#include "Instructions.h"

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
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);

    BYTE A = MemoryReadByte(m, ZPAddress, cyclesPtr);
    CPUSetA(C, A);

    incrementCycles(cyclesPtr, -1);

    ACC_SET_STATUS(C);
}

void INS_LDA_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddressPx = CPUFetchByte(C, m, cyclesPtr);

    ZPAddressPx = ZPAddressPx + CPUGetX(C);
    incrementCycles(cyclesPtr, -1);

    BYTE A = MemoryReadByte(m, ZPAddressPx, cyclesPtr);
    CPUSetA(C, A);
    incrementCycles(cyclesPtr, -1);

    ACC_SET_STATUS(C);
}

void INS_LDA_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    BYTE A = MemoryReadByte(m, address, cyclesPtr);
    CPUSetA(C, A);

    ACC_SET_STATUS(C);
}

void INS_LDA_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    address += CPUGetX(C);

    BYTE Avalue = MemoryReadByte(m, address, cyclesPtr);
    CPUSetA(C, Avalue);

    ACC_SET_STATUS(C);
}

void INS_LDA_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    address += CPUGetY(C);

    BYTE Avalue = MemoryReadByte(m, address, cyclesPtr);
    CPUSetA(C, Avalue);

    ACC_SET_STATUS(C);
}

void INS_LDA_INX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = CPUFetchByte(C, m, cyclesPtr);
    address += CPUGetX(C);

    WORD loadAddress = MemoryReadWord(m, address, cyclesPtr);

    BYTE Avalue = MemoryReadByte(m, loadAddress, cyclesPtr);

    CPUSetA(C, Avalue);
    ACC_SET_STATUS(C);
}

void INS_LDA_INY(CPU C, Memory m, int *cyclesPtr)
{
    BYTE address = CPUFetchByte(C, m, cyclesPtr);
    address += CPUGetY(C);

    WORD loadAddress = MemoryReadWord(m, address, cyclesPtr);
    BYTE Avalue = MemoryReadByte(m, loadAddress, cyclesPtr);

    CPUSetA(C, Avalue);

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
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);

    BYTE Xvalue = MemoryReadByte(m, ZPAddress, cyclesPtr);
    CPUSetX(C, Xvalue);

    incrementCycles(cyclesPtr, -1);
    XREG_SET_STATUS(C);
}

void INS_LDX_ZPY(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddressY = CPUFetchByte(C, m, cyclesPtr);

    ZPAddressY += CPUGetY(C);
    incrementCycles(cyclesPtr, -1);

    BYTE Xvalue = MemoryReadByte(m, ZPAddressY, cyclesPtr);
    CPUSetX(C, Xvalue);

    incrementCycles(cyclesPtr, -1);
    XREG_SET_STATUS(C);
}

void INS_LDX_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    BYTE Xvalue = MemoryReadByte(m, address, cyclesPtr);

    CPUSetX(C, Xvalue);

    XREG_SET_STATUS(C);
}

void INS_LDX_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    address += CPUGetY(C);

    BYTE Xvalue = MemoryReadByte(m, address, cyclesPtr);

    CPUSetX(C, Xvalue);
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
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);
    BYTE Yvalue = MemoryReadByte(m, ZPAddress, cyclesPtr);

    CPUSetY(C, Yvalue);
    YREG_SET_STATUS(C);
}

void INS_LDY_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddressX = CPUFetchByte(C, m, cyclesPtr);
    ZPAddressX += CPUGetX(C);
    incrementCycles(cyclesPtr, -1);

    BYTE Yvalue = MemoryReadByte(m, ZPAddressX, cyclesPtr);
    CPUSetY(C, Yvalue);

    YREG_SET_STATUS(C);
}

void INS_LDY_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    BYTE Yvalue = MemoryReadByte(m, address, cyclesPtr);
    CPUSetY(C, Yvalue);

    YREG_SET_STATUS(C);
}

void INS_LDY_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    address += CPUGetX(C);

    BYTE Yvalue = MemoryReadByte(m, address, cyclesPtr);
    CPUSetY(C, Yvalue);

    YREG_SET_STATUS(C);
}

void INS_STA_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPaddress = CPUFetchByte(C, m, cyclesPtr);
    BYTE Avalue = CPUGetA(C);

    MemoryWrite(m, ZPaddress, Avalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_STA_ZPX(CPU C, Memory m, int *cyclesPtr)
{

    BYTE ZPaddressX = CPUFetchByte(C, m, cyclesPtr);
    ZPaddressX += CPUGetX(C);

    incrementCycles(cyclesPtr, -1);

    BYTE Avalue = CPUGetA(C);
    MemoryWrite(m, ZPaddressX, Avalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_STA_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);

    BYTE Avalue = CPUGetA(C);
    MemoryWrite(m, address, Avalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_STA_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    address += CPUGetX(C);
    incrementCycles(cyclesPtr, -1);

    BYTE Avalue = CPUGetA(C);
    MemoryWrite(m, address, Avalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_STA_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    address += CPUGetY(C);
    incrementCycles(cyclesPtr, -1);

    BYTE Avalue = CPUGetA(C);
    MemoryWrite(m, address, Avalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_STA_INX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPaddress = CPUFetchByte(C, m, cyclesPtr);
    ZPaddress += CPUGetX(C);
    incrementCycles(cyclesPtr, -1);

    WORD writeAddress = MemoryReadWord(m, ZPaddress, cyclesPtr);

    BYTE Avalue = CPUGetA(C);
    MemoryWrite(m, writeAddress, Avalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_STA_INY(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPaddress = CPUFetchByte(C, m, cyclesPtr);
    ZPaddress += CPUGetY(C);
    incrementCycles(cyclesPtr, -1);

    WORD writeAddress = MemoryReadWord(m, ZPaddress, cyclesPtr);

    BYTE Avalue = CPUGetA(C);
    MemoryWrite(m, writeAddress, Avalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_STX_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPaddress = CPUFetchByte(C, m, cyclesPtr);
    BYTE Xvalue = CPUGetX(C);

    MemoryWrite(m, ZPaddress, Xvalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_STX_ZPY(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPaddressY = CPUFetchByte(C, m, cyclesPtr);
    ZPaddressY += CPUGetY(C);
    incrementCycles(cyclesPtr, -1);

    BYTE Xvalue = CPUGetX(C);

    MemoryWrite(m, ZPaddressY, Xvalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_STX_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    BYTE Xvalue = CPUGetX(C);

    MemoryWrite(m, address, Xvalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_STY_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPaddress = CPUFetchByte(C, m, cyclesPtr);
    BYTE Yvalue = CPUGetY(C);

    MemoryWrite(m, ZPaddress, Yvalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_STY_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPaddressX = CPUFetchByte(C, m, cyclesPtr);
    ZPaddressX += CPUGetX(C);
    incrementCycles(cyclesPtr, -1);

    BYTE Yvalue = CPUGetY(C);

    MemoryWrite(m, ZPaddressX, Yvalue);
    incrementCycles(cyclesPtr, -1);
}

void INS_STY_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    BYTE Yvalue = CPUGetY(C);

    MemoryWrite(m, address, Yvalue);
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
