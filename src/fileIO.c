#include "fileIO.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

void FIODumpCPU(CPU C, Memory m)
{
    if (C == NULL || m == NULL)
    {
        return;
    }

    FILE *fp = fopen("cpuDump.txt", "w");
    time_t tm;
    time(&tm);

    if (fp == NULL)
    {
        return;
    }

    fprintf(fp, "\n === CPU DUMP === \n\n");
    fprintf(fp, "\nTIMESTAMP : %s\n", ctime(&tm));

    fprintf(fp, "\n --- CPU INTERNALS ---\n\n");

    fprintf(fp, "Program Counter (PC) : 0x%X\n", CPUGetPC(C));
    fprintf(fp, "Stack Pointer (SP) : 0x%X\n", CPUGetSP(C));
    fprintf(fp, "Accumulator (A) : 0x%X\n", CPUGetA(C));
    fprintf(fp, "X Register (X) : 0x%X\n", CPUGetX(C));
    fprintf(fp, "Y Register (Y) : 0x%X\n", CPUGetY(C));

    fprintf(fp, "\n --- MEMORY --- \n\n");
    WORD pc = CPUGetPC(C);

    fprintf(fp, "Memory to left of PC : 0x%X\n", MemoryRead(m, pc - 1));
    fprintf(fp, "Memory at PC : 0x%X\n", MemoryRead(m, pc));
    fprintf(fp, "Memory to right of PC : 0x%X\n", MemoryRead(m, pc + 1));

    fprintf(fp, "\n === END CPU DUMP === \n\n");

    fclose(fp);
}
