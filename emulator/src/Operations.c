#include "Operations.h"

void OPER_LDA(CPU C, WORD address)
{
    BYTE value = CPUReadByte(C, address);
    CPUSetA(C, value);
    STAT_Accumulator(C);
}

void OPER_LDX(CPU C, WORD address)
{
    BYTE value = CPUReadByte(C, address);
    CPUSetX(C, value);
    STAT_XRegister(C);
}

void OPER_LDY(CPU C, WORD address)
{
    BYTE value = CPUReadByte(C, address);
    CPUSetY(C, value);
    STAT_YRegister(C);
}

void OPER_STA(CPU C, WORD address)
{
    BYTE value = CPUGetA(C);
    CPUWriteByte(C, address, value);
    ClockTick(CPUGetClock(C));
}

void OPER_STX(CPU C, WORD address)
{
    BYTE value = CPUGetX(C);
    CPUWriteByte(C, address, value);

    ClockTick(CPUGetClock(C));
}

void OPER_STY(CPU C, WORD address)
{
    BYTE value = CPUGetY(C);
    CPUWriteByte(C, address, value);

    ClockTick(CPUGetClock(C));
}

void OPER_AND(CPU C, WORD address)
{
    BYTE value = CPUReadByte(C, address);

    BYTE Avalue = CPUGetA(C);
    CPUSetA(C, Avalue & value);

    STAT_Accumulator(C);
}

void OPER_EOR(CPU C, WORD address)
{
    BYTE value = CPUReadByte(C, address);
    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, value ^ Avalue);
    STAT_Accumulator(C);
}

void OPER_ORA(CPU C, WORD address)
{
    BYTE value = CPUReadByte(C, address);
    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, value | Avalue);
    STAT_Accumulator(C);
}

void OPER_BIT(CPU C, WORD address)
{
    BYTE value = CPUReadByte(C, address);
    BYTE Avalue = CPUGetA(C);

    CPUSetStatusFlag(C, PS_Z, (Avalue & value));
    CPUSetStatusFlag(C, PS_V, (value >> 1) & 1);
    CPUSetStatusFlag(C, PS_N, value & 1);
}

void OPER_ADC(CPU C, WORD address)
{
    BYTE value = CPUReadByte(C, address);

    // Perform 16 bit addition (Unlike hardware) => simplify logic

    // Add Accumulator with value, also add the Carry Status flag
    WORD accu = (WORD)CPUGetA(C);
    WORD sum = accu + (WORD)value + CPUGetStatusFlag(C, PS_C);

    // Load first 8 bits of sum into accumulator
    CPUSetA(C, (BYTE)(sum & 0x00FF));

    // Set flags (Uses previous accumulator value)
    STAT_ADC(C, accu, value, sum);
}

void OPER_SBC(CPU C, WORD address)
{
    WORD value = CPUReadByte(C, address);

    // Like ADC, Perform operations in 16 bit to simplify logic

    // NOTE : Negating signed 8 bit Number -> 2's Complement (Invert all bits + 1)
    value ^= 0x00FF;

    // Perform addition
    WORD accu = (WORD)CPUGetA(C);
    WORD sum = accu + value + CPUGetStatusFlag(C, PS_C);

    // TODO: Extract into function
    CPUSetStatusFlag(C, PS_C, sum & 0xFF00);
    CPUSetStatusFlag(C, PS_Z, sum & 0x00FF == 0);
    CPUSetStatusFlag(C, PS_V, (sum ^ accu) & (sum ^ value) & 0x0080);
    CPUSetStatusFlag(C, PS_N, sum & 0x0080);

    CPUSetA(C, sum & 0x00FF);

    // Same operation as addition
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

void STAT_ADC(CPU C, WORD accumulator, WORD valueToAdd, WORD sum)
{
    // ASSUMPTION : This function is called using the accumulator value before addition operation

    // Set the carry flag (If outside of 8 Bit Limit)
    CPUSetStatusFlag(C, PS_C, (sum > 0xFF));

    // Set Zero Flag (If lowest 8 bits are zero)
    CPUSetStatusFlag(C, PS_Z, !(sum & 0x00FF));

    // Set signed overflow flag
    // 0x0080 : Mask for the most significant bit (8 bits)
    // Let A be MSB Accumulator, M be MSB valueToAdd and R be the MSB result
    // Constructing a truth table and reducing to a boolean expression
    // | A | M | R | Output = V |
    // Output Rule : ~(A^M) & (A^R)

    int hasOverflown = (~(accumulator ^ valueToAdd) & (accumulator ^ sum)) & 0x0080;

    CPUSetStatusFlag(C, PS_V, hasOverflown);

    // Set Negative Flag (Most significant bit of 8 bit sum)
    CPUSetStatusFlag(C, PS_N, (sum & 0x0080));
}
