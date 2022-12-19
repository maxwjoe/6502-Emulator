#include "Clock.h"
#include "stdlib.h"
#include "time.h"
#include "stdio.h"

typedef struct clock
{
    int cycles;    // How many cycles the clock should tick
    double period; // Delay between each tick
    int stepMode;  // Defines whether the CPU waits for step instruction
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
    c->stepMode = 0;

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

int ClockSetStepMode(Clock c, int isStepMode)
{
    if (c == NULL)
    {
        return 0;
    }

    c->stepMode = isStepMode;
}

int ClockTick(Clock c)
{
    if (c == NULL)
    {
        return 0;
    }

    if (c->stepMode)
    {
        // Await Step Instruction
        getchar();
    }
    else
    {
        // Timed Clock Ticks
        clock_t t_zero = clock() / CLOCKS_PER_SEC;

        while (clock() / CLOCKS_PER_SEC < t_zero + c->period)
            ;
    }
    printf("Ticked!\n");
    c->cycles--;
    return 1;
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
