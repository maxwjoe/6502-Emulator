#include "Eagle.h"
extern "C"
{
#include "Emulator6502.h"
#include "testDefinitions.h"
}

TEST(T_LDX_IM)
{
    HW_SETUP();
    TEST_CYCLES(2);

    BYTE targetValue = 0xA4;

    MemoryWrite(M, PC_START, LDX_IM);
    MemoryWrite(M, PC_START + 1, 0xA4);

    CPUExecute(C);

    BYTE X = CPUGetX(C);
    CHECK_EQ(X, targetValue);

    HW_PACKDOWN();
}

TEST(T_LDX_ZP)
{
    HW_SETUP();
    TEST_CYCLES(3);

    BYTE zpAddress = 0x88;
    BYTE targetValue = 0xA4;

    MemoryWrite(M, PC_START, LDX_ZP);
    MemoryWrite(M, PC_START + 1, zpAddress);

    MemoryWrite(M, zpAddress, targetValue);

    CPUExecute(C);

    BYTE X = CPUGetX(C);
    CHECK_EQ(X, targetValue);

    HW_PACKDOWN();
}

TEST(T_LDX_ZPY)
{
    HW_SETUP();
    TEST_CYCLES(4);

    BYTE zpAddress = 0x88;
    BYTE yRegister = 0x22;
    BYTE targetValue = 0xA4;

    CPUSetY(C, yRegister);

    MemoryWrite(M, PC_START, LDX_ZPY);
    MemoryWrite(M, PC_START + 1, zpAddress);

    MemoryWrite(M, zpAddress + yRegister, targetValue);

    CPUExecute(C);

    BYTE X = CPUGetX(C);
    CHECK_EQ(X, targetValue);

    HW_PACKDOWN();
}

TEST(T_LDX_AB)
{
    HW_SETUP();
    TEST_CYCLES(4);

    BYTE targetValue = 0xA4;

    MemoryWrite(M, PC_START, LDX_AB);
    MemoryWrite(M, PC_START + 1, 0x11);
    MemoryWrite(M, PC_START + 2, 0x11);

    MemoryWrite(M, 0x1111, targetValue);

    CPUExecute(C);

    BYTE X = CPUGetX(C);
    CHECK_EQ(X, targetValue);

    HW_PACKDOWN();
}

TEST(T_LDX_ABY)
{
    HW_SETUP();
    TEST_CYCLES(4);

    BYTE yRegister = 0x55;
    BYTE targetValue = 0xA4;

    CPUSetY(C, yRegister);

    MemoryWrite(M, PC_START, LDX_ABY);
    MemoryWrite(M, PC_START + 1, 0x11);
    MemoryWrite(M, PC_START + 2, 0x11);

    MemoryWrite(M, 0x1111 + yRegister, targetValue);

    CPUExecute(C);

    BYTE X = CPUGetX(C);
    CHECK_EQ(X, targetValue);

    HW_PACKDOWN();
}