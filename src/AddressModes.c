#include "AddressModes.h"

// --- Addressing Mode Definitions ---

BYTE ADDR_IM(CPU C, Memory m, int *cyclesPtr)
{
    return CPUFetchByte(C, m, cyclesPtr);
}

BYTE ADDR_ZP(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);
    return MemoryReadByte(m, ZPAddress, cyclesPtr);
}

BYTE ADDR_ZPX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);
    ZPAddress += CPUGetX(C);

    return MemoryReadByte(m, ZPAddress, cyclesPtr);
}

BYTE ADDR_ZPY(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);
    ZPAddress += CPUGetY(C);

    return MemoryReadByte(m, ZPAddress, cyclesPtr);
}

BYTE ADDR_AB(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    return MemoryReadByte(m, address, cyclesPtr);
}

BYTE ADDR_ABX(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    address += CPUGetX(C);

    return MemoryReadByte(m, address, cyclesPtr);
}

BYTE ADDR_ABY(CPU C, Memory m, int *cyclesPtr)
{
    WORD address = CPUFetchWord(C, m, cyclesPtr);
    address += CPUGetY(C);

    return MemoryReadByte(m, address, cyclesPtr);
}

BYTE ADDR_INX(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);
    ZPAddress += CPUGetX(C);

    WORD loadAddress = MemoryReadWord(m, ZPAddress, cyclesPtr);

    return MemoryReadByte(m, loadAddress, cyclesPtr);
}

BYTE ADDR_INY(CPU C, Memory m, int *cyclesPtr)
{
    BYTE ZPAddress = CPUFetchByte(C, m, cyclesPtr);
    ZPAddress += CPUGetY(C);

    WORD loadAddress = MemoryReadWord(m, ZPAddress, cyclesPtr);

    return MemoryReadByte(m, loadAddress, cyclesPtr);
}
