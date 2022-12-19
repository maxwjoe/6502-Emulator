
// === EMULATOR RUN : File for running emulator (Quick Testbed) ===

#include "Emulator6502.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define ROM_FILE "./programs/binaries/testLoad.bin"
// #define ROM_FILE "./bin/main"

int main()
{

    CPU C = CPUNew();
    Memory M = MemoryNew(0xFFFF);
    Clock clockPtr = CPUGetClock(C);

    ClockSetCount(clockPtr, 10);
    ClockSetSpeed(clockPtr, 3);
    ClockSetMode(clockPtr, CM_STEP_NO_LIMIT);

    while (ClockGetCount(clockPtr))
    {
        ClockTick(clockPtr);
        printf("TICK\n");
    }

    CPUFree(C);

    return 0;
}

// === OLD CODE ===

// // Instantiate Hardware
// Memory RAM = MemoryNew(0xFFFF);
// CPU cpu6502 = CPUNew();

// CPUSetEmulationMode(cpu6502, EM_VIRT_MEMORY);
// CPUSetVirtualMemory(cpu6502, RAM);

// CPUReset(cpu6502);
// MemoryWriteAll(RAM, NOP_IM);

// MemoryWrite(RAM, 0xFFFC, JSR_AB);
// MemoryWrite(RAM, 0xFFFD, 0x00);
// MemoryWrite(RAM, 0xFFFE, 0x80);

// MemoryWrite(RAM, 0x8000, LDA_IM);
// MemoryWrite(RAM, 0x8001, 0xFD);

// MemoryWrite(RAM, 0x8002, PHA_IMP);

// MemoryWrite(RAM, 0x8003, LDA_IM);
// MemoryWrite(RAM, 0x8004, 0x14);

// MemoryWrite(RAM, 0x8005, TAX_IMP);
// MemoryWrite(RAM, 0x8006, PLA_IMP);

// MemoryWrite(RAM, 0x8007, EOR_IM);
// MemoryWrite(RAM, 0x8008, 0xFF);

// // Run CPU
// ClockSetMode(CPUGetClock(cpu6502), CM_FREQ_LIMIT);
// ClockSetCount(CPUGetClock(cpu6502), 21);
// CPUExecute(cpu6502);
// CPUDump(cpu6502);

// // Free Memory
// CPUFree(cpu6502);