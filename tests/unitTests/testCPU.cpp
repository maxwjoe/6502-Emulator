extern "C"
{
#include "Emulator6502.h"
}

int T_CREATE_CPU()
{
    CPU c = CPUNew();

    int hasPassed = c != NULL;

    CPUFree(c);
    return hasPassed;
}

int T_CREATE_MEMORY()
{
    Memory m = MemoryNew(0xFFFF);

    int hasPassed = (m != NULL);

    MemoryFree(m);
    return hasPassed;
}

int T_READ_WRITE_MEMORY()
{
    Memory m = MemoryNew(0xFFFF);

    MemoryWrite(m, 0xAAAA, 0xBB);
    int x = 5;
    BYTE b = MemoryReadByte(m, 0xAAAA, &x);

    return b == 0xBB;
}