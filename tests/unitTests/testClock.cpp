#include "Eagle.h"
extern "C"
{
#include "Emulator6502.h"
#include "testDefinitions.h"
}

TEST(T_CLOCK_CREATE)
{
    Clock C = ClockNew();

    CHECK_TRUE(C != NULL);

    ClockFree(C);
}

TEST(T_CLOCK_TICK)
{
    Clock C = ClockNew();

    ClockSetMode(C, CM_FREQ_LIMIT);
    ClockSetCount(C, 20);

    int cyclesStart = ClockGetCount(C);
    int tickSuccess = 1;

    while (ClockGetCount(C))
    {
        tickSuccess &= ClockTick(C);
    }

    int cyclesEnd = ClockGetCount(C);

    CHECK_EQ(cyclesStart, 20);
    CHECK_EQ(cyclesEnd, 0);
    CHECK_TRUE(tickSuccess);

    ClockFree(C);
}

TEST(T_CLOCK_PERIOD_ONE_SECOND_THREE_TICKS)
{
    Clock C = ClockNew();
    ClockSetMode(C, CM_FREQ_LIMIT);
    ClockSetCount(C, 3);
    ClockSetSpeed(C, 1.0);

    int period = ClockGetPeriod(C);

    while (ClockGetCount(C))
    {
        ClockTick(C);
    }

    CHECK_EQ(period, 1);

    ClockFree(C);
}