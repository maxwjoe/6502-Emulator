#include "AddressModes.h"

// --- Addressing Mode Definitions ---

BYTE ADDR_ZP(CPU C, Memory m)
{
    return CPUFetchByte(C, m);
}

BYTE ADDR_ZPX(CPU C, Memory m)
{
    BYTE ZPAddress = CPUFetchByte(C, m);
    ZPAddress += CPUGetX(C);
    ClockTick(CPUGetClock(C));
    return ZPAddress;
}

BYTE ADDR_ZPY(CPU C, Memory m)
{
    BYTE ZPAddress = CPUFetchByte(C, m);
    ZPAddress += CPUGetY(C);
    ClockTick(CPUGetClock(C));
    return ZPAddress;
}

WORD ADDR_AB(CPU C, Memory m)
{
    return CPUFetchWord(C, m);
}

WORD ADDR_ABX(CPU C, Memory m)
{
    WORD address = CPUFetchWord(C, m);
    address += CPUGetX(C);

    return address;
}

WORD ADDR_ABY(CPU C, Memory m)
{
    WORD address = CPUFetchWord(C, m);
    address += CPUGetY(C);

    return address;
}

WORD ADDR_INX(CPU C, Memory m)
{
    BYTE ZPAddress = CPUFetchByte(C, m);
    ZPAddress += CPUGetX(C);

    WORD loadAddress = MemoryReadWord(m, ZPAddress, CPUGetClock(C));

    return loadAddress;
}

WORD ADDR_INY(CPU C, Memory m)
{
    BYTE ZPAddress = CPUFetchByte(C, m);
    ZPAddress += CPUGetY(C);

    WORD loadAddress = MemoryReadWord(m, ZPAddress, CPUGetClock(C));

    return loadAddress;
}
