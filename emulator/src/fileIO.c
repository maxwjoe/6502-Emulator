#include "fileIO.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "string.h"

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

    fprintf(fp, "Program Counter (PC) : 0x%04X\n", CPUGetPC(C));
    fprintf(fp, "Stack Pointer (SP) : 0x%02X\n", CPUGetSP(C));
    fprintf(fp, "Accumulator (A) : 0x%02X\n", CPUGetA(C));
    fprintf(fp, "X Register (X) : 0x%02X\n", CPUGetX(C));
    fprintf(fp, "Y Register (Y) : 0x%02X\n", CPUGetY(C));

    fprintf(fp, "\n --- MEMORY --- \n\n");
    WORD pc = CPUGetPC(C);

    fprintf(fp, "Memory to left of PC : 0x%02X\n", MemoryReadByte(m, pc - 1, NULL));
    fprintf(fp, "Memory at PC : 0x%02X\n", MemoryReadByte(m, pc, NULL));
    fprintf(fp, "Memory to right of PC : 0x%02X\n", MemoryReadByte(m, pc + 1, NULL));

    fprintf(fp, "\n === END CPU DUMP === \n\n");

    fclose(fp);
}

int FIOReadBinary(const char *filePath, Memory m)
{
    if (filePath == NULL || m == NULL)
    {
        printf("Invalid binary file or memory parameters\n");
        return 0;
    }

    FILE *fp = fopen(filePath, "rb");

    if (fp == NULL)
    {
        printf("Failed to open binary file\n");
        return 0;
    }

    BYTE data[0xFFFF] = {0};

    fread(data, sizeof(data), 1, fp);

    fclose(fp);
    return 1;
}
