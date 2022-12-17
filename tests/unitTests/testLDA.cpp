#include "Eagle.h"
extern "C"
{
#include "Emulator6502.h"
#include "testDefinitions.h"
}

TEST(T_LDA_IM)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE targetValue = 0xA4;

    MemoryWrite(ROM, PC_START, LDA_IM);
    MemoryWrite(ROM, PC_START + 1, 0xA4);

    CPUExecute(c, ROM, 2);

    BYTE accumulator = CPUGetA(c);
    CHECK_EQ(accumulator, targetValue);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDA_ZP)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE zpAddress = 0xA4;
    BYTE targetValue = 0x55;

    MemoryWrite(ROM, PC_START, LDA_ZP);
    MemoryWrite(ROM, PC_START + 1, zpAddress);

    MemoryWrite(ROM, zpAddress, targetValue);

    CPUExecute(c, ROM, 3);

    BYTE accumulator = CPUGetA(c);
    CHECK_EQ(accumulator, targetValue);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDA_ZPX)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE xRegister = 0x11;
    BYTE zpAddress = 0xA4;
    BYTE targetValue = 0x55;

    CPUSetX(c, xRegister);

    MemoryWrite(ROM, PC_START, LDA_ZPX);
    MemoryWrite(ROM, PC_START + 1, zpAddress);

    MemoryWrite(ROM, zpAddress + xRegister, targetValue);

    CPUExecute(c, ROM, 4);

    BYTE accumulator = CPUGetA(c);
    CHECK_EQ(accumulator, targetValue);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDA_AB)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE targetValue = 0x55;

    MemoryWrite(ROM, PC_START, LDA_AB);
    MemoryWrite(ROM, PC_START + 1, 0x88);
    MemoryWrite(ROM, PC_START + 2, 0x88);

    MemoryWrite(ROM, 0x8888, targetValue);

    CPUExecute(c, ROM, 4);

    BYTE accumulator = CPUGetA(c);
    CHECK_EQ(accumulator, targetValue);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDA_ABX)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE xRegister = 0x87;
    BYTE targetValue = 0x55;

    CPUSetX(c, xRegister);

    MemoryWrite(ROM, PC_START, LDA_ABX);
    MemoryWrite(ROM, PC_START + 1, 0x88);
    MemoryWrite(ROM, PC_START + 2, 0x88);

    MemoryWrite(ROM, 0x8888 + xRegister, targetValue);

    CPUExecute(c, ROM, 4);

    BYTE accumulator = CPUGetA(c);
    CHECK_EQ(accumulator, targetValue);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDA_ABY)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE yRegister = 0x99;
    BYTE targetValue = 0x23;

    CPUSetY(c, yRegister);

    MemoryWrite(ROM, PC_START, LDA_ABY);
    MemoryWrite(ROM, PC_START + 1, 0xBA);
    MemoryWrite(ROM, PC_START + 2, 0x34);

    MemoryWrite(ROM, 0x34BA + yRegister, targetValue);

    CPUExecute(c, ROM, 4);

    BYTE accumulator = CPUGetA(c);
    CHECK_EQ(accumulator, targetValue);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDA_INX)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE xRegister = 0x45;
    BYTE zpAddress = 0x11;
    BYTE value = 0x56;

    CPUSetX(c, xRegister);

    MemoryWrite(ROM, PC_START, LDA_INX);
    MemoryWrite(ROM, PC_START + 1, zpAddress);

    MemoryWrite(ROM, zpAddress + xRegister, 0x22);
    MemoryWrite(ROM, zpAddress + xRegister + 1, 0x22);

    MemoryWrite(ROM, 0x2222, value);

    CPUExecute(c, ROM, 6);

    BYTE accumulator = CPUGetA(c);
    CHECK_EQ(accumulator, value);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDA_INY)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE yRegister = 0x45;
    BYTE zpAddress = 0x11;
    BYTE value = 0x56;

    CPUSetY(c, yRegister);

    MemoryWrite(ROM, PC_START, LDA_INY);
    MemoryWrite(ROM, PC_START + 1, zpAddress);

    MemoryWrite(ROM, zpAddress + yRegister, 0x22);
    MemoryWrite(ROM, zpAddress + yRegister + 1, 0x22);

    MemoryWrite(ROM, 0x2222, value);

    CPUExecute(c, ROM, 6);

    BYTE accumulator = CPUGetA(c);
    CHECK_EQ(accumulator, value);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDA_N_FLAG)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE negativeNumber = 0x8C;

    MemoryWrite(ROM, PC_START, LDA_IM);
    MemoryWrite(ROM, PC_START + 1, negativeNumber);

    CPUExecute(c, ROM, 2);

    int N_FLAG = CPUGetStatusFlag(c, PS_N);
    CHECK_TRUE(N_FLAG);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDA_Z_FLAG)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    MemoryWrite(ROM, PC_START, LDA_IM);
    MemoryWrite(ROM, PC_START + 1, 0x00);

    CPUExecute(c, ROM, 2);

    int Z_FLAG = CPUGetStatusFlag(c, PS_Z);
    CHECK_TRUE(Z_FLAG);

    CPUFree(c);
    MemoryFree(ROM);
}