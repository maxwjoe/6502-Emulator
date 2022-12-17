// === TESTBED : File to run all unit tests ===

#include "Eagle.h"
#include "./unitTests/testCPU.cpp"
#include "./unitTests/testLDA.cpp"
#include "./unitTests/testLDX.cpp"
#include "./unitTests/testADC.cpp"

int main()
{

    EAGLE_INIT(true);

    ADD_TEST(STRUCTS, CREATE_CPU);
    ADD_TEST(STRUCTS, CREATE_MEMORY);
    ADD_TEST(STRUCTS, READ_WRITE_MEMORY);

    ADD_TEST(LDA, T_LDA_IM);
    ADD_TEST(LDA, T_LDA_ZP);
    ADD_TEST(LDA, T_LDA_ZPX);
    ADD_TEST(LDA, T_LDA_AB);
    ADD_TEST(LDA, T_LDA_ABY);
    ADD_TEST(LDA, T_LDA_ABX);
    ADD_TEST(LDA, T_LDA_INX);
    ADD_TEST(LDA, T_LDA_INY);
    ADD_TEST(LDA, T_LDA_N_FLAG);
    ADD_TEST(LDA, T_LDA_Z_FLAG);

    ADD_TEST(LDX, T_LDX_IM);
    ADD_TEST(LDX, T_LDX_ZP);
    ADD_TEST(LDX, T_LDX_ZPY);
    ADD_TEST(LDX, T_LDX_AB);
    ADD_TEST(LDX, T_LDX_ABY);

    ADD_TEST(ADC, T_ADC_IM_ONE_PLUS_ONE);
    ADD_TEST(ADC, T_ADC_IM_HAS_CARRY_OVERFLOW);
    ADD_TEST(ADC, T_ADC_ZP);

    RUN_ALL_TESTS();
    EAGLE_EXIT();
}