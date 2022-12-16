// === TESTBED : File to run all unit tests ===

#include "Eagle.h"

// === INCLUDE TEST DEFINITIONS (Just as CPP files for now) ===

#include "./unitTests/testCPU.cpp"
#include "./unitTests/testLDA.cpp"
#include "./unitTests/testLDX.cpp"
#include "./unitTests/testADC.cpp"

// === COLLECTIONS ===

#define STRUCT_COL "STRUCTS"
#define LDA_COL "LDA"
#define LDX_COL "LDX"
#define ADC_COL "ADC"

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
    e->AddTest(LDA_COL, "LDA_ABX", &T_LDA_ABX);
    e->AddTest(LDA_COL, "LDA_ABY", &T_LDA_ABY);
    e->AddTest(LDA_COL, "LDA_INX", &T_LDA_INX);
    e->AddTest(LDA_COL, "LDA_INY", &T_LDA_INY);
    e->AddTest(LDA_COL, "LDA_PS_N", &T_LDA_N_FLAG);
    e->AddTest(LDA_COL, "LDA_PS_Z", &T_LDA_Z_FLAG);

    // LDX
    e->AddTest(LDX_COL, "LDX_IM", &T_LDX_IM);
    e->AddTest(LDX_COL, "LDX_ZP", &T_LDX_ZP);
    e->AddTest(LDX_COL, "LDX_ZPY", &T_LDX_ZPY);
    e->AddTest(LDX_COL, "LDX_AB", &T_LDX_AB);
    e->AddTest(LDX_COL, "LDX_ABY", &T_LDX_ABY);

    // LDY

    // ADC
    e->AddTest(ADC_COL, "ADC_IM_ONE_PLUS_ONE", &T_ADC_IM_ONE_PLUS_ONE);
    e->AddTest(ADC_COL, "ADC_IM_ONE_HAS_CARRY_AND_OVERFLOW", &T_ADC_IM_HAS_CARRY_AND_OVERFLOW);
    e->AddTest(ADC_COL, "ADC_ZP", &T_ADC_ZP);

    // === RUN AND CLEANUP ===
    e->RunAll();
    delete e;
}