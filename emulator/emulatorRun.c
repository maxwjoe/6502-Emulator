
// === EMULATOR RUN : File for running emulator (Quick Testbed) ===

#include "CPU6502.h"
#include "Memory.h"
#include "Opcodes.h"
#include "stdio.h"
#include "stdlib.h"

#define ROM_FILE "./programs/binaries/testLoad.bin"
// #define ROM_FILE "./bin/main"

int main()
{
    // Instantiate Hardware
    Memory ROM = MemoryNew(0xFFFF);
    CPU cpu6502 = CPUNew();
    CPUReset(cpu6502, ROM);

    MemoryWrite(ROM, 0xFFFC, JSR_AB);
    MemoryWrite(ROM, 0xFFFD, 0x00);
    MemoryWrite(ROM, 0xFFFE, 0x80);

    MemoryWrite(ROM, 0x8000, LDA_IM);
    MemoryWrite(ROM, 0x8001, 0xFD);

    MemoryWrite(ROM, 0x8002, PHA_IMP);

    MemoryWrite(ROM, 0x8003, LDA_IM);
    MemoryWrite(ROM, 0x8004, 0x14);

    MemoryWrite(ROM, 0x8005, TAX_IMP);
    MemoryWrite(ROM, 0x8006, PLA_IMP);

    MemoryWrite(ROM, 0x8007, EOR_IM);
    MemoryWrite(ROM, 0x8008, 0xFF);

    // Run CPU
    CPUExecute(cpu6502, ROM, 21);
    CPUDump(cpu6502);

    // Free Memory
    CPUFree(cpu6502);
    MemoryFree(ROM);

    return 0;
}