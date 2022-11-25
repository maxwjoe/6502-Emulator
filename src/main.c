#include "CPU6502.h"
#include "Memory.h"
#include "stdio.h"
#include "stdlib.h"
#include "Opcodes.h"
#include "fileIO.h"

int main()
{
    // Instantiate Hardware
    Memory ROM = MemoryNew(0xFFFF);
    CPU cpu6502 = CPUNew();

    int res = FIOReadBinary("a.bin", ROM);
    printf("RES = %d\n", res);
    // Setup CPU
    CPUReset(cpu6502, ROM);

    // Program the ROM
    MemoryWrite(ROM, 0xFFFC, JSR_AB);
    MemoryWrite(ROM, 0xFFFD, 0xAA);
    MemoryWrite(ROM, 0xFFFE, 0xAA);

    MemoryWrite(ROM, 0xAAAA, LDX_IM);
    MemoryWrite(ROM, 0xAAAB, 0x39);

    MemoryWrite(ROM, 0xAAAC, LDY_IM);
    MemoryWrite(ROM, 0xAAAD, 0x87);

    MemoryWrite(ROM, 0xAAAE, JSR_AB);
    MemoryWrite(ROM, 0xAAAF, 0x55);
    MemoryWrite(ROM, 0xAAB0, 0x55);

    MemoryWrite(ROM, 0x5555, LDA_ZPX);
    MemoryWrite(ROM, 0x5556, 0x33);
    MemoryWrite(ROM, 0x0033 + 0x39, 0x09);

    // Run the program
    CPUExecute(cpu6502, ROM, 20);

    // Dump CPU to Console
    // CPUDump(cpu6502);

    // Free Memory
    CPUFree(cpu6502);
    MemoryFree(ROM);

    return 0;
}