#include "CPU6502.h"

int main()
{
    CPU cpu6502 = CPUNew();

    CPUSetStatusFlag(cpu6502, PS_N, 1);
    CPUSetStatusFlag(cpu6502, PS_D, 1);
    CPUSetStatusFlag(cpu6502, PS_C, 1);

    CPUDump(cpu6502);

    CPUFree(cpu6502);

    return 0;
}