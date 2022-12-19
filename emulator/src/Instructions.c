#include "Instructions.h"
#include "AddressModes.h"
#include "Operations.h"

void INS_LDA_IM(CPU C, Memory m)
{
    BYTE value = CPUFetchByte(C, m);
    CPUSetA(C, value);
    STAT_Accumulator(C);
}

void INS_LDA_ZP(CPU C, Memory m)
{
    BYTE address = ADDR_ZP(C, m);
    OPER_LDA(C, m, address);
}

void INS_LDA_ZPX(CPU C, Memory m)
{
    BYTE address = ADDR_ZPX(C, m);
    OPER_LDA(C, m, address);
}

void INS_LDA_AB(CPU C, Memory m)
{
    WORD address = ADDR_AB(C, m);
    OPER_LDA(C, m, address);
}

void INS_LDA_ABX(CPU C, Memory m)
{
    WORD address = ADDR_ABX(C, m);
    OPER_LDA(C, m, address);
}

void INS_LDA_ABY(CPU C, Memory m)
{
    WORD address = ADDR_ABY(C, m);
    OPER_LDA(C, m, address);
}

void INS_LDA_INX(CPU C, Memory m)
{
    WORD address = ADDR_INX(C, m);
    OPER_LDA(C, m, address);
}

void INS_LDA_INY(CPU C, Memory m)
{
    WORD address = ADDR_INY(C, m);
    OPER_LDA(C, m, address);
}

void INS_LDX_IM(CPU C, Memory m)
{
    BYTE value = CPUFetchByte(C, m);
    CPUSetX(C, value);

    STAT_XRegister(C);
}

void INS_LDX_ZP(CPU C, Memory m)
{
    BYTE address = ADDR_ZP(C, m);
    OPER_LDX(C, m, address);
}

void INS_LDX_ZPY(CPU C, Memory m)
{
    BYTE address = ADDR_ZPY(C, m);
    OPER_LDX(C, m, address);
}

void INS_LDX_AB(CPU C, Memory m)
{
    WORD address = ADDR_AB(C, m);
    OPER_LDX(C, m, address);
}

void INS_LDX_ABY(CPU C, Memory m)
{
    WORD address = ADDR_ABY(C, m);
    OPER_LDX(C, m, address);
}

void INS_LDY_IM(CPU C, Memory m)
{
    BYTE value = CPUFetchByte(C, m);
    CPUSetY(C, value);

    STAT_YRegister(C);
}

void INS_LDY_ZP(CPU C, Memory m)
{
    BYTE address = ADDR_ZP(C, m);
    OPER_LDY(C, m, address);
}

void INS_LDY_ZPX(CPU C, Memory m)
{
    BYTE address = ADDR_ZPX(C, m);
    OPER_LDY(C, m, address);
}

void INS_LDY_AB(CPU C, Memory m)
{
    WORD address = ADDR_AB(C, m);
    OPER_LDY(C, m, address);
}

void INS_LDY_ABX(CPU C, Memory m)
{
    WORD address = ADDR_ABX(C, m);
    OPER_LDY(C, m, address);
}

void INS_STA_ZP(CPU C, Memory m)
{
    BYTE address = ADDR_ZP(C, m);
    OPER_STA(C, m, address);
}

void INS_STA_ZPX(CPU C, Memory m)
{
    BYTE address = ADDR_ZPX(C, m);
    OPER_STA(C, m, address);
}

void INS_STA_AB(CPU C, Memory m)
{
    WORD address = ADDR_AB(C, m);
    OPER_STA(C, m, address);
}

void INS_STA_ABX(CPU C, Memory m)
{
    WORD address = ADDR_ABX(C, m);
    OPER_STA(C, m, address);
}

void INS_STA_ABY(CPU C, Memory m)
{
    WORD address = ADDR_ABY(C, m);
    OPER_STA(C, m, address);
}

void INS_STA_INX(CPU C, Memory m)
{
    WORD address = ADDR_INX(C, m);
    OPER_STA(C, m, address);
}

void INS_STA_INY(CPU C, Memory m)
{
    WORD address = ADDR_INY(C, m);
    OPER_STA(C, m, address);
}

void INS_STX_ZP(CPU C, Memory m)
{
    BYTE address = ADDR_ZP(C, m);
    OPER_STX(C, m, address);
}

void INS_STX_ZPY(CPU C, Memory m)
{
    BYTE address = ADDR_ZPY(C, m);
    OPER_STX(C, m, address);
}

void INS_STX_AB(CPU C, Memory m)
{
    WORD address = ADDR_AB(C, m);
    OPER_STX(C, m, address);
}

void INS_STY_ZP(CPU C, Memory m)
{
    BYTE address = ADDR_ZP(C, m);
    OPER_STY(C, m, address);
}

void INS_STY_ZPX(CPU C, Memory m)
{
    BYTE address = ADDR_ZPX(C, m);
    OPER_STY(C, m, address);
}

void INS_STY_AB(CPU C, Memory m)
{
    WORD address = ADDR_AB(C, m);
    OPER_STY(C, m, address);
}

void INS_TAX_IMP(CPU C, Memory m)
{
    BYTE Avalue = CPUGetA(C);
    CPUSetX(C, Avalue);
    ClockTick(CPUGetClock(C));

    STAT_XRegister(C);
}

void INS_TAY_IMP(CPU C, Memory m)
{
    BYTE Avalue = CPUGetA(C);
    CPUSetY(C, Avalue);
    ClockTick(CPUGetClock(C));

    STAT_YRegister(C);
}

void INS_TXA_IMP(CPU C, Memory m)
{
    BYTE Xvalue = CPUGetX(C);
    CPUSetA(C, Xvalue);
    ClockTick(CPUGetClock(C));

    STAT_Accumulator(C);
}

void INS_TYA_IMP(CPU C, Memory m)
{
    BYTE Yvalue = CPUGetY(C);
    CPUSetA(C, Yvalue);
    ClockTick(CPUGetClock(C));

    STAT_Accumulator(C);
}

void INS_TSX_IMP(CPU C, Memory m)
{
    BYTE stackPointer = CPUGetSP(C);
    CPUSetX(C, stackPointer);
    ClockTick(CPUGetClock(C));

    STAT_XRegister(C);
}

void INS_TXS_IMP(CPU C, Memory m)
{
    BYTE Xvalue = CPUGetX(C);
    CPUSetSP(C, Xvalue);
    ClockTick(CPUGetClock(C));
}

void INS_PHA_IMP(CPU C, Memory m)
{
    BYTE Avalue = CPUGetA(C);

    MemoryWriteToStack(m, CPUGetSP(C), (Avalue >> 8) & 0x00FF);
    CPUIncrementSP(C, -1);
    ClockTick(CPUGetClock(C));

    MemoryWriteToStack(m, CPUGetSP(C), Avalue & 0x00FF);
    CPUIncrementSP(C, -1);
    ClockTick(CPUGetClock(C));
}

void INS_PHP_IMP(CPU C, Memory m)
{
    BYTE statusRegister = CPUGetStatusRegister(C);

    MemoryWriteToStack(m, CPUGetSP(C), (statusRegister >> 8) & 0x00FF);
    CPUIncrementSP(C, -1);
    ClockTick(CPUGetClock(C));

    MemoryWriteToStack(m, CPUGetSP(C), (statusRegister & 0x00FF));
    CPUIncrementSP(C, -1);
    ClockTick(CPUGetClock(C));
}

void INS_PLA_IMP(CPU C, Memory m)
{
    CPUIncrementSP(C, 1);
    ClockTick(CPUGetClock(C));

    BYTE stackValue = MemoryReadFromStack(m, CPUGetSP(C), CPUGetClock(C));

    CPUSetA(C, stackValue);

    STAT_Accumulator(C);
    ClockTick(CPUGetClock(C));
}

void INS_PLP_IMP(CPU C, Memory m)
{
    CPUIncrementSP(C, 1);
    ClockTick(CPUGetClock(C));

    BYTE stackValue = MemoryReadFromStack(m, CPUGetSP(C), CPUGetClock(C));

    CPUSetStatusRegister(C, stackValue);
    ClockTick(CPUGetClock(C));
}

void INS_AND_IM(CPU C, Memory m)
{
    BYTE value = CPUFetchByte(C, m);
    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, Avalue & value);

    STAT_Accumulator(C);
}

void INS_AND_ZP(CPU C, Memory m)
{
    BYTE address = ADDR_ZP(C, m);
    OPER_AND(C, m, address);
}

void INS_AND_ZPX(CPU C, Memory m)
{
    BYTE address = ADDR_ZPX(C, m);
    OPER_AND(C, m, address);
}

void INS_AND_AB(CPU C, Memory m)
{
    WORD address = ADDR_AB(C, m);
    OPER_AND(C, m, address);
}

void INS_AND_ABX(CPU C, Memory m)
{
    WORD address = ADDR_ABX(C, m);
    OPER_AND(C, m, address);
}

void INS_AND_ABY(CPU C, Memory m)
{
    WORD address = ADDR_ABY(C, m);
    OPER_AND(C, m, address);
}

void INS_AND_INX(CPU C, Memory m)
{
    WORD address = ADDR_INX(C, m);
    OPER_AND(C, m, address);
}

void INS_AND_INY(CPU C, Memory m)
{
    WORD address = ADDR_INY(C, m);
    OPER_AND(C, m, address);
}

void INS_EOR_IM(CPU C, Memory m)
{
    BYTE value = CPUFetchByte(C, m);
    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, Avalue ^ value);
    STAT_Accumulator(C);
}

void INS_EOR_ZP(CPU C, Memory m)
{
    BYTE address = ADDR_ZP(C, m);
    OPER_EOR(C, m, address);
}

void INS_EOR_ZPX(CPU C, Memory m)
{
    BYTE address = ADDR_ZPX(C, m);
    OPER_EOR(C, m, address);
}

void INS_EOR_AB(CPU C, Memory m)
{
    WORD address = ADDR_AB(C, m);
    OPER_EOR(C, m, address);
}

void INS_EOR_ABX(CPU C, Memory m)
{
    WORD address = ADDR_ABX(C, m);
    OPER_EOR(C, m, address);
}

void INS_EOR_ABY(CPU C, Memory m)
{
    WORD address = ADDR_ABY(C, m);
    OPER_EOR(C, m, address);
}

void INS_EOR_INX(CPU C, Memory m)
{
    WORD address = ADDR_INX(C, m);
    OPER_EOR(C, m, address);
}

void INS_EOR_INY(CPU C, Memory m)
{
    WORD address = ADDR_INY(C, m);
    OPER_EOR(C, m, address);
}

void INS_ORA_IM(CPU C, Memory m)
{
    BYTE value = CPUFetchByte(C, m);
    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, Avalue | value);
    STAT_Accumulator(C);
}

void INS_ORA_ZP(CPU C, Memory m)
{
    BYTE address = ADDR_ZP(C, m);
    OPER_ORA(C, m, address);
}

void INS_ORA_ZPX(CPU C, Memory m)
{
    BYTE address = ADDR_ZPX(C, m);
    OPER_ORA(C, m, address);
}

void INS_ORA_AB(CPU C, Memory m)
{
    WORD address = ADDR_AB(C, m);
    OPER_ORA(C, m, address);
}

void INS_ORA_ABX(CPU C, Memory m)
{
    WORD address = ADDR_ABX(C, m);
    OPER_ORA(C, m, address);
}

void INS_ORA_ABY(CPU C, Memory m)
{
    WORD address = ADDR_ABY(C, m);
    OPER_ORA(C, m, address);
}

void INS_ORA_INX(CPU C, Memory m)
{
    WORD address = ADDR_INX(C, m);
    OPER_ORA(C, m, address);
}

void INS_ORA_INY(CPU C, Memory m)
{
    WORD address = ADDR_INY(C, m);
    OPER_ORA(C, m, address);
}

void INS_BIT_ZP(CPU C, Memory m)
{
    BYTE address = ADDR_ZP(C, m);
    OPER_BIT(C, m, address);
}

void INS_BIT_AB(CPU C, Memory m)
{
    WORD address = ADDR_AB(C, m);
    OPER_BIT(C, m, address);
}

void INS_ADC_IM(CPU C, Memory m)
{
    BYTE value = CPUFetchByte(C, m);

    // Perform 16 bit addition (Unlike hardware) => simplify logic

    // Add Accumulator with value, also add the Carry Status flag
    WORD accu = (WORD)CPUGetA(C);
    WORD sum = accu + (WORD)value + CPUGetStatusFlag(C, PS_C);

    // Load first 8 bits of sum into accumulator
    CPUSetA(C, (BYTE)(sum & 0x00FF));

    // Set flags (Uses previous accumulator value)
    STAT_ADC(C, accu, value, sum);
}

void INS_ADC_ZP(CPU C, Memory m)
{
    BYTE address = ADDR_ZP(C, m);
    OPER_ADC(C, m, address);
}

void INS_ADC_ZPX(CPU C, Memory m)
{
    BYTE address = ADDR_ZPX(C, m);
    OPER_ADC(C, m, address);
}

void INS_ADC_AB(CPU C, Memory m)
{
    WORD address = ADDR_AB(C, m);
    OPER_ADC(C, m, address);
}

void INS_ADC_ABX(CPU C, Memory m)
{
    WORD address = ADDR_ABX(C, m);
    OPER_ADC(C, m, address);
}

void INS_ADC_ABY(CPU C, Memory m)
{
    WORD address = ADDR_ABY(C, m);
    OPER_ADC(C, m, address);
}

void INS_ADC_INX(CPU C, Memory m)
{
    WORD address = ADDR_INX(C, m);
    OPER_ADC(C, m, address);
}

void INS_ADC_INY(CPU C, Memory m)
{
    WORD address = ADDR_INY(C, m);
    OPER_ADC(C, m, address);
}

void INS_JSR_AB(CPU C, Memory m)
{
    WORD address = ADDR_AB(C, m);
    CPUIncrementPC(C, -1);
    WORD pc = CPUGetPC(C);

    MemoryWrite(m, CPUGetSP(C), (pc >> 8) & 0x00FF);
    ClockTick(CPUGetClock(C));

    CPUIncrementSP(C, -1);

    MemoryWrite(m, CPUGetSP(C), pc & 0x00FF);
    ClockTick(CPUGetClock(C));
    CPUSetPC(C, address);

    ClockTick(CPUGetClock(C));
}
