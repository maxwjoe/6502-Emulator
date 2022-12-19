#ifndef MEM_H
#define MEM_H

#include "EmulatorTypes.h"
#include "Clock.h"

typedef struct memory *Memory;

// MemoryNew : Creates a new Memory Object (Capacity in Bytes)
Memory MemoryNew(int capacity);

// MemoryReset : Resets memory
int MemoryReset(Memory m);

// MemoryLoadBinary : Loads ROM into memory
int MemoryLoadBinary(Memory m, const char *filePath);

// MemoryHexDump : Dumps memory range to console (Hex)
void MemoryHexDump(Memory m, WORD start, WORD end);

// MemoryReadByte : Reads memory at a given index (Byte) (Cost 1 CPU Cycle)
BYTE MemoryReadByte(Memory m, WORD Addr, Clock clk);

// MemoryReadFromStack : Reads a byte of memory from the stack (0x0100 - 0x01FF)
BYTE MemoryReadFromStack(Memory m, BYTE Addr, Clock clk);

// MemoryReadWord : Reads a word from memory at a given address (Note this costs 2 cycles)
WORD MemoryReadWord(Memory m, WORD Addr, Clock clk);

// MemoryWrite : Writes to memory at a given address (FIXME: Why is this not costing cycles????)
int MemoryWrite(Memory m, WORD Addr, BYTE Data);

// MemoryWriteAll : Writes to entire address space
int MemoryWriteAll(Memory m, BYTE Data);

// MemoryWriteToStack : Writes to stack memory (0x0100 - 0x01FF)
int MemoryWriteToStack(Memory m, BYTE Addr, BYTE Data);

// MemoryFree : Frees all memory associated with RAM Object
int MemoryFree(Memory m);

#endif