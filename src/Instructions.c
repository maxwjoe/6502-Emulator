#include "Instructions.h"
#include "AddressModes.h"
#include "Operations.h"

// incrementCycles : Helper function to increment the cycles in instructions
static void incrementCycles(int *cycles, int amount)
{
    *cycles = *cycles + amount;
}

void ACC_SET_STATUS(CPU C)
{
    BYTE A = CPUGetA(C);
    CPUSetStatusFlag(C, PS_Z, (A == 0));
    CPUSetStatusFlag(C, PS_N, (A & 0b10000000) > 0);
}

void XREG_SET_STATUS(CPU C)
{
    BYTE X = CPUGetX(C);
    CPUSetStatusFlag(C, PS_Z, (X == 0));
    CPUSetStatusFlag(C, PS_N, (X & 0b10000000) > 0);
}

void YREG_SET_STATUS(CPU C)
{
    BYTE Y = CPUGetY(C);
    CPUSetStatusFlag(C, PS_Z, (Y == 0));
    CPUSetStatusFlag(C, PS_N, (Y & 0b10000000) > 0);
}

void INS_LDA_IM(CPU C, Memory m, int *cyclesPtr)
{
    BYTE value = CPUFetchByte(C, m, cyclesPtr);
    CPUSetA(C, value);
    ACC_SET_STATUS(C);
}

void INS_LDA_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    OPER_LDA(C, m, cyclesPtr, address);
}

void INS_LDA_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPX(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);

    CPUSetA(C, value);
    incrementCycles(cyclesPtr, -1);

    ACC_SET_STATUS(C);
}

void INS_LDA_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    CPUSetA(C, value);

    ACC_SET_STATUS(C);
}

void INS_LDA_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABX(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    CPUSetA(C, value);

    ACC_SET_STATUS(C);
}

void INS_LDA_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABY(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    CPUSetA(C, value);

    ACC_SET_STATUS(C);
}

void INS_LDA_INX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INX(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);

    CPUSetA(C, value);
    ACC_SET_STATUS(C);
}

void INS_LDA_INY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INY(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);

    CPUSetA(C, value);
    ACC_SET_STATUS(C);
}

void INS_LDX_IM(CPU C, Memory m, int *cyclesPtr)
{
    BYTE value = CPUFetchByte(C, m, cyclesPtr);
    CPUSetX(C, value);

    XREG_SET_STATUS(C);
}

void INS_LDX_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    CPUSetX(C, value);

    incrementCycles(cyclesPtr, -1);
    XREG_SET_STATUS(C);
}

void INS_LDX_ZPY(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPY(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    CPUSetX(C, value);

    incrementCycles(cyclesPtr, -1);
    XREG_SET_STATUS(C);
}

void INS_LDX_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    CPUSetX(C, value);

    XREG_SET_STATUS(C);
}

void INS_LDX_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABY(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    CPUSetX(C, value);

    XREG_SET_STATUS(C);
}

void INS_LDY_IM(CPU C, Memory m, int *cyclesPtr)
{
    BYTE value = CPUFetchByte(C, m, cyclesPtr);
    CPUSetY(C, value);

    YREG_SET_STATUS(C);
}

void INS_LDY_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);

    CPUSetY(C, value);
    YREG_SET_STATUS(C);
}

void INS_LDY_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPX(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);

    CPUSetY(C, value);
    YREG_SET_STATUS(C);
}

void INS_LDY_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    CPUSetY(C, value);

    YREG_SET_STATUS(C);
}

void INS_LDY_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABX(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    CPUSetY(C, value);

    YREG_SET_STATUS(C);
}

void INS_STA_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    BYTE value = CPUGetA(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_STA_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPX(C, m, cyclesPtr);
    BYTE value = CPUGetA(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_STA_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    BYTE value = CPUGetA(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_STA_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABX(C, m, cyclesPtr);
    BYTE value = CPUGetA(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_STA_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABY(C, m, cyclesPtr);
    BYTE value = CPUGetA(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_STA_INX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INX(C, m, cyclesPtr);
    BYTE value = CPUGetA(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_STA_INY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INY(C, m, cyclesPtr);
    BYTE value = CPUGetA(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_STX_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    BYTE value = CPUGetX(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_STX_ZPY(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPY(C, m, cyclesPtr);
    BYTE value = CPUGetX(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_STX_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    BYTE value = CPUGetX(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_STY_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    BYTE value = CPUGetY(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_STY_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPX(C, m, cyclesPtr);
    BYTE value = CPUGetY(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_STY_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    BYTE value = CPUGetY(C);

    MemoryWrite(m, address, value);
    incrementCycles(cyclesPtr, -1);
}

void INS_TAX_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE Avalue = CPUGetA(C);
    CPUSetX(C, Avalue);
    incrementCycles(cyclesPtr, -1);

    XREG_SET_STATUS(C);
}

void INS_TAY_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE Avalue = CPUGetA(C);
    CPUSetY(C, Avalue);
    incrementCycles(cyclesPtr, -1);

    YREG_SET_STATUS(C);
}

void INS_TXA_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE Xvalue = CPUGetX(C);
    CPUSetA(C, Xvalue);
    incrementCycles(cyclesPtr, -1);

    ACC_SET_STATUS(C);
}

void INS_TYA_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE Yvalue = CPUGetY(C);
    CPUSetA(C, Yvalue);
    incrementCycles(cyclesPtr, -1);

    ACC_SET_STATUS(C);
}

void INS_TSX_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE stackPointer = CPUGetSP(C);
    CPUSetX(C, stackPointer);
    incrementCycles(cyclesPtr, -1);

    XREG_SET_STATUS(C);
}

void INS_TXS_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE Xvalue = CPUGetX(C);
    CPUSetSP(C, Xvalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_PHA_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE Avalue = CPUGetA(C);

    MemoryWriteToStack(m, CPUGetSP(C), (Avalue >> 8) & 0x00FF);
    CPUIncrementSP(C, -1);
    incrementCycles(cyclesPtr, -1);

    MemoryWriteToStack(m, CPUGetSP(C), Avalue & 0x00FF);
    CPUIncrementSP(C, -1);
    incrementCycles(cyclesPtr, -1);
}

void INS_PHP_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE statusRegister = CPUGetStatusRegister(C);

    MemoryWriteToStack(m, CPUGetSP(C), (statusRegister >> 8) & 0x00FF);
    CPUIncrementSP(C, -1);
    incrementCycles(cyclesPtr, -1);

    MemoryWriteToStack(m, CPUGetSP(C), (statusRegister & 0x00FF));
    CPUIncrementSP(C, -1);
    incrementCycles(cyclesPtr, -1);
}

void INS_PLA_IMP(CPU C, Memory m, int *cyclesPtr)
{
    CPUIncrementSP(C, 1);
    incrementCycles(cyclesPtr, -1);

    BYTE stackValue = MemoryReadFromStack(m, CPUGetSP(C), cyclesPtr);

    CPUSetA(C, stackValue);

    ACC_SET_STATUS(C);
    incrementCycles(cyclesPtr, -1);
}

void INS_PLP_IMP(CPU C, Memory m, int *cyclesPtr)
{
    CPUIncrementSP(C, 1);
    incrementCycles(cyclesPtr, -1);

    BYTE stackValue = MemoryReadFromStack(m, CPUGetSP(C), cyclesPtr);

    CPUSetStatusRegister(C, stackValue);
    incrementCycles(cyclesPtr, -1);
}

void INS_AND_IM(CPU C, Memory m, int *cyclesPtr)
{
    BYTE value = CPUFetchByte(C, m, cyclesPtr);
    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, Avalue & value);

    ACC_SET_STATUS(C);
}

void INS_AND_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);

    BYTE Avalue = CPUGetA(C);
    CPUSetA(C, Avalue & value);

    ACC_SET_STATUS(C);
}

void INS_AND_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPX(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);

    BYTE Avalue = CPUGetA(C);
    CPUSetA(C, Avalue & value);

    ACC_SET_STATUS(C);
}

void INS_AND_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);

    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, Avalue & value);

    ACC_SET_STATUS(C);
}

void INS_AND_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABX(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);

    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, Avalue & value);

    ACC_SET_STATUS(C);
}

void INS_AND_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABY(C, m, cyclesPtr);
    BYTE value = MemoryReadByte(m, address, cyclesPtr);

    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, Avalue & value);

    ACC_SET_STATUS(C);
}

void INS_AND_INX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INX(C, m, cyclesPtr);

    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, Avalue & value);

    ACC_SET_STATUS(C);
}

void INS_AND_INY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INY(C, m, cyclesPtr);

    BYTE value = MemoryReadByte(m, address, cyclesPtr);
    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, Avalue & value);

    ACC_SET_STATUS(C);
}

void INS_JSR_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    CPUIncrementPC(C, -1);
    WORD pc = CPUGetPC(C);

    MemoryWrite(m, CPUGetSP(C), (pc >> 8) & 0x00FF);
    incrementCycles(cyclesPtr, -1);

    CPUIncrementSP(C, -1);

    MemoryWrite(m, CPUGetSP(C), pc & 0x00FF);
    incrementCycles(cyclesPtr, -1);
    CPUSetPC(C, address);

    incrementCycles(cyclesPtr, -1);
}
