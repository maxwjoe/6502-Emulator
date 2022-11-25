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
    CPUSetX(cpu6502, 0x02);

    // Program the ROM
    MemoryWrite(ROM, 0xFFFC, JSR_AB);
    MemoryWrite(ROM, 0xFFFD, 0xAA);
    MemoryWrite(ROM, 0xFFFE, 0xAA);

    MemoryWrite(ROM, 0xAAAA, LDA_IM);
    MemoryWrite(ROM, 0xAAAB, 0x11);

    MemoryWrite(ROM, 0xAAAC, LDA_ZP);
    MemoryWrite(ROM, 0xAAAD, 0xBB);
    MemoryWrite(ROM, 0x00BB, 0x69);

    MemoryWrite(ROM, 0xAAAE, JSR_AB);
    MemoryWrite(ROM, 0xAAAF, 0xEE);
    MemoryWrite(ROM, 0xAAB0, 0xEE);

    MemoryWrite(ROM, 0xEEEE, LDA_ZPX);
    MemoryWrite(ROM, 0xEEEF, 0x12);
    MemoryWrite(ROM, 0x12 + CPUGetX(cpu6502), 0x56);

    // Run the program
    CPUExecute(cpu6502, ROM, 19);

    // Dump CPU to Console
    CPUDump(cpu6502);

    // Free Memory
    CPUFree(cpu6502);
    MemoryFree(ROM);

    return 0;
}