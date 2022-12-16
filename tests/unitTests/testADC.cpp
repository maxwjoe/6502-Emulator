extern "C"
{
#include "Emulator6502.h"
#include "testDefinitions.h"
}

int T_ADC_IM_ONE_PLUS_ONE()
{
    CPU C = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(C, ROM);

    CPUSetA(C, 0x01);

    MemoryWrite(ROM, PC_START, ADC_IM);
    MemoryWrite(ROM, PC_START + 1, 0x01);

    CPUExecute(C, ROM, 2);

    // Result = 2, C = 0, V = 0
    int hasPassed = (CPUGetA(C) == 0x02);
    hasPassed &= !CPUGetStatusFlag(C, PS_C);
    hasPassed &= !CPUGetStatusFlag(C, PS_V);

    CPUFree(C);
    MemoryFree(ROM);

    return hasPassed;
}

int T_ADC_IM_HAS_CARRY_AND_OVERFLOW()
{
    CPU C = CPUNew();
    Memory ROM = MemoryNew(0xFFFF);
    CPUReset(C, ROM);

    CPUSetA(C, 0b10000000);

    MemoryWrite(ROM, PC_START, ADC_IM);
    MemoryWrite(ROM, PC_START + 1, 0b11111111);

    CPUExecute(C, ROM, 2);

    // Result = 2, C = 0, V = 0
    int hasPassed = (CPUGetA(C) == 0b01111111);
    hasPassed &= CPUGetStatusFlag(C, PS_C);
    hasPassed &= CPUGetStatusFlag(C, PS_V);

    CPUFree(C);
    MemoryFree(ROM);

    return hasPassed;
}

int T_ADC_ZP()
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

    // Result = 0x9E, C = 0, V = 0, N = 1
    int hasPassed = (CPUGetA(C) == (a + b));
    hasPassed &= !CPUGetStatusFlag(C, PS_C);
    hasPassed &= CPUGetStatusFlag(C, PS_V);
    hasPassed &= CPUGetStatusFlag(C, PS_N);

    CPUFree(C);
    MemoryFree(ROM);

    return hasPassed;
}