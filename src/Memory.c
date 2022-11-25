#include "Memory.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

// --- Static Helpers ---

// s_MemoryBounds : Returns true if address within memory bounds
static int s_MemoryBounds(Memory m, WORD Addr);

typedef struct memory
{
    int capacity;
    BYTE *Data;

} * Memory;

Memory MemoryNew(int capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }

    Memory m = (Memory)malloc(sizeof(struct memory));

    if (m == NULL)
    {
        return NULL;
    }

    m->capacity = capacity;
    m->Data = (BYTE *)calloc(m->capacity, sizeof(BYTE));

    if (m->Data == NULL)
    {
        free(m);
        return NULL;
    }

    return m;
}

BYTE MemoryReadByte(Memory m, WORD Addr, int *cycles)
{
    if (m == NULL || !s_MemoryBounds(m, Addr))
    {
        return 0;
    }

    if (cycles != NULL)
    {
        *cycles -= 1;
    }

    return m->Data[Addr];
}

WORD MemoryReadWord(Memory m, WORD Addr, int *cycles)
{
    if (m == NULL || !s_MemoryBounds(m, Addr))
    {
        return 0;
    }

    // Note : 6502 is Little Endian
    WORD data = m->Data[Addr];
    Addr++;
    data |= (m->Data[Addr] << 8);

    if (cycles != NULL)
    {
        *cycles -= 2;
    }

    return data;
}

int MemoryWrite(Memory m, WORD Addr, BYTE Data)
{
    if (m == NULL || !s_MemoryBounds(m, Addr))
    {
        return 0;
    }

    m->Data[Addr] = Data;
    return 1;
}

int MemoryReset(Memory m)
{
    if (m == NULL)
    {
        return 0;
    }

    memset(m->Data, 0, sizeof(BYTE) * m->capacity);
    return 1;
}

int MemoryFree(Memory m)
{
    if (m == NULL)
    {
        return 0;
    }

    free(m->Data);
    free(m);

    return 1;
}

// --- Static Helper Definitions ---

static int s_MemoryBounds(Memory m, WORD Addr)
{
    if ((int)Addr < 0 || (int)Addr > m->capacity)
    {
        printf("\nInvalid Memory Write Operation\n");
        return 0;
    }

    return 1;
}
