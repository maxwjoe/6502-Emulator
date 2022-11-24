#include "CPU6502.h"
#include "Memory.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
    Memory RAM = MemoryNew(1024);
    CPU cpu6502 = CPUNew();

    CPUDump(cpu6502);

    MemoryWrite(RAM, 0x01, 0xFF);

    printf("%hhu\n", CPUFetch(cpu6502, RAM));
    printf("%hhu\n", CPUFetch(cpu6502, RAM));

    CPUDump(cpu6502);

    CPUFree(cpu6502);
    MemoryFree(RAM);

    return 0;
}