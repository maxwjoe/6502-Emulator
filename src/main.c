#include "CPU6502.h"
#include "Memory.h"
#include "stdio.h"
#include "stdlib.h"
#include "Opcodes.h"

int main()
{
    // Instantiate Hardware
    Memory ROM = MemoryNew(0xFFFF);
    CPU cpu6502 = CPUNew();

    // Setup CPU
    CPUReset(cpu6502, ROM);

    // Program the ROM
    MemoryWrite(ROM, 0xFFFC, JSR_AB);
    MemoryWrite(ROM, 0xFFFD, 0xAA);
    MemoryWrite(ROM, 0xFFFE, 0xAA);

    MemoryWrite(ROM, 0xAAAA, LDX_IM);
    MemoryWrite(ROM, 0xAAAB, 0x39);

    // Run the program
    CPUExecute(cpu6502, ROM, 8);

    // Dump CPU to Console
    CPUDump(cpu6502);

    // Free Memory
    CPUFree(cpu6502);
    MemoryFree(ROM);

    return 0;
}