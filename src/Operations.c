#include "Operations.h"

void OPER_LDA(CPU C, Memory m, int *cyclesPtr, WORD address)
{
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    CPUSetA(C, value);
    STAT_Accumulator(C);
}

void OPER_LDX(CPU C, Memory m, int *cyclesPtr, WORD address)
{
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    CPUSetX(C, value);
    STAT_XRegister(C);
}

void OPER_LDY(CPU C, Memory m, int *cyclesPtr, WORD address)
{
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    CPUSetY(C, value);
    STAT_YRegister(C);
}

void OPER_STA(CPU C, Memory m, int *cyclesPtr, WORD address)
{
    BYTE value = CPUGetA(C);
    MemoryWrite(m, address, value);
    *cyclesPtr = *cyclesPtr - 1;
}

void OPER_STX(CPU C, Memory m, int *cyclesPtr, WORD address)
{
    BYTE value = CPUGetX(C);
    MemoryWrite(m, address, value);
    *cyclesPtr = *cyclesPtr - 1;
}

void OPER_STY(CPU C, Memory m, int *cyclesPtr, WORD address)
{
    BYTE value = CPUGetY(C);
    MemoryWrite(m, address, value);
    *cyclesPtr = *cyclesPtr - 1;
}

void OPER_AND(CPU C, Memory m, int *cyclesPtr, WORD address)
{
    BYTE value = MemoryReadByte(m, address, cyclesPtr);

    BYTE Avalue = CPUGetA(C);
    CPUSetA(C, Avalue & value);

    STAT_Accumulator(C);
}

void OPER_EOR(CPU C, Memory m, int *cyclesPtr, WORD address)
{
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, value ^ Avalue);
    STAT_Accumulator(C);
}

void OPER_ORA(CPU C, Memory m, int *cyclesPtr, WORD address)
{
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, value | Avalue);
    STAT_Accumulator(C);
}

void OPER_BIT(CPU C, Memory m, int *cyclesPtr, WORD address)
{
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    BYTE Avalue = CPUGetA(C);

    CPUSetStatusFlag(C, PS_Z, (Avalue & value));
    CPUSetStatusFlag(C, PS_V, (value >> 1) & 1);
    CPUSetStatusFlag(C, PS_N, value & 1);
}

void STAT_Accumulator(CPU C)
{
    BYTE A = CPUGetA(C);
    CPUSetStatusFlag(C, PS_Z, (A == 0));
    CPUSetStatusFlag(C, PS_N, (A & 0b10000000) > 0);
}

void STAT_XRegister(CPU C)
{
    BYTE X = CPUGetX(C);
    CPUSetStatusFlag(C, PS_Z, (X == 0));
    CPUSetStatusFlag(C, PS_N, (X & 0b10000000) > 0);
}

void STAT_YRegister(CPU C)
{
    BYTE Y = CPUGetY(C);
    CPUSetStatusFlag(C, PS_Z, (Y == 0));
    CPUSetStatusFlag(C, PS_N, (Y & 0b10000000) > 0);
}