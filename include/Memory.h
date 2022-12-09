#ifndef MEM_H
#define MEM_H

#include "common.h"

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
BYTE MemoryReadByte(Memory m, WORD Addr, int *cycles);

// MemoryReadFromStack : Reads a byte of memory from teh stack (0x0100 - 0x01FF)
BYTE MemoryReadFromStack(Memory m, BYTE Addr, int *cycles);

// MemoryReadWord : Reads a word from memory at a given address (Note this costs 2 cycles)
WORD MemoryReadWord(Memory m, WORD Addr, int *cycles);

// MemoryWrite : Writes to memory at a given address
int MemoryWrite(Memory m, WORD Addr, BYTE Data);

// MemoryWriteToStack : Writes to stack memory (0x0100 - 0x01FF)
int MemoryWriteToStack(Memory m, BYTE Addr, BYTE Data);

// MemoryFree : Frees all memory associated with RAM Object
int MemoryFree(Memory m);

#endif