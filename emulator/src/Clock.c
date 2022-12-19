#include "Clock.h"
#include "stdlib.h"
#include "time.h"
#include "stdio.h"

static void s_delay(double delaySeconds);

typedef struct clock
{
    int cycles;     // How many cycles the clock should tick
    double period;  // Delay between each tick
    int mode;       // Clock Mode
    int clock_edge; // Variable to store clock state
} *Clock;

Clock ClockNew()
{
    Clock c = (Clock)malloc(sizeof(struct clock));

    if (c == NULL)
    {
        return NULL;
    }

    c->cycles = 0;
    c->period = 0.0;
    c->mode = CM_FREQ_NO_LIMIT;

    return c;
}

int ClockSetSpeed(Clock c, double freq)
{
    if (c == NULL)
    {
        return 0;
    }

    if (freq <= 0)
    {
        c->period = 0;
        return 1;
    }

    c->period = 1.0 / freq;
    return 1;
}

double ClockGetPeriod(Clock c)
{
    if (c == NULL)
    {
        return 0.0;
    }

    return c->period;
}

int ClockSetCount(Clock c, int count)
{
    if (c == NULL)
    {
        return 0;
    }

    c->cycles = count;
    return 1;
}

int ClockGetCount(Clock c)
{
    if (c == NULL)
    {
        return 0;
    }

    return c->cycles;
}

int ClockSetMode(Clock c, int mode)
{
    if (c == NULL)
    {
        return 0;
    }

    c->mode = mode;
    return 1;
}

int ClockGetMode(Clock c)
{
    if (c == NULL)
    {
        return -1;
    }

    return c->mode;
}

int ClockTick(Clock c)
{
    if (c == NULL)
    {
        return 0;
    }

    switch (c->mode)
    {
    case CM_FREQ_LIMIT:
        s_delay(c->period);
        c->cycles--;
        break;
    case CM_FREQ_NO_LIMIT:
        s_delay(c->period);
        break;
    case CM_STEP_LIMIT:
        getchar();
        c->cycles--;
        break;
    case CM_STEP_NO_LIMIT:
        getchar();
        break;
    }

    return 1;
}

// NOTE: Not in use because requires multi-threading
int ClockSendPulse(Clock c)
{
    if (c == NULL)
    {
        return 0;
    }

    c->clock_edge = !c->clock_edge;
}

int ClockFree(Clock c)
{
    if (c == NULL)
    {
        return 0;
    }

    free(c);
    return 1;
}

static void s_delay(double delaySeconds)
{
    // Timed Clock Ticks
    clock_t t_zero = clock() / CLOCKS_PER_SEC;

    while (clock() / CLOCKS_PER_SEC < t_zero + delaySeconds)
        ;
}
