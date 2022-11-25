#ifndef FILEIO_H
#define FILEIO_h

#include "CPU6502.h"
#include "Memory.h"

// FIODumpCPU : Dumps CPU Contents to a file
void FIODumpCPU(CPU C, Memory m);

// FIOReadBinary : Reads a binary file and writes it to memory (Not working yet)
int FIOReadBinary(const char *filePath, Memory m);

#endif