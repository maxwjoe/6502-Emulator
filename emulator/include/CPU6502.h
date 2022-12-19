#ifndef CPU6502_H
#define CPU6502_H

#include "EmulatorTypes.h"
#include "Memory.h"

#define CPU_6502_DEFAULT_CLOCK_SPEED 0
#define STACK_PAGE_START 0x0100
#define STACK_PAGE_END 0x01FF

// cpu6502 : Struct to represent 6502 CPU
typedef struct cpu6502 *CPU;

// cpuOperation : Type definition of opcode function pointer
typedef void (*cpuOperation)(CPU);

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

// EMULATION_MODES : Enumeration for emulation modes
enum EMULATION_MODES
{
    EM_VIRT_MEMORY, // Emulation uses virtual memory (No IO Pins)
    EM_HARD_MEMORY  // Emulation uses real hardware (IO Pins)
};

// --- CPU6502 ADT Functions ---

// === General ===

// CPUNew : Creates a new CPU6502 Object
CPU CPUNew();

// CPUFree : Frees all memory associated with 6502 (Frees Virtual Memory and Clocks)
int CPUFree(CPU C);

// === Internals ===

// CPUReset : Resets the CPU
int CPUReset(CPU C);

// CPUSetStatusFlag : Sets a CPU Status Flag (Returns 0 on fail)
int CPUSetStatusFlag(CPU C, int flagId, int flagValue);

// CPUGetStatusRegister : Returns the entire status register
BYTE CPUGetStatusRegister(CPU C);

// CPUSetStatusRegister : Sets the entire status register
int CPUSetStatusRegister(CPU C, BYTE val);

// CPUGetStatusFlag : Gets a CPU Status Flag (Returns -1 if not valid)
int CPUGetStatusFlag(CPU C, int flagId);

// CPUGetClock : Returns a pointer to the clock
Clock CPUGetClock(CPU C);

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

// === Memory ===

// CPUFetchByte : Fetches data at PC, increments PC, costs 1 cycle
BYTE CPUFetchByte(CPU C);

// CPUFetchWord : Fetches data at PC, increments PC twice, costs 2 cycles
WORD CPUFetchWord(CPU C);

// CPUReadByte : Reads a byte of data at a given address, costs 1 cycle
BYTE CPUReadByte(CPU C, WORD address);

// CPUReadWord : Reads a word of data at a given address, costs 2 cycles
WORD CPUReadWord(CPU C, WORD address);

// CPUWriteByte : Writes a byte of data to the given location in memory
int CPUWriteByte(CPU C, WORD address, BYTE data);

// CPUReadFromStack : Reads from the stack
BYTE CPUReadFromStack(CPU C, BYTE stackAddress);

// CPUWriteToStack : Writes to the stack
int CPUWriteToStack(CPU C, BYTE stackAddress, BYTE data);

// CPUSetEmulationMode : Sets the emulation mode
int CPUSetEmulationMode(CPU C, int mode);

// CPUSetVirtualMemory : Sets virtual memory for CPU
int CPUSetVirtualMemory(CPU C, Memory m);

// CPUGetVirtualMemory : Returns a pointer to the virtual memory for CPU
Memory CPUGetVirtualMemory(CPU C);

// === Operations ===

// CPUExecute : Executes N clock cycles starting from Program Counter in memory
int CPUExecute(CPU C);

// CPUDump : Dumps CPU Struct to Console
void CPUDump(CPU C);

#endif