#ifndef TEST_DEFINITIONS_H
#define TEST_DEFINITIONS_H

#define PC_START 0xFFFC // Program Counter Initial Value

// HW_SETUP : Initial Hardware setup boilerplate
#define HW_SETUP()                       \
    CPU C = CPUNew();                    \
    Memory M = MemoryNew(0xFFFF);        \
    Clock clkPtr = CPUGetClock(C);       \
    CPUSetVirtualMemory(C, M);           \
    ClockSetMode(clkPtr, CM_FREQ_LIMIT); \
    CPUReset(C);                         \
    MemoryReset(M)

// HW_PACKDOWN : Frees all test resources
#define HW_PACKDOWN() CPUFree(C)

// GET_ALL_FLAGS : Gets all CPU Flags
#define GET_ALL_FLAGS()                  \
    int F_N = CPUGetStatusFlag(C, PS_N); \
    int F_V = CPUGetStatusFlag(C, PS_V); \
    int F_Z = CPUGetStatusFlag(C, PS_Z); \
    int F_B = CPUGetStatusFlag(C, PS_B); \
    int F_C = CPUGetStatusFlag(C, PS_C); \
    int F_I = CPUGetStatusFlag(C, PS_I); \
    int F_D = CPUGetStatusFlag(C, PS_D)

// GET_ALL_REGISTERS : Gets all CPU Registers
#define GET_ALL_REGISTERS()  \
    BYTE R_A = CPUGetA(C);   \
    BYTE R_X = CPUGetX(C);   \
    BYTE R_Y = CPUGetY(C);   \
    BYTE R_PC = CPUGetPC(C); \
    BYTE R_SP = CPUGetSP(C)

// GET_INTERNALS() : Gets all flags AND registers from CPU
#define GET_INTERNALS() \
    GET_ALL_FLAGS();    \
    GET_ALL_REGISTERS()

// TEST_CYCLES : Sets CPU Cycles for test
#define TEST_CYCLES(CYCLES) ClockSetCount(clkPtr, CYCLES)

#endif