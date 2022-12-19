
// === EMULATOR RUN : File for running emulator (Quick Testbed) ===

#include "Emulator6502.h"
#include "stdio.h"
#include "stdlib.h"

#define ROM_FILE "./programs/binaries/testLoad.bin"
// #define ROM_FILE "./bin/main"

int main()
{
    // Instantiate Hardware
    Memory ROM = MemoryNew(0xFFFF);
    CPU cpu6502 = CPUNew();

    CPUSetVirtualMemory(cpu6502, ROM);

    CPUReset(cpu6502);
    MemoryWriteAll(ROM, NOP_IM);

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
    ClockSetMode(CPUGetClock(cpu6502), CM_FREQ_LIMIT);
    ClockSetCount(CPUGetClock(cpu6502), 21);
    CPUExecute(cpu6502);
    CPUDump(cpu6502);

    // Free Memory
    CPUFree(cpu6502);

    return 0;
}