#include "CPU6502.h"
#include "Memory.h"
#include "stdio.h"
#include "stdlib.h"
#include "Opcodes.h"
#include "fileIO.h"

#define ROM_FILE "./programs/binaries/testLoad.bin"

int main()
{
    // Instantiate Hardware
    Memory ROM = MemoryNew(0xFFFF);
    CPU cpu6502 = CPUNew();
    CPUReset(cpu6502, ROM);

    // Load Binary File into Virtual ROM
    MemoryLoadBinary(ROM, ROM_FILE);

    // View the memory (Debugging)
    MemoryHexDump(ROM, 0xFFFC, 0xFFFF);

    // Run the program (2 CPU Cycles)
    CPUExecute(cpu6502, ROM, 2);

    // Dump CPU to Console (Debugging)
    CPUDump(cpu6502);

    // Free Memory
    CPUFree(cpu6502);
    MemoryFree(ROM);

    return 0;
}