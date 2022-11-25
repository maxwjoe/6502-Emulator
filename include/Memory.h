#ifndef MEM_H
#define MEM_H

#include "common.h"

typedef struct memory *Memory;

// MemoryNew : Creates a new Memory Object (Capacity in Bytes)
Memory MemoryNew(int capacity);

// MemoryReset : Resets memory
int MemoryReset(Memory m);

// MemoryRead : Reads memory at a given index
BYTE MemoryRead(Memory m, WORD Addr);

// MemoryWrite : Writes to memory at a given address
int MemoryWrite(Memory m, WORD Addr, BYTE Data);

// MemoryFree : Frees all memory associated with RAM Object
int MemoryFree(Memory m);

#endif