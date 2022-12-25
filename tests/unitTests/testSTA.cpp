#include "Eagle.h"
extern "C"
{
#include "Emulator6502.h"
#include "testDefinitions.h"
}

TEST(T_STA_ZP)
{
    HW_SETUP();
    TEST_CYCLES(3);

    CPUSetA(C, 0x66);

    MemoryWrite(M, PC_START, STA_ZP);
    MemoryWrite(M, PC_START + 1, 0x55);

    int runCorrect = CPUExecute(C);
    CHECK_TRUE(runCorrect);

    BYTE storedValue = MemoryReadByte(M, 0x55, clkPtr);

    CHECK_EQ(storedValue, 0x66);

    HW_PACKDOWN();
}

TEST(T_STA_ZPX)
{
    HW_SETUP();
    TEST_CYCLES(4);

    CPUSetX(C, 0x11);
    CPUSetA(C, 0x33);

    MemoryWrite(M, PC_START, STA_ZPX);
    MemoryWrite(M, PC_START + 1, 0x22);

    int runCorrect = CPUExecute(C);
    CHECK_TRUE(runCorrect);

    BYTE storedValue = MemoryReadByte(M, 0x22 + 0x11, clkPtr);

    CHECK_EQ(storedValue, 0x33);

    HW_PACKDOWN();
}

TEST(T_STA_AB)
{
    HW_SETUP();
    TEST_CYCLES(4);

    CPUSetA(C, 0x99);

    MemoryWrite(M, PC_START, STA_AB);
    MemoryWrite(M, PC_START + 1, 0x23);
    MemoryWrite(M, PC_START + 2, 0x56);

    int runCorrect = CPUExecute(C);
    CHECK_TRUE(runCorrect);

    BYTE storedValue = MemoryReadByte(M, 0x5623, clkPtr);

    CHECK_EQ(storedValue, 0x99);

    HW_PACKDOWN();
}

TEST(T_STA_ABX)
{
    HW_SETUP();
    TEST_CYCLES(5);

    CPUSetA(C, 0x46);
    CPUSetX(C, 0x02);

    MemoryWrite(M, PC_START, STA_ABX);
    MemoryWrite(M, PC_START + 1, 0x23);
    MemoryWrite(M, PC_START + 2, 0x56);

    int runCorrect = CPUExecute(C);
    CHECK_TRUE(runCorrect);

    BYTE storedValue = MemoryReadByte(M, 0x5623 + 0x02, clkPtr);

    CHECK_EQ(storedValue, 0x46);

    HW_PACKDOWN();
}

TEST(T_STA_ABY)
{
    HW_SETUP();
    TEST_CYCLES(5);

    CPUSetA(C, 0x46);
    CPUSetY(C, 0x03);

    MemoryWrite(M, PC_START, STA_ABY);
    MemoryWrite(M, PC_START + 1, 0x23);
    MemoryWrite(M, PC_START + 2, 0x56);

    int runCorrect = CPUExecute(C);
    CHECK_TRUE(runCorrect);

    BYTE storedValue = MemoryReadByte(M, 0x5623 + 0x03, clkPtr);

    CHECK_EQ(storedValue, 0x46);

    HW_PACKDOWN();
}

TEST(T_STA_INX)
{
    HW_SETUP();
    TEST_CYCLES(6);

    BYTE XReg = 0x33;

    CPUSetX(C, XReg);
    CPUSetA(C, 0x12);

    MemoryWrite(M, PC_START, STA_INX);
    MemoryWrite(M, PC_START + 1, 0x55);
    MemoryWrite(M, 0x55 + XReg, 0x12);
    MemoryWrite(M, 0x56 + XReg, 0x33);

    int runCorrect = CPUExecute(C);
    CHECK_TRUE(runCorrect);

    BYTE storedValue = MemoryReadByte(M, 0x3312, clkPtr);

    CHECK_EQ(storedValue, 0x12);

    HW_PACKDOWN();
}

TEST(T_STA_INY)
{
    HW_SETUP();
    TEST_CYCLES(6);

    BYTE YReg = 0x33;

    CPUSetY(C, YReg);
    CPUSetA(C, 0x12);

    MemoryWrite(M, PC_START, STA_INY);
    MemoryWrite(M, PC_START + 1, 0x55);
    MemoryWrite(M, 0x55 + YReg, 0x12);
    MemoryWrite(M, 0x56 + YReg, 0x33);

    int runCorrect = CPUExecute(C);
    CHECK_TRUE(runCorrect);

    BYTE storedValue = MemoryReadByte(M, 0x3312, clkPtr);

    CHECK_EQ(storedValue, 0x12);

    HW_PACKDOWN();
}