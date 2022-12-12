#ifndef CPU6502_H
#define CPU6502_H

#include "EmulatorTypes.h"
#include "Memory.h"

// cpu6502 : Struct to represent 6502 CPU
typedef struct cpu6502 *CPU;

// cpuOperation : Type definition of opcode function pointer
typedef void (*cpuOperation)(CPU, Memory, int *);

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

// CPUFetchByte : Fetches byte of data pointed to by program counter from memory, increments PC (1 Cpu Cycle)
BYTE CPUFetchByte(CPU C, Memory m, int *cycles);

// CPUFetchWord : Fetches word of data pointed to by pc from memory, increments pc (2 Cpu Cycles)
WORD CPUFetchWord(CPU C, Memory m, int *cycles);

// CPUExecute : Executes N clock cycles starting from Program Counter in memory
int CPUExecute(CPU C, Memory m, int cycles);

// CPUSetStatusFlag : Sets a CPU Status Flag (Returns 0 on fail)
int CPUSetStatusFlag(CPU C, int flagId, int flagValue);

// CPUGetStatusRegister : Returns the entire status register
BYTE CPUGetStatusRegister(CPU C);

// CPUSetStatusRegister : Sets the entire status register
int CPUSetStatusRegister(CPU C, BYTE val);

// CPUGetStatusFlag : Gets a CPU Status Flag (Returns -1 if not valid)
int CPUGetStatusFlag(CPU C, int flagId);

// CPUDump : Dumps CPU Struct to Console
void CPUDump(CPU C);

// CPUIncrementPC : Increments the program counter by a given value (Can be negative)
void CPUIncrementPC(CPU C, BYTE val);

// CPUIncrementSP : Increments the stack pointer by a given value (Can be negative)
void CPUIncrementSP(CPU C, BYTE val);

// CPUSetPC : Sets a value for the program counter
void CPUSetPC(CPU C, WORD val);

// CPUSetSP : Sets a value for the stack pointer
void CPUSetSP(CPU C, BYTE val);

// CPSettA : Sets a value for the accumulator
void CPUSetA(CPU C, BYTE val);

// CPUSetX : Sets a value in the X Register
void CPUSetX(CPU C, BYTE val);

// CPUSetY : Sets a value in the Y Register
void CPUSetY(CPU C, BYTE val);

// CPUGetPC : Returns the value of the program counter
WORD CPUGetPC(CPU C);

// CPUGetSP : Returns the value of the stack pointer
BYTE CPUGetSP(CPU C);

// CPUGetA : Returns the value of the accumulator
BYTE CPUGetA(CPU C);

// CPUGetX : Returns the value in the X Register
BYTE CPUGetX(CPU C);

// CPUGetY : Returns the value in the Y Register
BYTE CPUGetY(CPU C);

// CPUFree : Frees all memory associated with 6502
int CPUFree(CPU C);

#endif