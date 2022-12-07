#include "CPU6502.h"
#include "Memory.h"
#include "stdio.h"
#include "stdlib.h"
#include "Opcodes.h"
#include "fileIO.h"

#define ROM_FILE "./programs/binaries/testLoad.bin"
// #define ROM_FILE "./bin/main"

int main()
{
    // Instantiate Hardware
    Memory ROM = MemoryNew(0xFFFF);
    CPU cpu6502 = CPUNew();
    CPUReset(cpu6502, ROM);

    // Load Binary File into Virtual ROM
    int loadStatus = MemoryLoadBinary(ROM, ROM_FILE);

    if (!loadStatus)
    {
        printf("ERROR : Failed to load binary into virtual ROM\n");
        exit(EXIT_FAILURE);
    }

    // Run CPU
    CPUExecute(cpu6502, ROM, 8);
    CPUDump(cpu6502);

    // Free Memory
    CPUFree(cpu6502);
    MemoryFree(ROM);

    return 0;
}