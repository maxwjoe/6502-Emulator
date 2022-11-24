#include "CPU6502.h"
#include "Memory.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
    Memory RAM = MemoryNew(1024);
    CPU cpu6502 = CPUNew();

    BYTE addr = 0x01;
    BYTE data = 0x11;
    int cycles = 5;
    for (int i = 0; i < cycles; i++)
    {
        MemoryWrite(RAM, addr, data);
        addr++;
        data += 5;
    }

    CPUExecute(cpu6502, RAM, cycles + 5);

    CPUFree(cpu6502);
    MemoryFree(RAM);

    return 0;
}