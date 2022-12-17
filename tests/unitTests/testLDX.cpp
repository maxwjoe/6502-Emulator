#include "Eagle.h"
extern "C"
{
#include "Emulator6502.h"
#include "testDefinitions.h"
}

TEST(T_LDX_IM)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE targetValue = 0xA4;

    MemoryWrite(ROM, PC_START, LDX_IM);
    MemoryWrite(ROM, PC_START + 1, 0xA4);

    CPUExecute(c, ROM, 2);

    BYTE X = CPUGetX(c);
    CHECK_EQ(X, targetValue);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDX_ZP)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE zpAddress = 0x88;
    BYTE targetValue = 0xA4;

    MemoryWrite(ROM, PC_START, LDX_ZP);
    MemoryWrite(ROM, PC_START + 1, zpAddress);

    MemoryWrite(ROM, zpAddress, targetValue);

    CPUExecute(c, ROM, 3);

    BYTE X = CPUGetX(c);
    CHECK_EQ(X, targetValue);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDX_ZPY)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE zpAddress = 0x88;
    BYTE yRegister = 0x22;
    BYTE targetValue = 0xA4;

    CPUSetY(c, yRegister);

    MemoryWrite(ROM, PC_START, LDX_ZPY);
    MemoryWrite(ROM, PC_START + 1, zpAddress);

    MemoryWrite(ROM, zpAddress + yRegister, targetValue);

    CPUExecute(c, ROM, 4);

    BYTE X = CPUGetX(c);
    CHECK_EQ(X, targetValue);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDX_AB)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE targetValue = 0xA4;

    MemoryWrite(ROM, PC_START, LDX_AB);
    MemoryWrite(ROM, PC_START + 1, 0x11);
    MemoryWrite(ROM, PC_START + 2, 0x11);

    MemoryWrite(ROM, 0x1111, targetValue);

    CPUExecute(c, ROM, 4);

    BYTE X = CPUGetX(c);
    CHECK_EQ(X, targetValue);

    CPUFree(c);
    MemoryFree(ROM);
}

TEST(T_LDX_ABY)
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE yRegister = 0x55;
    BYTE targetValue = 0xA4;

    CPUSetY(c, yRegister);

    MemoryWrite(ROM, PC_START, LDX_ABY);
    MemoryWrite(ROM, PC_START + 1, 0x11);
    MemoryWrite(ROM, PC_START + 2, 0x11);

    MemoryWrite(ROM, 0x1111 + yRegister, targetValue);

    CPUExecute(c, ROM, 4);

    BYTE X = CPUGetX(c);
    CHECK_EQ(X, targetValue);

    CPUFree(c);
    MemoryFree(ROM);
}