#include "Memory.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

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

BYTE MemoryRead(Memory m, WORD Addr)
{
    if (m == NULL)
    {
        return 0;
    }

    if (Addr < 0 || Addr >= (WORD)m->capacity)
    {
        printf("Memory Read Error : Address out of bounds\n");
        return 0;
    }

    return m->Data[Addr];
}

int MemoryWrite(Memory m, WORD Addr, BYTE Data)
{
    if (m == NULL)
    {
        return 0;
    }

    if ((int)Addr < 0 || (int)Addr > m->capacity)
    {
        printf("\nInvalid Memory Write Operation\n");
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
