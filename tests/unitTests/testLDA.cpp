extern "C"
{
#include "Emulator6502.h"
#include "testDefinitions.h"
}

int T_LDA_IM()
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE targetValue = 0xA4;

    MemoryWrite(ROM, PC_START, LDA_IM);
    MemoryWrite(ROM, PC_START + 1, 0xA4);

    CPUExecute(c, ROM, 2);

    int hasPassed = (CPUGetA(c) == targetValue);

    CPUFree(c);
    MemoryFree(ROM);

    return hasPassed;
}

int T_LDA_ZP()
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

    int hasPassed = (CPUGetA(c) == targetValue);

    CPUFree(c);
    MemoryFree(ROM);

    return hasPassed;
}

int T_LDA_ZPX()
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

    int hasPassed = (CPUGetA(c) == targetValue);

    CPUFree(c);
    MemoryFree(ROM);

    return hasPassed;
}

int T_LDA_AB()
{
    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    BYTE targetValue = 0x55;

    MemoryWrite(ROM, PC_START, LDA_ZPX);
    MemoryWrite(ROM, PC_START + 1, 0x88);
    MemoryWrite(ROM, PC_START + 1, 0x88);

    MemoryWrite(ROM, 0x8888, targetValue);

    CPUExecute(c, ROM, 4);

    int hasPassed = (CPUGetA(c) == targetValue);

    CPUFree(c);
    MemoryFree(ROM);

    return hasPassed;
}