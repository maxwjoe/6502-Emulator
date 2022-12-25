#include "Eagle.h"
extern "C"
{
#include "Emulator6502.h"
#include "testDefinitions.h"
}

TEST(T_LDY_IM)
{
    HW_SETUP();
    TEST_CYCLES(2);

    BYTE targetValue = 0x99;

    MemoryWrite(M, PC_START, LDY_IM);
    MemoryWrite(M, PC_START + 1, targetValue);

    int runCorrect = CPUExecute(C);

    GET_INTERNALS();

    CHECK_TRUE(runCorrect);
    CHECK_EQ(R_Y, targetValue);
    CHECK_TRUE(F_N);
    CHECK_FALSE(F_Z);

    HW_PACKDOWN();
}

TEST(T_LDY_ZP)
{
    HW_SETUP();
    TEST_CYCLES(3);

    BYTE zpAddress = 0x55;
    BYTE targetValue = 0x19;

    MemoryWrite(M, PC_START, LDY_ZP);
    MemoryWrite(M, PC_START + 1, zpAddress);
    MemoryWrite(M, zpAddress, targetValue);

    int runCorrect = CPUExecute(C);
    GET_INTERNALS();

    CHECK_TRUE(runCorrect);
    CHECK_EQ(R_Y, targetValue);
    CHECK_FALSE(F_N);
    CHECK_FALSE(F_Z);

    HW_PACKDOWN();
}

TEST(T_LDY_ZPX)
{
    HW_SETUP();
    TEST_CYCLES(4);

    MemoryWriteAll(M, 0xFF);

    BYTE zpAddress = 0x55;
    BYTE targetValue = 0x00;
    BYTE XRegister = 0x45;

    CPUSetX(C, XRegister);

    MemoryWrite(M, PC_START, LDY_ZPX);
    MemoryWrite(M, PC_START + 1, zpAddress);

    MemoryWrite(M, zpAddress + XRegister, targetValue);

    int runCorrect = CPUExecute(C);

    GET_INTERNALS();

    CHECK_TRUE(runCorrect);
    CHECK_EQ(R_Y, targetValue);
    CHECK_TRUE(F_Z);
    CHECK_FALSE(F_N);

    HW_PACKDOWN();
}

TEST(T_LDY_AB)
{
    HW_SETUP();
    TEST_CYCLES(4);

    BYTE targetValue = 0x88;

    MemoryWrite(M, PC_START, LDY_AB);
    MemoryWrite(M, PC_START + 1, 0x67);
    MemoryWrite(M, PC_START + 2, 0x32);

    MemoryWrite(M, 0x3267, targetValue);

    int runCorrect = CPUExecute(C);

    GET_INTERNALS();

    CHECK_TRUE(runCorrect);
    CHECK_EQ(R_Y, targetValue);
    CHECK_TRUE(F_N);
    CHECK_FALSE(F_Z);

    HW_PACKDOWN();
}

TEST(T_LDY_ABX)
{
    HW_SETUP();
    TEST_CYCLES(4);

    BYTE targetValue = 0x76;
    BYTE XRegister = 0x33;

    CPUSetX(C, XRegister);

    MemoryWrite(M, PC_START, LDY_ABX);
    MemoryWrite(M, PC_START + 1, 0x67);
    MemoryWrite(M, PC_START + 2, 0x32);

    MemoryWrite(M, 0x3267 + XRegister, targetValue);

    int runCorrect = CPUExecute(C);

    GET_INTERNALS();

    CHECK_TRUE(runCorrect);
    CHECK_EQ(R_Y, targetValue);
    CHECK_FALSE(F_Z);
    CHECK_FALSE(F_N);

    HW_PACKDOWN();
}