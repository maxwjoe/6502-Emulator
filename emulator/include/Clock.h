#ifndef CLOCK_H
#define CLOCK_H

// === CLOCK : ADT to handle CPU Clock operations ===

typedef struct clock *Clock;

// ClockNew : Creates a new clock object
Clock ClockNew();

// ClockSetSpeed : Sets the clock speed (Hz)
int ClockSetSpeed(Clock c, double freq);

// ClockGetPeriod : Gets the clock period
double ClockGetPeriod(Clock c);

// ClockSetStepMode : Sets the stepping mode
int ClockSetStepMode(Clock c, int isStepMode);

// ClockSetCount : Sets the cycle count
int ClockSetCount(Clock c, int count);

// ClockGetCount : Gets the cycle count
int ClockGetCount(Clock c);

// ClockTick : Ticks the clock
int ClockTick(Clock c);

// ClockFree : Frees a clock object
int ClockFree(Clock c);

#endif