#include "Eagle.h"
extern "C"
{
#include "Emulator6502.h"
}

TEST(T_CREATE_CPU)
{
    CPU C = CPUNew();

    CHECK_TRUE(C != NULL);

    CPUFree(C);
}

TEST(T_CREATE_CPU_MEMORY)
{
    CPU C = CPUNew();
    Memory M = MemoryNew(0xFFFF);

    CPUSetEmulationMode(C, EM_VIRT_MEMORY);
    CPUSetVirtualMemory(C, M);

    Memory CPU_MEMORY = CPUGetVirtualMemory(C);

    CHECK_EQ(M, CPU_MEMORY);

    CPUFree(C);
}

TEST(T_READ_WRITE_CPU_MEMORY)
{
    WORD writeAddress = 0x5555;
    BYTE writtenData = 0x56;

    CPU C = CPUNew();
    Memory M = MemoryNew(0xFFFF);

    CPUSetEmulationMode(C, EM_VIRT_MEMORY);
    CPUSetVirtualMemory(C, M);

    int writeSuccess = CPUWriteByte(C, writeAddress, writtenData);

    CHECK_TRUE(writeSuccess);

    BYTE readData = CPUReadByte(C, writeAddress);
    CHECK_EQ(writtenData, readData);

    CPUFree(C);
}

TEST(T_EXECUTE_NOP_TEN_CYCLES)
{
    CPU C = CPUNew();
    Memory M = MemoryNew(0xFFFF);

    CPUSetEmulationMode(C, EM_VIRT_MEMORY);
    CPUSetVirtualMemory(C, M);
    ClockSetMode(CPUGetClock(C), CM_FREQ_LIMIT);

    // Write No Operations to all memory and set clock to tick ten times
    MemoryWriteAll(CPUGetVirtualMemory(C), 0xEA);
    ClockSetCount(CPUGetClock(C), 10);

    // Execute and record clock states
    int startCycles = ClockGetCount(CPUGetClock(C));
    int executionSuccess = CPUExecute(C);
    int endCycles = ClockGetCount(CPUGetClock(C));

    CHECK_TRUE(executionSuccess);
    CHECK_EQ(startCycles, 10);
    CHECK_EQ(endCycles, 0);

    CPUFree(C);
}

TEST(T_CPU_EXIT_ON_INVALID_OPERATION)
{
    CPU C = CPUNew();
    Memory M = MemoryNew(0xFFFF);

    CPUSetEmulationMode(C, EM_VIRT_MEMORY);
    CPUSetVirtualMemory(C, M);
    ClockSetMode(CPUGetClock(C), CM_FREQ_LIMIT);

    ClockSetCount(CPUGetClock(C), 50);

    int executionSuccess = CPUExecute(C);

    CHECK_FALSE(executionSuccess);

    CPUFree(C);
}

TEST(T_CPU_PROGRAM_COUNTER)
{
    CPU C = CPUNew();
    Memory M = MemoryNew(0xFFFF);

    CPUSetEmulationMode(C, EM_VIRT_MEMORY);
    CPUSetVirtualMemory(C, M);
    ClockSetMode(CPUGetClock(C), CM_FREQ_LIMIT);

    CPUReset(C);

    WORD PC_INITIAL = CPUGetPC(C);

    CPUFetchByte(C);

    WORD PC_AFTER_FETCH_BYTE = CPUGetPC(C);

    CPUReset(C);
    CPUFetchWord(C);

    WORD PC_AFTER_FETCH_WORD = CPUGetPC(C);

    CHECK_EQ(PC_INITIAL, 0xFFFC);
    CHECK_EQ(PC_AFTER_FETCH_BYTE, 0xFFFD);
    CHECK_EQ(PC_AFTER_FETCH_WORD, 0xFFFE);

    CPUFree(C);
}

TEST(T_CPU_READ_WRITE_STACK)
{
    BYTE stackAddress = 0x67;
    BYTE dataWritten = 0x33;

    CPU C = CPUNew();
    Memory M = MemoryNew(0xFFFF);

    CPUSetEmulationMode(C, EM_VIRT_MEMORY);
    CPUSetVirtualMemory(C, M);
    ClockSetMode(CPUGetClock(C), CM_FREQ_LIMIT);

    int writeSuccess = CPUWriteToStack(C, stackAddress, dataWritten);
    BYTE dataRead = CPUReadFromStack(C, stackAddress);

    CHECK_TRUE(writeSuccess);
    CHECK_EQ(dataWritten, dataRead);

    CPUFree(C);
}