#include "AddressModes.h"

// --- Addressing Mode Definitions ---

BYTE ADDR_ZP(CPU C, Memory m, int *cyclesPtr)
{
    return CPUFetchByte(C, m, cyclesPtr);
}

BYTE ADDR_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);
    ZPAddress += CPUGetX(C);
    *cyclesPtr = *cyclesPtr - 1;
    return ZPAddress;
}

BYTE ADDR_ZPY(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);
    ZPAddress += CPUGetY(C);
    *cyclesPtr = *cyclesPtr - 1;
    return ZPAddress;
}

WORD ADDR_AB(CPU C, Memory m, int *cyclesPtr)
{
    return CPUFetchWord(C, m, cyclesPtr);
}

WORD ADDR_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    address += CPUGetX(C);

    return address;
}

WORD ADDR_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    address += CPUGetY(C);

    return address;
}

WORD ADDR_INX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);
    ZPAddress += CPUGetX(C);

    WORD loadAddress = MemoryReadWord(m, ZPAddress, cyclesPtr);

    return loadAddress;
}

WORD ADDR_INY(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);
    ZPAddress += CPUGetY(C);

    WORD loadAddress = MemoryReadWord(m, ZPAddress, cyclesPtr);

    return loadAddress;
}
