#include "CPU6502.h"
#include "stdlib.h"
#include "stdio.h"
#include "fileIO.h"
#include "Opcodes.h"

// --- Static Definitions ---

// s_LDA_SET_STATUS : Sets CPU status based on values in registers on LDA
static void s_LDA_SET_STATUS(CPU C);

typedef struct cpu6502
{
    WORD PC; // Program Counter
    BYTE SP; // Stack Pointer

    BYTE A; // Accumulator Register
    BYTE X; // X Register
    BYTE Y; // Y Register

    BYTE PS; // Processor Status Flags

} * CPU;

CPU CPUNew()
{
    CPU C = (CPU)malloc(sizeof(struct cpu6502));

    if (C == NULL)
    {
        return NULL;
    }

    C->PC = 0;
    C->SP = 0;
    C->A = 0;
    C->X = 0;
    C->Y = 0;
    C->PS = 0;

    return C;
}

int CPUReset(CPU C, Memory m)
{
    if (C == NULL)
    {
        return 0;
    }

    // Reset Pointers
    C->PC = 0xFFFC;
    C->SP = 0x01;

    // Clear Registers
    C->A = 0;
    C->X = 0;
    C->Y = 0;

    // Clear all Flags for now
    for (int i = 0; i < 8; i++)
    {
        CPUSetStatusFlag(C, i, 0);
    }

    // Clear the memory
    MemoryReset(m);

    return 1;
}

BYTE CPUFetchByte(CPU C, Memory m, int *cycles)
{
    if (C == NULL || m == NULL)
    {
        return 0;
    }

    BYTE data = MemoryReadByte(m, C->PC, cycles);
    C->PC++;

    return data;
}

WORD CPUFetchWord(CPU C, Memory m, int *cycles)
{
    if (C == NULL || m == NULL)
    {
        return 0;
    }

    WORD data = MemoryReadWord(m, C->PC, cycles);
    C->PC += 2;
    return data;
}

int CPUSetStatusFlag(CPU C, int flagId, int flagValue)
{
    if (C == NULL || flagId < 0 || flagId > 7)
    {
        return 0;
    }

    if (flagValue)
    {
        C->PS |= 1 << flagId;
        return 1;
    }

    C->PS &= ~(1 << flagId);
    return 1;
}

int CPUGetStatusFlag(CPU C, int flagId)
{
    if (C == NULL || flagId < 0 || flagId > 7)
    {
        return -1;
    }

    BYTE status = C->PS;
    return (status >> flagId) & 0x01;
}

void CPUDump(CPU C)
{
    if (C == NULL)
    {
        return;
    }

    printf("\n --- START CPU DUMP --- \n");

    printf("\nPointers :\n");
    printf("\tPC : 0x%X\n", C->PC);
    printf("\tSP : 0x%X\n", C->SP);

    printf("\nRegisters :\n");
    printf("\tA : 0x%X\n", C->A);
    printf("\tX : 0x%X\n", C->X);
    printf("\tY : 0x%X\n", C->Y);

    printf("\nProcessor Status Flags :\n");
    printf("\tC : %d\n", CPUGetStatusFlag(C, PS_C));
    printf("\tZ : %d\n", CPUGetStatusFlag(C, PS_Z));
    printf("\tI : %d\n", CPUGetStatusFlag(C, PS_I));
    printf("\tD : %d\n", CPUGetStatusFlag(C, PS_D));
    printf("\tB : %d\n", CPUGetStatusFlag(C, PS_B));
    printf("\tV : %d\n", CPUGetStatusFlag(C, PS_V));
    printf("\tN : %d\n", CPUGetStatusFlag(C, PS_N));

    printf("\n --- END CPU DUMP --- \n");
}

WORD CPUGetPC(CPU C)
{
    if (C == NULL)
    {
        return 0;
    }

    return C->PC;
}

BYTE CPUGetSP(CPU C)
{
    if (C == NULL)
    {
        return 0;
    }

    return C->SP;
}

BYTE CPUGetA(CPU C)
{
    if (C == NULL)
    {
        return 0;
    }

    return C->A;
}

BYTE CPUGetX(CPU C)
{
    if (C == NULL)
    {
        return 0;
    }

    return C->X;
}

BYTE CPUGetY(CPU C)
{
    if (C == NULL)
    {
        return 0;
    }

    return C->Y;
}

void CPUSetPC(CPU C, WORD val)
{
    if (C == NULL)
    {
        return;
    }

    C->PC = val;
}

void CPUSetSP(CPU C, BYTE val)
{
    if (C == NULL)
    {
        return;
    }

    C->SP = val;
}

void CPUSetA(CPU C, BYTE val)
{
    if (C == NULL)
    {
        return;
    }

    C->A = val;
}

void CPUSetX(CPU C, BYTE val)
{
    if (C == NULL)
    {
        return;
    }

    C->X = val;
}

void CPUSetY(CPU C, BYTE val)
{
    if (C == NULL)
    {
        return;
    }

    C->Y = val;
}

int CPUFree(CPU C)
{
    if (C == NULL)
    {
        return 0;
    }

    free(C);

    return 1;
}

int CPUExecute(CPU C, Memory m, int cycles)
{

    if (C == NULL || m == NULL || cycles <= 0)
    {
        return 0;
    }

    while (cycles > 0)
    {
        BYTE instruction = CPUFetchByte(C, m, &cycles);

        switch (instruction)
        {
        case LDA_IM:

            BYTE value = CPUFetchByte(C, m, &cycles);

            CPUSetA(C, value);

            s_LDA_SET_STATUS(C);
            break;

        case LDA_ZP:

            BYTE ZPAddress = CPUFetchByte(C, m, &cycles);

            C->A = MemoryReadByte(m, ZPAddress, &cycles);
            cycles--;

            s_LDA_SET_STATUS(C);
            break;

        case LDA_ZPX:

            BYTE ZPAddressPx = CPUFetchByte(C, m, &cycles);

            ZPAddressPx = ZPAddressPx + C->X;
            cycles--;

            C->A = MemoryReadByte(m, ZPAddressPx, &cycles);
            cycles--;

            s_LDA_SET_STATUS(C);
            break;

        case JSR_AB:

            WORD SRAddress = CPUFetchWord(C, m, &cycles);
            C->PC--;

            MemoryWrite(m, C->SP, (C->PC >> 8) & 0x00FF);
            cycles--;

            C->SP--;
            MemoryWrite(m, C->SP, C->PC & 0x00FF);
            cycles--;

            C->PC = SRAddress;
            printf("%X\n", C->PC);
            cycles--;

            break;

        default:
            printf("ERROR : Unknown Instruction ( %X )\nDumping CPU to file...\n", instruction);
            FIODumpCPU(C, m);
            exit(EXIT_FAILURE);
            break;
        }
    }

    return 1;
}

// --- Static Helper Function Definitions ---

static void s_LDA_SET_STATUS(CPU C)
{
    CPUSetStatusFlag(C, PS_Z, (C->A == 0));
    CPUSetStatusFlag(C, PS_N, (C->A & 0b1000000) > 0);
}
