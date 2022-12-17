#include "Eagle.h"
extern "C"
{
#include "Emulator6502.h"
#include "testDefinitions.h"
}

TEST(T_ADC_IM_ONE_PLUS_ONE)
{
    CPU C = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(C, ROM);

    CPUSetA(C, 0x01);

    MemoryWrite(ROM, PC_START, ADC_IM);
    MemoryWrite(ROM, PC_START + 1, 0x01);

    CPUExecute(C, ROM, 2);

    // Result = 2, C = 0, V = 0
    BYTE accumulator = CPUGetA(C);
    int C_FLAG = CPUGetStatusFlag(C, PS_C);
    int V_FLAG = CPUGetStatusFlag(C, PS_V);

    CHECK_EQ(accumulator, 0x02);
    CHECK_FALSE(C_FLAG);
    CHECK_FALSE(V_FLAG);

    CPUFree(C);
    MemoryFree(ROM);
}

TEST(T_ADC_IM_HAS_CARRY_OVERFLOW)
{
    CPU C = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(C, ROM);

    CPUSetA(C, 0b10000000);

    MemoryWrite(ROM, PC_START, ADC_IM);
    MemoryWrite(ROM, PC_START + 1, 0b11111111);

    CPUExecute(C, ROM, 2);

    // Result = 01111111, C = 0, V = 0
    BYTE accumulator = CPUGetA(C);
    int C_FLAG = CPUGetStatusFlag(C, PS_C);
    int V_FLAG = CPUGetStatusFlag(C, PS_V);

    CHECK_EQ(accumulator, 0b01111111);
    CHECK_TRUE(C_FLAG);
    CHECK_TRUE(V_FLAG);

    CPUFree(C);
    MemoryFree(ROM);
}

TEST(T_ADC_ZP)
{
    BYTE a = 0x34;
    BYTE b = 0x67;
    BYTE zpAddress = 0xAA;

    CPU C = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(C, ROM);

    CPUSetA(C, a);

    MemoryWrite(ROM, PC_START, ADC_ZP);
    MemoryWrite(ROM, PC_START + 1, zpAddress);

    MemoryWrite(ROM, zpAddress, b);

    CPUExecute(C, ROM, 3);

    // Result = 0x9B, C = 0, V = 0, N = 1
    BYTE accumulator = CPUGetA(C);
    int C_FLAG = CPUGetStatusFlag(C, PS_C);
    int V_FLAG = CPUGetStatusFlag(C, PS_V);
    int N_FLAG = CPUGetStatusFlag(C, PS_N);

    CHECK_EQ(accumulator, 0x9B);
    CHECK_FALSE(C_FLAG);
    CHECK_TRUE(V_FLAG);
    CHECK_TRUE(N_FLAG);

    CPUFree(C);
    MemoryFree(ROM);
}