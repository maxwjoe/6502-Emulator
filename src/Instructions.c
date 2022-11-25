#include "Instructions.h"

// incrementCycles : Helper function to increment the cycles in instructions
static void incrementCycles(int *cycles, int amount)
{
    *cycles = *cycles + amount;
}

void LDA_SET_STATUS(CPU C)
{
    BYTE A = CPUGetA(C);
    CPUSetStatusFlag(C, PS_Z, (A == 0));
    CPUSetStatusFlag(C, PS_N, (A & 0b1000000) > 0);
}

void LDX_SET_STATUS(CPU C)
{
    BYTE X = CPUGetX(C);
    CPUSetStatusFlag(C, PS_Z, (X == 0));
    CPUSetStatusFlag(C, PS_N, (X & 0b1000000) > 0);
}

void LDY_SET_STATUS(CPU C)
{
    BYTE Y = CPUGetY(C);
    CPUSetStatusFlag(C, PS_Z, (Y == 0));
    CPUSetStatusFlag(C, PS_N, (Y & 0b1000000) > 0);
}

void INS_LDA_IM(CPU C, Memory m, int *cyclesPtr)
{
    BYTE value = CPUFetchByte(C, m, cyclesPtr);
    CPUSetA(C, value);
    LDA_SET_STATUS(C);
}

void INS_LDA_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);

    BYTE A = MemoryReadByte(m, ZPAddress, cyclesPtr);
    CPUSetA(C, A);

    incrementCycles(cyclesPtr, -1);

    LDA_SET_STATUS(C);
}

void INS_LDA_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddressPx = CPUFetchByte(C, m, cyclesPtr);

    ZPAddressPx = ZPAddressPx + CPUGetX(C);
    incrementCycles(cyclesPtr, -1);

    BYTE A = MemoryReadByte(m, ZPAddressPx, cyclesPtr);
    CPUSetA(C, A);
    incrementCycles(cyclesPtr, -1);

    LDA_SET_STATUS(C);
}

void INS_LDA_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    BYTE A = MemoryReadByte(m, address, cyclesPtr);
    CPUSetA(C, A);

    LDA_SET_STATUS(C);
}

void INS_LDX_IM(CPU C, Memory m, int *cyclesPtr)
{
    BYTE value = CPUFetchByte(C, m, cyclesPtr);
    CPUSetX(C, value);

    LDX_SET_STATUS(C);
}

void INS_LDY_IM(CPU C, Memory m, int *cyclesPtr)
{
    BYTE value = CPUFetchByte(C, m, cyclesPtr);
    CPUSetY(C, value);

    LDY_SET_STATUS(C);
}

void INS_JSR_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD SRAddress = CPUFetchWord(C, m, cyclesPtr);
    CPUIncrementPC(C, -1);
    WORD pc = CPUGetPC(C);

    MemoryWrite(m, CPUGetSP(C), (pc >> 8) & 0x00FF);
    incrementCycles(cyclesPtr, -1);

    CPUIncrementSP(C, -1);

    MemoryWrite(m, CPUGetSP(C), pc & 0x00FF);
    incrementCycles(cyclesPtr, -1);
    CPUSetPC(C, SRAddress);

    incrementCycles(cyclesPtr, -1);
}
