#include "stdlib.h"
#include "stdio.h"
#include "../include/CPU6502.h"
#include "../include/Memory.h"
#include "testCommon.h"

// T_JSR : Tests jump to sub-routine
int T_JSR_AB();

// T_LDA_IM : Tests loading accumulator in immediate mode
int T_LDA_IM();

// T_LDA_ZP : Tests loading accumulator in zero page mode
int T_LDA_ZP();

// T_LDA_ZPX : Tests Loading accumulator in zero page x mode
int T_LDA_ZPX();

// --- Test Driver ---
int main()
{
    RUN_TEST(&T_JSR_AB, "JSR_AB");
    RUN_TEST(&T_LDA_IM, "LDA_IM");
    RUN_TEST(&T_LDA_ZP, "LDA_ZP");
    RUN_TEST(&T_LDA_ZPX, "LDA_ZPX");

    return 0;
}

// --- Test Definitions ---

int T_JSR_AB()
{

    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    MemoryWrite(ROM, 0xFFFC, JSR_AB);
    MemoryWrite(ROM, 0xFFFD, 0x00);
    MemoryWrite(ROM, 0xFFFE, 0x80);

    CPUExecute(c, ROM, 6);

    WORD PC = CPUGetPC(c);

    CPUFree(c);
    MemoryFree(ROM);

    return (PC == 0x8000);
}

int T_LDA_IM()
{

    BYTE targetValue = 0x11;

    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    MemoryWrite(ROM, 0xFFFC, LDA_IM);
    MemoryWrite(ROM, 0xFFFD, targetValue);

    CPUExecute(c, ROM, 2);

    BYTE accumulator = CPUGetA(c);

    CPUFree(c);
    MemoryFree(ROM);

    return (targetValue == accumulator);
}

int T_LDA_ZP()
{
    BYTE targetValue = 0x69;

    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    MemoryWrite(ROM, 0xFFFC, JSR_AB);
    MemoryWrite(ROM, 0xFFFD, 0x00);
    MemoryWrite(ROM, 0xFFFE, 0x80);

    MemoryWrite(ROM, 0x8000, LDA_ZP);
    MemoryWrite(ROM, 0x8001, 0x50);
    MemoryWrite(ROM, 0x0050, targetValue);

    CPUExecute(c, ROM, 9);

    BYTE accumulator = CPUGetA(c);

    CPUFree(c);
    MemoryFree(ROM);

    return (accumulator == targetValue);
}

int T_LDA_ZPX()
{
    BYTE targetValue = 0x69;
    BYTE xRegVal = 0x04;

    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    CPUSetX(c, xRegVal);

    MemoryWrite(ROM, 0xFFFC, JSR_AB);
    MemoryWrite(ROM, 0xFFFD, 0x00);
    MemoryWrite(ROM, 0xFFFE, 0x80);

    MemoryWrite(ROM, 0x8000, LDA_ZPX);
    MemoryWrite(ROM, 0x8001, 0x0A);

    MemoryWrite(ROM, 0x000A + xRegVal, targetValue);

    CPUExecute(c, ROM, 10);

    BYTE accumulator = CPUGetA(c);

    CPUFree(c);
    MemoryFree(ROM);

    return (accumulator == targetValue);
}
