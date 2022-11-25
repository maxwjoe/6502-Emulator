#ifndef MEM_H
#define MEM_H

#include "common.h"

typedef struct memory *Memory;

// MemoryNew : Creates a new Memory Object (Capacity in Bytes)
Memory MemoryNew(int capacity);

// MemoryReset : Resets memory
int MemoryReset(Memory m);

// MemoryReadByte : Reads memory at a given index (Byte)
BYTE MemoryReadByte(Memory m, WORD Addr, int *cycles);

// MemoryReadWord : Reads a word from memory at a given address (Note this costs 2 cycles)
WORD MemoryReadWord(Memory m, WORD Addr, int *cycles);

// MemoryWrite : Writes to memory at a given address
int MemoryWrite(Memory m, WORD Addr, BYTE Data);

// MemoryFree : Frees all memory associated with RAM Object
int MemoryFree(Memory m);

#endif