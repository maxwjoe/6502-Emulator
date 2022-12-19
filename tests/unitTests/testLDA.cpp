#include "Eagle.h"
extern "C"
{
#include "Emulator6502.h"
#include "testDefinitions.h"
}

TEST(T_LDA_IM)
{
    BYTE targetData = 0x45;

    HW_SETUP();
    TEST_CYCLES(2);

    MemoryWrite(M, PC_START, LDA_IM);
    MemoryWrite(M, PC_START + 1, targetData);

    CPUExecute(C);

    BYTE A = CPUGetA(C);
    CHECK_EQ(A, targetData);

    HW_PACKDOWN();
}

TEST(T_LDA_ZP)
{
    BYTE zpAddress = 0xA4;
    BYTE targetValue = 0x55;

    HW_SETUP();
    TEST_CYCLES(3);

    MemoryWrite(M, PC_START, LDA_ZP);
    MemoryWrite(M, PC_START + 1, zpAddress);

    MemoryWrite(M, zpAddress, targetValue);

    CPUExecute(C);

    BYTE A = CPUGetA(C);
    CHECK_EQ(A, targetValue);

    HW_PACKDOWN();
}

TEST(T_LDA_ZPX)
{
    HW_SETUP();
    TEST_CYCLES(4);

    BYTE xRegister = 0x11;
    BYTE zpAddress = 0xA4;
    BYTE targetValue = 0x55;

    CPUSetX(C, xRegister);

    MemoryWrite(M, PC_START, LDA_ZPX);
    MemoryWrite(M, PC_START + 1, zpAddress);

    MemoryWrite(M, zpAddress + xRegister, targetValue);

    CPUExecute(C);

    BYTE accumulator = CPUGetA(C);
    CHECK_EQ(accumulator, targetValue);

    HW_PACKDOWN();
}

TEST(T_LDA_AB)
{
    HW_SETUP();
    TEST_CYCLES(4);

    BYTE targetValue = 0x55;

    MemoryWrite(M, PC_START, LDA_AB);
    MemoryWrite(M, PC_START + 1, 0x88);
    MemoryWrite(M, PC_START + 2, 0x88);

    MemoryWrite(M, 0x8888, targetValue);

    CPUExecute(C);

    BYTE accumulator = CPUGetA(C);
    CHECK_EQ(accumulator, targetValue);

    HW_PACKDOWN();
}

TEST(T_LDA_ABX)
{

    HW_SETUP();
    TEST_CYCLES(4);

    BYTE xRegister = 0x87;
    BYTE targetValue = 0x55;

    CPUSetX(C, xRegister);

    MemoryWrite(M, PC_START, LDA_ABX);
    MemoryWrite(M, PC_START + 1, 0x88);
    MemoryWrite(M, PC_START + 2, 0x88);

    MemoryWrite(M, 0x8888 + xRegister, targetValue);

    CPUExecute(C);

    BYTE accumulator = CPUGetA(C);
    CHECK_EQ(accumulator, targetValue);

    HW_PACKDOWN();
}

TEST(T_LDA_ABY)
{
    HW_SETUP();
    TEST_CYCLES(4);

    BYTE yRegister = 0x99;
    BYTE targetValue = 0x23;

    CPUSetY(C, yRegister);

    MemoryWrite(M, PC_START, LDA_ABY);
    MemoryWrite(M, PC_START + 1, 0xBA);
    MemoryWrite(M, PC_START + 2, 0x34);

    MemoryWrite(M, 0x34BA + yRegister, targetValue);

    CPUExecute(C);

    BYTE accumulator = CPUGetA(C);
    CHECK_EQ(accumulator, targetValue);

    HW_PACKDOWN();
}

TEST(T_LDA_INX)
{
    HW_SETUP();
    TEST_CYCLES(6);

    BYTE xRegister = 0x45;
    BYTE zpAddress = 0x11;
    BYTE value = 0x56;

    CPUSetX(C, xRegister);

    MemoryWrite(M, PC_START, LDA_INX);
    MemoryWrite(M, PC_START + 1, zpAddress);
    MemoryWrite(M, zpAddress + xRegister, 0x22);
    MemoryWrite(M, zpAddress + xRegister + 1, 0x22);

    MemoryWrite(M, 0x2222, value);

    CPUExecute(C);

    BYTE accumulator = CPUGetA(C);
    CHECK_EQ(accumulator, value);

    HW_PACKDOWN();
}

TEST(T_LDA_INY)
{
    HW_SETUP();
    TEST_CYCLES(6);

    BYTE yRegister = 0x45;
    BYTE zpAddress = 0x11;
    BYTE value = 0x56;

    CPUSetY(C, yRegister);

    MemoryWrite(M, PC_START, LDA_INY);
    MemoryWrite(M, PC_START + 1, zpAddress);

    MemoryWrite(M, zpAddress + yRegister, 0x22);
    MemoryWrite(M, zpAddress + yRegister + 1, 0x22);

    MemoryWrite(M, 0x2222, value);

    CPUExecute(C);

    BYTE accumulator = CPUGetA(C);
    CHECK_EQ(accumulator, value);

    HW_PACKDOWN();
}

TEST(T_LDA_N_FLAG)
{
    HW_SETUP();
    TEST_CYCLES(2);

    BYTE negativeNumber = 0x8C;

    MemoryWrite(M, PC_START, LDA_IM);
    MemoryWrite(M, PC_START + 1, negativeNumber);

    CPUExecute(C);

    int N_FLAG = CPUGetStatusFlag(C, PS_N);
    CHECK_TRUE(N_FLAG);

    HW_PACKDOWN();
}

TEST(T_LDA_Z_FLAG)
{
    HW_SETUP();
    TEST_CYCLES(2);

    MemoryWrite(M, PC_START, LDA_IM);
    MemoryWrite(M, PC_START + 1, 0x00);

    CPUExecute(C);

    int Z_FLAG = CPUGetStatusFlag(C, PS_Z);
    CHECK_TRUE(Z_FLAG);

    HW_PACKDOWN();
}