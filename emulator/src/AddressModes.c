#include "AddressModes.h"

// --- Addressing Mode Definitions ---

BYTE ADDR_ZP(CPU C)
{
    return CPUFetchByte(C);
}

BYTE ADDR_ZPX(CPU C)
{
    BYTE ZPAddress = CPUFetchByte(C);
    ZPAddress += CPUGetX(C);
    ClockTick(CPUGetClock(C));
    return ZPAddress;
}

BYTE ADDR_ZPY(CPU C)
{
    BYTE ZPAddress = CPUFetchByte(C);
    ZPAddress += CPUGetY(C);
    ClockTick(CPUGetClock(C));
    return ZPAddress;
}

WORD ADDR_AB(CPU C)
{
    return CPUFetchWord(C);
}

WORD ADDR_ABX(CPU C)
{
    WORD address = CPUFetchWord(C);
    address += CPUGetX(C);

    return address;
}

WORD ADDR_ABY(CPU C)
{
    WORD address = CPUFetchWord(C);
    address += CPUGetY(C);

    return address;
}

WORD ADDR_INX(CPU C)
{
    BYTE ZPAddress = CPUFetchByte(C);
    ZPAddress += CPUGetX(C);

    WORD loadAddress = CPUReadWord(C, ZPAddress);

    return loadAddress;
}

WORD ADDR_INY(CPU C)
{
    BYTE ZPAddress = CPUFetchByte(C);
    ZPAddress += CPUGetY(C);

    WORD loadAddress = CPUReadWord(C, ZPAddress);

    return loadAddress;
}
