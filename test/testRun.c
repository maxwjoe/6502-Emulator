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

// T_LDA_AB : Tests Loading the accumulator in absolute mode
int T_LDA_AB();

// T_LDA_ABX : Tests loading the accumulator in absolute mode with x reg offset
int T_LDA_ABX();

// T_LDA_ABY : Tests loading the accumulator in absolute mode with y reg offset
int T_LDA_ABY();

// T_LDA_INX : Tests loading the accumulator in indirect X mode
int T_LDA_INX();

// T_LDA_INY : Tets loading the accumulator in indirect Y mode
int T_LDA_INY();

// --- Test Driver ---
int main()
{
    RUN_TEST(&T_JSR_AB, "JSR_AB");
    RUN_TEST(&T_LDA_IM, "LDA_IM");
    RUN_TEST(&T_LDA_ZP, "LDA_ZP");
    RUN_TEST(&T_LDA_ZPX, "LDA_ZPX");
    RUN_TEST(&T_LDA_AB, "LDA_AB");
    RUN_TEST(&T_LDA_ABX, "LDA_ABX");
    RUN_TEST(&T_LDA_ABY, "LDA_ABY");
    RUN_TEST(&T_LDA_INX, "LDA_INX");
    RUN_TEST(&T_LDA_INY, "LDA_INY");
    printf("blah");

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
    int N_FLAG = CPUGetStatusFlag(c, PS_N);
    int Z_FLAG = CPUGetStatusFlag(c, PS_Z);

    CPUFree(c);
    MemoryFree(ROM);

    int hasPassed = (targetValue == accumulator) && !(N_FLAG || Z_FLAG);

    return hasPassed;
}

int T_LDA_ZP()
{
    BYTE targetValue = 0x8C;

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
    int N_FLAG = CPUGetStatusFlag(c, PS_N);
    int Z_FLAG = CPUGetStatusFlag(c, PS_Z);

    CPUFree(c);
    MemoryFree(ROM);

    int hasPassed = (accumulator == targetValue) && (N_FLAG == 1) && !Z_FLAG;

    return hasPassed;
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
    int Z_FLAG = CPUGetStatusFlag(c, PS_Z);
    int N_FLAG = CPUGetStatusFlag(c, PS_N);

    CPUFree(c);
    MemoryFree(ROM);

    int hasPassed = (accumulator == targetValue) && !(N_FLAG || Z_FLAG);

    return hasPassed;
}

int T_LDA_AB()
{

    BYTE targetValue = 0x00;

    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    MemoryWrite(ROM, 0xFFFC, JSR_AB);
    MemoryWrite(ROM, 0xFFFD, 0x00);
    MemoryWrite(ROM, 0xFFFE, 0xE0);

    MemoryWrite(ROM, 0xE000, LDA_AB);
    MemoryWrite(ROM, 0xE001, 0x00);
    MemoryWrite(ROM, 0xE002, 0x80);

    MemoryWrite(ROM, 0x8000, targetValue);

    CPUExecute(c, ROM, 10);

    BYTE accumulator = CPUGetA(c);
    int Z_FLAG = CPUGetStatusFlag(c, PS_Z);
    int N_FLAG = CPUGetStatusFlag(c, PS_N);

    CPUFree(c);
    MemoryFree(ROM);

    int hasPassed = (accumulator == targetValue) && (Z_FLAG == 1) && !N_FLAG;

    return hasPassed;
}

int T_LDA_ABX()
{
    BYTE targetValue = 0xB3;
    BYTE XRegisterValue = 0x10;

    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    CPUSetX(c, XRegisterValue);

    MemoryWrite(ROM, 0xFFFC, JSR_AB);
    MemoryWrite(ROM, 0xFFFD, 0x00);
    MemoryWrite(ROM, 0xFFFE, 0xAA);

    MemoryWrite(ROM, 0xAA00, LDA_ABX);
    MemoryWrite(ROM, 0xAA01, 0x00);
    MemoryWrite(ROM, 0xAA02, 0x80);

    MemoryWrite(ROM, 0x8000 + XRegisterValue, targetValue);

    CPUExecute(c, ROM, 10);

    BYTE accumulator = CPUGetA(c);
    int Z_FLAG = CPUGetStatusFlag(c, PS_Z);
    int N_FLAG = CPUGetStatusFlag(c, PS_N);

    CPUFree(c);
    MemoryFree(ROM);

    int hasPassed = (accumulator == targetValue) && (N_FLAG == 1) && !Z_FLAG;
    return hasPassed;
}

int T_LDA_ABY()
{
    BYTE targetValue = 0x63;
    BYTE YRegisterValue = 0x69;

    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    CPUSetY(c, YRegisterValue);

    MemoryWrite(ROM, 0xFFFC, JSR_AB);
    MemoryWrite(ROM, 0xFFFD, 0x00);
    MemoryWrite(ROM, 0xFFFE, 0xAA);

    MemoryWrite(ROM, 0xAA00, LDA_ABY);
    MemoryWrite(ROM, 0xAA01, 0x00);
    MemoryWrite(ROM, 0xAA02, 0x80);

    MemoryWrite(ROM, 0x8000 + YRegisterValue, targetValue);

    CPUExecute(c, ROM, 10);

    BYTE accumulator = CPUGetA(c);
    int Z_FLAG = CPUGetStatusFlag(c, PS_Z);
    int N_FLAG = CPUGetStatusFlag(c, PS_N);

    CPUFree(c);
    MemoryFree(ROM);

    int hasPassed = (accumulator == targetValue) && !(N_FLAG || Z_FLAG);
    return hasPassed;
}

int T_LDA_INX()
{
    BYTE targetValue = 0x45;
    BYTE XRegisterValue = 0x23;

    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    CPUSetX(c, XRegisterValue);

    MemoryWrite(ROM, 0xFFFC, JSR_AB);
    MemoryWrite(ROM, 0xFFFD, 0x00);
    MemoryWrite(ROM, 0xFFFE, 0xAA);

    MemoryWrite(ROM, 0xAA00, LDA_INX);
    MemoryWrite(ROM, 0xAA01, 0x50);

    MemoryWrite(ROM, 0x0050 + XRegisterValue, 0xBB);
    MemoryWrite(ROM, 0x51 + XRegisterValue, 0xBB);
    MemoryWrite(ROM, 0xBBBB, targetValue);

    // NOTE: Should be 12 CPU Cycles (Something wrong here)
    CPUExecute(c, ROM, 11);

    BYTE accumulator = CPUGetA(c);
    int Z_FLAG = CPUGetStatusFlag(c, PS_Z);
    int N_FLAG = CPUGetStatusFlag(c, PS_N);

    CPUFree(c);
    MemoryFree(ROM);

    int hasPassed = (accumulator == targetValue) && !(N_FLAG || Z_FLAG);
    return hasPassed;
}

int T_LDA_INY()
{
    BYTE targetValue = 0x45;
    BYTE YRegisterValue = 0x66;

    CPU c = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(c, ROM);

    CPUSetY(c, YRegisterValue);

    MemoryWrite(ROM, 0xFFFC, JSR_AB);
    MemoryWrite(ROM, 0xFFFD, 0x00);
    MemoryWrite(ROM, 0xFFFE, 0xAA);

    MemoryWrite(ROM, 0xAA00, LDA_INY);
    MemoryWrite(ROM, 0xAA01, 0x50);

    MemoryWrite(ROM, 0x0050 + YRegisterValue, 0xBB);
    MemoryWrite(ROM, 0x51 + YRegisterValue, 0xBB);
    MemoryWrite(ROM, 0xBBBB, targetValue);

    CPUExecute(c, ROM, 11);

    BYTE accumulator = CPUGetA(c);
    int Z_FLAG = CPUGetStatusFlag(c, PS_Z);
    int N_FLAG = CPUGetStatusFlag(c, PS_N);

    CPUFree(c);
    MemoryFree(ROM);

    int hasPassed = (accumulator == targetValue) && !(N_FLAG || Z_FLAG);
    return hasPassed;
}
