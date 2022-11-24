#ifndef CPU6502_H
#define CPU6502_H

#include "common.h"
#include "Memory.h"

// cpu6502 : Struct to represent 6502 CPU
typedef struct cpu6502 *CPU;

// PS_FLAGS : Enumeration for processor status flags
enum PS_FLAGS
{
    PS_C, // Carry
    PS_Z, // Zero
    PS_I, // Interrupt Disable
    PS_D, // Decimal Mode
    PS_B, // Break Command
    PS_V, // Overflow
    PS_N  // Negative
};

// --- CPU6502 ADT Functions ---

// CPUNew : Creates a new CPU6502 Object
CPU CPUNew();

// CPUReset : Resets the CPU
int CPUReset(CPU C, Memory m);

// CPUFetch : Fetches data pointed to by program counter from memory, increments PC
BYTE CPUFetch(CPU C, Memory m);

// CPUSetStatusFlag : Sets a CPU Status Flag (Returns 0 on fail)
int CPUSetStatusFlag(CPU C, int flagId, int flagValue);

// CPUGetStatusFlag : Gets a CPU Status Flag (Returns -1 if not valid)
int CPUGetStatusFlag(CPU C, int flagId);

// CPUDump : Dumps CPU Struct to Console
void CPUDump(CPU C);

// CPUFree : Frees all memory associated with 6502
int CPUFree(CPU C);

#endif