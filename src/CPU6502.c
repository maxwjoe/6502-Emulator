#include "CPU6502.h"
#include "stdlib.h"
#include "stdio.h"
#include "fileIO.h"
#include "Opcodes.h"
#include "Instructions.h"

// --- Static Helper Functions ---

// setupFunctionPointers : Instantiates function pointer array for opcodes
static void setupFunctionPointers(CPU c);

typedef struct cpu6502
{
    WORD PC; // Program Counter
    BYTE SP; // Stack Pointer

    BYTE A; // Accumulator Register
    BYTE X; // X Register
    BYTE Y; // Y Register

    BYTE PS; // Processor Status Flags

    cpuOperation *ops; // Array of function pointers for CPU operations

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

    C->ops = calloc(0xFF, sizeof(cpuOperation));
    setupFunctionPointers(C);

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

void CPUIncrementSP(CPU C, BYTE val)
{
    if (C == NULL)
    {
        return;
    }

    C->SP += val;
}

void CPUIncrementPC(CPU C, BYTE val)
{
    if (C == NULL)
    {
        return;
    }

    C->PC += val;
}

int CPUFree(CPU C)
{
    if (C == NULL)
    {
        return 0;
    }

    free(C->ops);
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

        cpuOperation func = C->ops[instruction];

        if (!func)
        {
            printf("ERROR : Unknown CPU Instruction [ 0x%02X ]\n", instruction);
            exit(EXIT_FAILURE);
        }

        func(C, m, &cycles);
    }

    return 1;
}

static void setupFunctionPointers(CPU c)
{
    if (c == NULL)
    {
        return;
    }

    // LDA
    c->ops[LDA_IM] = &INS_LDA_IM;
    c->ops[LDA_ZP] = &INS_LDA_ZP;
    c->ops[LDA_ZPX] = &INS_LDA_ZPX;
    c->ops[LDA_AB] = &INS_LDA_AB;
    c->ops[LDA_ABX] = &INS_LDA_ABX;
    c->ops[LDA_ABY] = &INS_LDA_ABY;
    c->ops[LDA_INX] = &INS_LDA_INX;
    c->ops[LDA_INY] = &INS_LDA_INY;

    // LDX
    c->ops[LDX_IM] = &INS_LDX_IM;
    c->ops[LDX_ZP] = &INS_LDX_ZP;
    c->ops[LDX_ZPY] = &INS_LDX_ZPY;
    c->ops[LDX_AB] = &INS_LDX_AB;
    c->ops[LDX_ABY] = &INS_LDX_ABY;

    // LDY
    c->ops[LDY_IM] = &INS_LDY_IM;
    c->ops[LDY_ZP] = &INS_LDY_ZP;
    c->ops[LDY_ZPX] = &INS_LDY_ZPX;
    c->ops[LDY_AB] = &INS_LDY_AB;
    c->ops[LDY_ABX] = &INS_LDY_ABX;

    // JSR
    c->ops[JSR_AB] = &INS_JSR_AB;
}
