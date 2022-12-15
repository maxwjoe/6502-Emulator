// === TESTBED : File to run all unit tests ===

#include "Eagle.h"

// === INCLUDE TEST DEFINITIONS (Just as CPP files for now) ===

#include "./unitTests/testCPU.cpp"
#include "./unitTests/testLDA.cpp"

// === COLLECTIONS ===

#define STRUCT_COL "STRUCTS"
#define LDA_COL "LDA"

int main()
{
    // === SETUP ===
    Eagle *e = new Eagle();
    e->SetVerbose(true);

    // === ADD TESTS ===

    // Test Structs
    e->AddTest(STRUCT_COL, "CPU_CREATE", &T_CREATE_CPU);
    e->AddTest(STRUCT_COL, "MEMORY_CREATE", &T_CREATE_MEMORY);
    e->AddTest(STRUCT_COL, "MEMORY_READ_WRITE", &T_READ_WRITE_MEMORY);

    // JSR

    // LDA
    e->AddTest(LDA_COL, "LDA_IM", &T_LDA_IM);
    e->AddTest(LDA_COL, "LDA_ZP", &T_LDA_ZP);
    e->AddTest(LDA_COL, "LDA_ZPX", &T_LDA_ZPX);
    e->AddTest(LDA_COL, "LDA_AB", &T_LDA_AB);

    // LDX

    // LDY

    // === RUN AND CLEANUP ===
    e->RunAll();
    delete e;
}