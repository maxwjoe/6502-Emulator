#include "Eagle.h"
extern "C"
{
#include "Emulator6502.h"
#include "testDefinitions.h"
}

TEST(T_STX_ZP)
{
    HW_SETUP();
    TEST_CYCLES(3);

    CPUSetX(C, 0x98);

    MemoryWrite(M, PC_START, STX_ZP);
    MemoryWrite(M, PC_START + 1, 0x44);

    int runCorrect = CPUExecute(C);

    BYTE storedValue = MemoryReadByte(M, 0x44, clkPtr);

    CHECK_EQ(storedValue, 0x98);
    CHECK_TRUE(runCorrect);

    HW_PACKDOWN();
}

TEST(T_STX_ZPY)
{
    HW_SETUP();
    TEST_CYCLES(4);

    CPUSetX(C, 0x55);
    CPUSetY(C, 0x02);

    MemoryWrite(M, PC_START, STX_ZPY);
    MemoryWrite(M, PC_START + 1, 0x44);

    int runCorrect = CPUExecute(C);

    BYTE storedValue = MemoryReadByte(M, 0x44 + 0x02, clkPtr);

    CHECK_TRUE(runCorrect);
    CHECK_EQ(storedValue, 0x55);

    HW_PACKDOWN();
}

TEST(T_STX_AB)
{
    HW_SETUP();
    TEST_CYCLES(4);

    CPUSetX(C, 0x66);

    MemoryWrite(M, PC_START, STX_AB);
    MemoryWrite(M, PC_START + 1, 0x33);
    MemoryWrite(M, PC_START + 2, 0x77);

    int runCorrect = CPUExecute(C);

    BYTE storedValue = MemoryReadByte(M, 0x7733, clkPtr);

    CHECK_TRUE(runCorrect);
    CHECK_EQ(storedValue, 0x66);

    HW_PACKDOWN();
}