#include "CPU6502.h"
#include "stdlib.h"
#include "stdio.h"
#include "fileIO.h"
#include "Opcodes.h"
#include "Instructions.h"
#include "Clock.h"

// --- Static Helper Functions ---

// setupFunctionPointers : Instantiates function pointer array for opcodes
static void setupFunctionPointers(CPU c);

typedef struct cpu6502
{
    // === Internals ===

    WORD PC; // Program Counter
    BYTE SP; // Stack Pointer

    BYTE A; // Accumulator Register
    BYTE X; // X Register
    BYTE Y; // Y Register

    BYTE PS; // Processor Status Flags

    Clock clk; // CPU Clock (Internal to CPU unlike in real hardware)

    cpuOperation *ops; // Array of function pointers for CPU operations

    // === Outputs ===

    // === Software Mode ===
    Memory SW_MEMORY;

    // === Hardware Mode ===
    BYTE HW_DATA_BUS; // 8-Bit Data bus IO Pins
    WORD HW_ADDR_BUS; // 16-Bit Address bus IO Pins
    int HW_BUS_MODE;  // Indicates CPU Mode on bus (Read or Write)

} *CPU;

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

    C->ops = (cpuOperation *)calloc(0xFF, sizeof(cpuOperation));
    setupFunctionPointers(C);

    C->clk = ClockNew();

    if (C->clk == NULL)
    {
        free(C->ops);
        free(C);
        return NULL;
    }

    ClockSetSpeed(C->clk, CPU_6502_DEFAULT_CLOCK_SPEED);
    return C;
}

int CPUReset(CPU C)
{
    if (C == NULL)
    {
        return 0;
    }

    // Reset Pointers
    C->PC = 0xFFFC;
    C->SP = 0xFF;

    // Clear Registers
    C->A = 0;
    C->X = 0;
    C->Y = 0;

    // Clear all Flags for now
    for (int i = 0; i < 8; i++)
    {
        CPUSetStatusFlag(C, i, 0);
    }

    return 1;
}

BYTE CPUFetchByte(CPU C, Memory m)
{
    if (C == NULL || m == NULL)
    {
        return 0;
    }

    BYTE data = MemoryReadByte(m, C->PC, C->clk);
    C->PC++;

    return data;
}

WORD CPUFetchWord(CPU C, Memory m)
{
    if (C == NULL || m == NULL)
    {
        return 0;
    }

    WORD data = MemoryReadWord(m, C->PC, C->clk);
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

BYTE CPUGetStatusRegister(CPU C)
{
    if (C == NULL)
    {
        return 0;
    }

    return C->PS;
}

int CPUSetStatusRegister(CPU C, BYTE val)
{
    if (C == NULL)
    {
        return 0;
    }

    C->PS = val;
    return 1;
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

    ClockFree(C->clk);
    free(C->ops);
    free(C);

    return 1;
}

Clock CPUGetClock(CPU C)
{
    if (C == NULL)
    {
        return NULL;
    }

    return C->clk;
}

int CPUExecute(CPU C, Memory m)
{

    if (C == NULL || m == NULL)
    {
        return 0;
    }

    int clkMode = ClockGetMode(CPUGetClock(C));
    int tickForever = (clkMode == CM_FREQ_NO_LIMIT || clkMode == CM_STEP_NO_LIMIT);

    while (tickForever || ClockGetCount(C->clk))
    {
        BYTE instruction = CPUFetchByte(C, m);

        cpuOperation func = C->ops[instruction];

        if (!func)
        {
            return 0;
        }

        func(C, m);
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

    // STA
    c->ops[STA_ZP] = &INS_STA_ZP;
    c->ops[STA_ZPX] = &INS_STA_ZPX;
    c->ops[STA_AB] = &INS_STA_AB;
    c->ops[STA_ABX] = &INS_STA_ABX;
    c->ops[STA_ABY] = &INS_STA_ABY;
    c->ops[STA_INX] = &INS_STA_INX;
    c->ops[STA_INY] = &INS_STA_INY;

    // STX
    c->ops[STX_ZP] = &INS_STX_ZP;
    c->ops[STX_ZPY] = &INS_STX_ZPY;
    c->ops[STX_AB] = &INS_STX_AB;

    // STY
    c->ops[STY_ZP] = &INS_STY_ZP;
    c->ops[STY_ZPX] = &INS_STY_ZPX;
    c->ops[STY_AB] = &INS_STY_AB;

    // TAX
    c->ops[TAX_IMP] = &INS_TAX_IMP;

    // TAY
    c->ops[TAY_IMP] = &INS_TAY_IMP;

    // TXA
    c->ops[TXA_IMP] = &INS_TXA_IMP;

    // TYA
    c->ops[TYA_IMP] = &INS_TYA_IMP;

    // TSX
    c->ops[TSX_IMP] = &INS_TSX_IMP;

    // TXS
    c->ops[TXS_IMP] = &INS_TXS_IMP;

    // PHA
    c->ops[PHA_IMP] = &INS_PHA_IMP;

    // PHP
    c->ops[PHP_IMP] = &INS_PHP_IMP;

    // PLA
    c->ops[PLA_IMP] = &INS_PLA_IMP;

    // PLP
    c->ops[PLP_IMP] = &INS_PLP_IMP;

    // AND
    c->ops[AND_IM] = &INS_AND_IM;
    c->ops[AND_ZP] = &INS_AND_ZP;
    c->ops[AND_ZPX] = &INS_AND_ZPX;
    c->ops[AND_AB] = &INS_AND_AB;
    c->ops[AND_ABX] = &INS_AND_ABX;
    c->ops[AND_ABY] = &INS_AND_ABY;
    c->ops[AND_INX] = &INS_AND_INX;
    c->ops[AND_INY] = &INS_AND_INY;

    // EOR
    c->ops[EOR_IM] = &INS_EOR_IM;
    c->ops[EOR_ZP] = &INS_EOR_ZP;
    c->ops[EOR_ZPX] = &INS_EOR_ZPX;
    c->ops[EOR_AB] = &INS_EOR_AB;
    c->ops[EOR_ABX] = &INS_EOR_ABX;
    c->ops[EOR_ABY] = &INS_EOR_ABY;
    c->ops[EOR_INX] = &INS_EOR_INX;
    c->ops[EOR_INY] = &INS_EOR_INY;

    // ORA
    c->ops[ORA_IM] = &INS_ORA_IM;
    c->ops[ORA_ZP] = &INS_ORA_ZP;
    c->ops[ORA_ZPX] = &INS_ORA_ZPX;
    c->ops[ORA_AB] = &INS_ORA_AB;
    c->ops[ORA_ABX] = &INS_ORA_ABX;
    c->ops[ORA_ABY] = &INS_ORA_ABY;
    c->ops[ORA_INX] = &INS_ORA_INX;
    c->ops[ORA_INY] = &INS_ORA_INY;

    // BIT
    c->ops[BIT_ZP] = &INS_BIT_ZP;
    c->ops[BIT_AB] = &INS_BIT_AB;

    // ADC
    c->ops[ADC_IM] = &INS_ADC_IM;
    c->ops[ADC_ZP] = &INS_ADC_ZP;
    c->ops[ADC_ZPX] = &INS_ADC_ZPX;
    c->ops[ADC_AB] = &INS_ADC_AB;
    c->ops[ADC_ABX] = &INS_ADC_ABX;
    c->ops[ADC_ABY] = &INS_ADC_ABY;
    c->ops[ADC_INX] = &INS_ADC_INX;
    c->ops[ADC_INY] = &INS_ADC_INY;

    // JSR
    c->ops[JSR_AB] = &INS_JSR_AB;
}
