#include "CPU6502.h"
#include "stdlib.h"
#include "stdio.h"

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

BYTE CPUFetch(CPU C, Memory m)
{
    if (C == NULL || m == NULL)
    {
        return 0;
    }

    BYTE data = MemoryRead(m, C->PC);
    C->PC++;

    return data;
}

int CPUExecute(CPU C, Memory m, int cycles)
{

    if (C == NULL || m == NULL || cycles <= 0)
    {
        return 0;
    }

    while (cycles > 0)
    {
        BYTE instruction = CPUFetch(C, m);
        cycles--;

        switch (instruction)
        {
        case LDA_IM:

            BYTE value = CPUFetch(C, m);
            cycles--;

            C->A = value;

            CPUSetStatusFlag(C, PS_Z, (C->A == 0));
            CPUSetStatusFlag(C, PS_N, (C->A & 0b1000000) > 0);

            break;

        default:
            printf("\nInstruction ( 0x%X ) not implemented\n", instruction);
            exit(EXIT_FAILURE);
            break;
        }
    }

    return 1;
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

int CPUFree(CPU C)
{
    if (C == NULL)
    {
        return 0;
    }

    free(C);

    return 1;
}