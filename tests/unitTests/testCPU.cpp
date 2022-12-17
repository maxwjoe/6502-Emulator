#include "Eagle.h"
extern "C"
{
#include "Emulator6502.h"
}

TEST(CREATE_CPU)
{
    CPU C = CPUNew();

    CHECK_TRUE(C != NULL);

    CPUFree(C);
}

TEST(CREATE_MEMORY)
{
    Memory m = MemoryNew(0xFFFF);

    CHECK_TRUE(m != NULL);

    MemoryFree(m);
}

TEST(READ_WRITE_MEMORY)
{
    Memory m = MemoryNew(0xFFFF);

    MemoryWrite(m, 0xAAAA, 0xBB);
    int x = 5;
    BYTE b = MemoryReadByte(m, 0xAAAA, &x);

    CHECK_EQ(b, 0xBB);

    MemoryFree(m);
}