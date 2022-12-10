#include "Instructions.h"
#include "AddressModes.h"
#include "Operations.h"

// s_IncrementCycles : Increments cycles pointer (To be used in future to control clock speed)
static void s_IncrementCycles(int *cyclesPtr, int amount)
{
    *cyclesPtr = *cyclesPtr + amount;
}

void INS_LDA_IM(CPU C, Memory m, int *cyclesPtr)
{
    BYTE value = CPUFetchByte(C, m, cyclesPtr);
    CPUSetA(C, value);
    STAT_Accumulator(C);
}

void INS_LDA_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    OPER_LDA(C, m, cyclesPtr, address);
}

void INS_LDA_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPX(C, m, cyclesPtr);
    OPER_LDA(C, m, cyclesPtr, address);
}

void INS_LDA_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    OPER_LDA(C, m, cyclesPtr, address);
}

void INS_LDA_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABX(C, m, cyclesPtr);
    OPER_LDA(C, m, cyclesPtr, address);
}

void INS_LDA_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABY(C, m, cyclesPtr);
    OPER_LDA(C, m, cyclesPtr, address);
}

void INS_LDA_INX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INX(C, m, cyclesPtr);
    OPER_LDA(C, m, cyclesPtr, address);
}

void INS_LDA_INY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INY(C, m, cyclesPtr);
    OPER_LDA(C, m, cyclesPtr, address);
}

void INS_LDX_IM(CPU C, Memory m, int *cyclesPtr)
{
    BYTE value = CPUFetchByte(C, m, cyclesPtr);
    CPUSetX(C, value);

    STAT_XRegister(C);
}

void INS_LDX_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    OPER_LDX(C, m, cyclesPtr, address);
}

void INS_LDX_ZPY(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPY(C, m, cyclesPtr);
    OPER_LDX(C, m, cyclesPtr, address);
}

void INS_LDX_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    OPER_LDX(C, m, cyclesPtr, address);
}

void INS_LDX_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABY(C, m, cyclesPtr);
    OPER_LDX(C, m, cyclesPtr, address);
}

void INS_LDY_IM(CPU C, Memory m, int *cyclesPtr)
{
    BYTE value = CPUFetchByte(C, m, cyclesPtr);
    CPUSetY(C, value);

    STAT_YRegister(C);
}

void INS_LDY_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    OPER_LDY(C, m, cyclesPtr, address);
}

void INS_LDY_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPX(C, m, cyclesPtr);
    OPER_LDY(C, m, cyclesPtr, address);
}

void INS_LDY_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    OPER_LDY(C, m, cyclesPtr, address);
}

void INS_LDY_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABX(C, m, cyclesPtr);
    OPER_LDY(C, m, cyclesPtr, address);
}

void INS_STA_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    OPER_STA(C, m, cyclesPtr, address);
}

void INS_STA_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPX(C, m, cyclesPtr);
    OPER_STA(C, m, cyclesPtr, address);
}

void INS_STA_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    OPER_STA(C, m, cyclesPtr, address);
}

void INS_STA_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABX(C, m, cyclesPtr);
    OPER_STA(C, m, cyclesPtr, address);
}

void INS_STA_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABY(C, m, cyclesPtr);
    OPER_STA(C, m, cyclesPtr, address);
}

void INS_STA_INX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INX(C, m, cyclesPtr);
    OPER_STA(C, m, cyclesPtr, address);
}

void INS_STA_INY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INY(C, m, cyclesPtr);
    OPER_STA(C, m, cyclesPtr, address);
}

void INS_STX_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    OPER_STX(C, m, cyclesPtr, address);
}

void INS_STX_ZPY(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPY(C, m, cyclesPtr);
    OPER_STX(C, m, cyclesPtr, address);
}

void INS_STX_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    OPER_STX(C, m, cyclesPtr, address);
}

void INS_STY_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    OPER_STY(C, m, cyclesPtr, address);
}

void INS_STY_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPX(C, m, cyclesPtr);
    OPER_STY(C, m, cyclesPtr, address);
}

void INS_STY_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    OPER_STY(C, m, cyclesPtr, address);
}

void INS_TAX_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE Avalue = CPUGetA(C);
    CPUSetX(C, Avalue);
    s_IncrementCycles(cyclesPtr, -1);

    STAT_XRegister(C);
}

void INS_TAY_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE Avalue = CPUGetA(C);
    CPUSetY(C, Avalue);
    s_IncrementCycles(cyclesPtr, -1);

    STAT_YRegister(C);
}

void INS_TXA_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE Xvalue = CPUGetX(C);
    CPUSetA(C, Xvalue);
    s_IncrementCycles(cyclesPtr, -1);

    STAT_Accumulator(C);
}

void INS_TYA_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE Yvalue = CPUGetY(C);
    CPUSetA(C, Yvalue);
    s_IncrementCycles(cyclesPtr, -1);

    STAT_Accumulator(C);
}

void INS_TSX_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE stackPointer = CPUGetSP(C);
    CPUSetX(C, stackPointer);
    s_IncrementCycles(cyclesPtr, -1);

    STAT_XRegister(C);
}

void INS_TXS_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE Xvalue = CPUGetX(C);
    CPUSetSP(C, Xvalue);
    s_IncrementCycles(cyclesPtr, -1);
}

void INS_PHA_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE Avalue = CPUGetA(C);

    MemoryWriteToStack(m, CPUGetSP(C), (Avalue >> 8) & 0x00FF);
    CPUIncrementSP(C, -1);
    s_IncrementCycles(cyclesPtr, -1);

    MemoryWriteToStack(m, CPUGetSP(C), Avalue & 0x00FF);
    CPUIncrementSP(C, -1);
    s_IncrementCycles(cyclesPtr, -1);
}

void INS_PHP_IMP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE statusRegister = CPUGetStatusRegister(C);

    MemoryWriteToStack(m, CPUGetSP(C), (statusRegister >> 8) & 0x00FF);
    CPUIncrementSP(C, -1);
    s_IncrementCycles(cyclesPtr, -1);

    MemoryWriteToStack(m, CPUGetSP(C), (statusRegister & 0x00FF));
    CPUIncrementSP(C, -1);
    s_IncrementCycles(cyclesPtr, -1);
}

void INS_PLA_IMP(CPU C, Memory m, int *cyclesPtr)
{
    CPUIncrementSP(C, 1);
    s_IncrementCycles(cyclesPtr, -1);

    BYTE stackValue = MemoryReadFromStack(m, CPUGetSP(C), cyclesPtr);

    CPUSetA(C, stackValue);

    STAT_Accumulator(C);
    s_IncrementCycles(cyclesPtr, -1);
}

void INS_PLP_IMP(CPU C, Memory m, int *cyclesPtr)
{
    CPUIncrementSP(C, 1);
    s_IncrementCycles(cyclesPtr, -1);

    BYTE stackValue = MemoryReadFromStack(m, CPUGetSP(C), cyclesPtr);

    CPUSetStatusRegister(C, stackValue);
    s_IncrementCycles(cyclesPtr, -1);
}

void INS_AND_IM(CPU C, Memory m, int *cyclesPtr)
{
    BYTE value = CPUFetchByte(C, m, cyclesPtr);
    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, Avalue & value);

    STAT_Accumulator(C);
}

void INS_AND_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    OPER_AND(C, m, cyclesPtr, address);
}

void INS_AND_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPX(C, m, cyclesPtr);
    OPER_AND(C, m, cyclesPtr, address);
}

void INS_AND_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    OPER_AND(C, m, cyclesPtr, address);
}

void INS_AND_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABX(C, m, cyclesPtr);
    OPER_AND(C, m, cyclesPtr, address);
}

void INS_AND_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABY(C, m, cyclesPtr);
    OPER_AND(C, m, cyclesPtr, address);
}

void INS_AND_INX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INX(C, m, cyclesPtr);
    OPER_AND(C, m, cyclesPtr, address);
}

void INS_AND_INY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INY(C, m, cyclesPtr);
    OPER_AND(C, m, cyclesPtr, address);
}

void INS_EOR_IM(CPU C, Memory m, int *cyclesPtr)
{
    BYTE value = CPUFetchByte(C, m, cyclesPtr);
    BYTE Avalue = CPUGetA(C);

    CPUSetA(C, Avalue ^ value);
    STAT_Accumulator(C);
}

void INS_EOR_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZP(C, m, cyclesPtr);
    OPER_EOR(C, m, cyclesPtr, address);
}

void INS_EOR_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = ADDR_ZPX(C, m, cyclesPtr);
    OPER_EOR(C, m, cyclesPtr, address);
}

void INS_EOR_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    OPER_EOR(C, m, cyclesPtr, address);
}

void INS_EOR_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABX(C, m, cyclesPtr);
    OPER_EOR(C, m, cyclesPtr, address);
}

void INS_EOR_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_ABY(C, m, cyclesPtr);
    OPER_EOR(C, m, cyclesPtr, address);
}

void INS_EOR_INX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INX(C, m, cyclesPtr);
    OPER_EOR(C, m, cyclesPtr, address);
}

void INS_EOR_INY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_INY(C, m, cyclesPtr);
    OPER_EOR(C, m, cyclesPtr, address);
}

void INS_JSR_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = ADDR_AB(C, m, cyclesPtr);
    CPUIncrementPC(C, -1);
    WORD pc = CPUGetPC(C);

    MemoryWrite(m, CPUGetSP(C), (pc >> 8) & 0x00FF);
    s_IncrementCycles(cyclesPtr, -1);

    CPUIncrementSP(C, -1);

    MemoryWrite(m, CPUGetSP(C), pc & 0x00FF);
    s_IncrementCycles(cyclesPtr, -1);
    CPUSetPC(C, address);

    s_IncrementCycles(cyclesPtr, -1);
}
