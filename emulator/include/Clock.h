#ifndef CLOCK_H
#define CLOCK_H

// === CLOCK : ADT to handle CPU Clock operations ===

typedef struct clock *Clock;

enum CLOCK_MODE
{
    CM_FREQ_LIMIT,    // Clock ticks at given frequency for n clock cycles
    CM_STEP_LIMIT,    // Clock ticks on keypress for n clock cycles
    CM_FREQ_NO_LIMIT, // Clock ticks at given frequency forever
    CM_STEP_NO_LIMIT  // Clock ticks on keypress forever
};

// ClockNew : Creates a new clock object
Clock ClockNew();

// ClockSetSpeed : Sets the clock speed (Hz)
int ClockSetSpeed(Clock c, double freq);

// ClockGetPeriod : Gets the clock period
double ClockGetPeriod(Clock c);

// ClockSetMode : Sets the stepping mode
int ClockSetMode(Clock c, int mode);

// ClockGetMode : Gets the stepping mode
int ClockGetMode(Clock c);

// ClockSetCount : Sets the cycle count
int ClockSetCount(Clock c, int count);

// ClockGetCount : Gets the cycle count
int ClockGetCount(Clock c);

// ClockTick : Ticks the clock
int ClockTick(Clock c);

// ClockSendPulse : Changes clock state for tick function
int ClockSendPulse(Clock c);

// ClockFree : Frees a clock object
int ClockFree(Clock c);

#endif