#include "Eagle.h"
extern "C"
{
#include "Emulator6502.h"
#include "testDefinitions.h"
}

TEST(T_CLOCK_TICK)
{
    Clock c = ClockNew();
    ClockSetCount(c, 3);
    ClockSetSpeed(c, 50);

    while (ClockGetCount(c))
    {
        ClockTick(c);
    }

    ClockFree(c);
}