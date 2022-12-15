// === TESTBED : File to run all unit tests ===

#include "Eagle.h"

// === INCLUDE TEST DEFINITIONS (Just as CPP files for now) ===

#include "./unitTests/testCPU.cpp"

// === COLLECTIONS ===

#define STRUCT_COL "Struct Memory"

int main()
{
    // === SETUP ===
    Eagle *e = new Eagle();
    e->SetVerbose(true);

    // === ADD TESTS ===

    // Test Structs
    e->AddTest(STRUCT_COL, "Create CPU", &T_CREATE_CPU);
    e->AddTest(STRUCT_COL, "Create Memory", &T_CREATE_MEMORY);
    e->AddTest(STRUCT_COL, "Write Memory", &T_WRITE_MEMORY);

    // Memory

    // JSR

    // LDA

    // LDX

    // LDY

    // === RUN AND CLEANUP ===
    e->RunAll();
    delete e;
}