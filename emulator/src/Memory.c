#include "Memory.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define STACK_PAGE_START 0x0100
#define STACK_PAGE_END 0x01FF

// --- Static Helpers ---

// s_MemoryBounds : Returns true if address within memory bounds
static int s_MemoryBounds(Memory m, WORD Addr);

typedef struct memory
{
    int capacity;
    int numBytes;
    BYTE *Data;

} *Memory;

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

    m->numBytes = m->capacity * sizeof(BYTE);

    return m;
}

int MemoryLoadBinary(Memory m, const char *filePath)
{
    if (m == NULL || filePath == NULL)
    {
        return 0;
    }

    FILE *fp = fopen(filePath, "rb");

    if (fp == NULL)
    {
        return 0;
    }

    fread(m->Data, m->numBytes, 1, fp);

    fclose(fp);
    return 1;
}

void MemoryHexDump(Memory m, WORD start, WORD end)
{
    if (m == NULL || !s_MemoryBounds(m, start) || !s_MemoryBounds(m, end))
    {
        return;
    }

    for (WORD i = start; i < end; i++)
    {
        printf("0x%04X : 0x%02X\n", i, m->Data[i]);
    }
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

BYTE MemoryReadFromStack(Memory m, BYTE Addr, int *cycles)
{
    return MemoryReadByte(m, STACK_PAGE_START + Addr, cycles);
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

int MemoryWriteToStack(Memory m, BYTE Addr, BYTE Data)
{
    if (m == NULL || !s_MemoryBounds(m, Addr))
    {
        return 0;
    }

    int hasWritten = MemoryWrite(m, STACK_PAGE_START + Addr, Data);
    return hasWritten;
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
