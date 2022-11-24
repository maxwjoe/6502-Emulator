#include "CPU6502.h"
#include "Memory.h"
#include "stdio.h"
#include "stdlib.h"
#include "Opcodes.h"

int main()
{
    Memory ROM = MemoryNew(0xFFFF);
    CPU cpu6502 = CPUNew();
    CPUReset(cpu6502, ROM);

    // Program the memory
    MemoryWrite(ROM, 0xFFFC, LDA_IM);
    MemoryWrite(ROM, 0xFFFD, 0x42);

    // Run the program
    CPUExecute(cpu6502, ROM, 3);

    CPUDump(cpu6502);

    CPUFree(cpu6502);
    MemoryFree(ROM);

    return 0;
}