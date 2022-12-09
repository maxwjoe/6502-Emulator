#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "Memory.h"
#include "CPU6502.h"
#include "stdio.h"

// === ABOUT INSTRUCTIONS ===

// INS_XXX_YYY : Where XXX is the Opcode, YYY is the addressing mode
// INS_XXX_YYY functions are the ones actually executed by the CPU for each opcode
// INS_XXX_XXX() is made up of an addressing function ADDR_XXX() and Operation function OPER_XXX()
// These two functions in combination give a specific version of each operation based on the addressing mode

// === Status Functions ===

// ACC_SET_STATUS : Set CPU Status Registers based on accumulator
void ACC_SET_STATUS(CPU C);

// XREG_SET_STATUS : Set CPU Status Registers based on X Register
void XREG_SET_STATUS(CPU C);

// YREG_ET_STATUS : Set CPU Status Registers based on Y Register
void YREG_ET_STATUS(CPU C);

// === INSTRUCTION DECLARATIONS ===

// --- LDA ---

// INS_LDA_IM : Executes LDA_IM
void INS_LDA_IM(CPU C, Memory m, int *cyclesPtr);

// INS_LDA_ZP : Executes LDA_ZP
void INS_LDA_ZP(CPU C, Memory m, int *cyclesPtr);

// INS_LDA_ZPX : Executes LDA_ZPX
void INS_LDA_ZPX(CPU C, Memory m, int *cyclesPtr);

// INS_LDA_AB : Executes LDA_AB
void INS_LDA_AB(CPU C, Memory m, int *cyclesPtr);

// INS_LDA_ABX : Executes LDA_ABX (TODO: Handle page cross)
void INS_LDA_ABX(CPU C, Memory m, int *cyclesPtr);

// INS_LDA_ABY : Executes LDA_ABY (TODO: Handle page cross)
void INS_LDA_ABY(CPU C, Memory m, int *cyclesPtr);

// INS_LDA_INX : Executes LDA_INX (TODO: Check CPU Cycles)
void INS_LDA_INX(CPU C, Memory m, int *cyclesPtr);

// INS_LDA_INY : Executes LDA_INY (TODO: Handle Page Cross)
void INS_LDA_INY(CPU C, Memory m, int *cyclesPtr);

// --- LDX ---

// INS_LDX_IM : Executes LDX_IM
void INS_LDX_IM(CPU C, Memory m, int *cyclesPtr);

// INS_LDX_ZP : Executes LDX_ZP
void INS_LDX_ZP(CPU C, Memory m, int *cyclesPtr);

// INS_LDX_ZPY : Executes LDX_ZPY
void INS_LDX_ZPY(CPU C, Memory m, int *cyclesPtr);

// INS_LDX_AB : Executes LDX_AB
void INS_LDX_AB(CPU C, Memory m, int *cyclesPtr);

// INS_LDX_ABY : Executes LDX_ABY (TODO: Need to handle page crossing)
void INS_LDX_ABY(CPU C, Memory m, int *cyclesPtr);

// --- LDY ---

// INS_LDY_IM : Executes LDY_IM
void INS_LDY_IM(CPU C, Memory m, int *cyclesPtr);

// INS_LDY_ZP : Executes LDY_ZP
void INS_LDY_ZP(CPU C, Memory m, int *cyclesPtr);

// INS_LDY_ZPX : Executes LDY_ZPX
void INS_LDY_ZPX(CPU C, Memory m, int *cyclesPtr);

// INS_LDY_AB : Executes LDY_AB
void INS_LDY_AB(CPU C, Memory m, int *cyclesPtr);

// INS_LDY_ABX : Executes LDY_ABX (TODO: Handle page crossing)
void INS_LDY_ABX(CPU C, Memory m, int *cyclesPtr);

// --- STA ---

// INS_STA_ZP : Executes STA_ZP
void INS_STA_ZP(CPU C, Memory m, int *cyclesPtr);

// INS_STA_ZPX : Executes STA_ZPX
void INS_STA_ZPX(CPU C, Memory m, int *cyclesPtr);

// INS_STA_AB : Executes STA_AB
void INS_STA_AB(CPU C, Memory m, int *cyclesPtr);

// INS_STA_ABX : Executes STA_ABX
void INS_STA_ABX(CPU C, Memory m, int *cyclesPtr);

// INS_STA_ABY : Executes STA_ABY
void INS_STA_ABY(CPU C, Memory m, int *cyclesPtr);

// INS_STA_INX : Executes STA_INX
void INS_STA_INX(CPU C, Memory m, int *cyclesPtr);

// INS_STA_INY : Executes STA_INY
void INS_STA_INY(CPU C, Memory m, int *cyclesPtr);

// --- STX ---

// INS_STX_ZP : Executes STX_ZP
void INS_STX_ZP(CPU C, Memory m, int *cyclesPtr);

// INS_STX_ZPY : Executes STX_ZPY
void INS_STX_ZPY(CPU C, Memory m, int *cyclesPtr);

// INS_STX_AB : Executes STX_AB
void INS_STX_AB(CPU C, Memory m, int *cyclesPtr);

// --- STY ---

// INS_STY_ZP : Executes STY_ZP
void INS_STY_ZP(CPU C, Memory m, int *cyclesPtr);

// INS_STY_ZPX : Executes STY_ZPX
void INS_STY_ZPX(CPU C, Memory m, int *cyclesPtr);

// INS_STY_AB : Executes STY_AB
void INS_STY_AB(CPU C, Memory m, int *cyclesPtr);

// --- TAX ---

// INS_TAX_IMP : Executes TAX_IMP
void INS_TAX_IMP(CPU C, Memory m, int *cyclesPtr);

// --- TAY ---

// INS_TAY_IMP : Executes TAY_IMP
void INS_TAY_IMP(CPU C, Memory m, int *cyclesPtr);

// --- TXA ---

// INS_TXA_IMP : Executes TXA_IMP
void INS_TXA_IMP(CPU C, Memory m, int *cyclesPtr);

// --- TYA ---

// INS_TYA_IMP : Executes TYA_IMP
void INS_TYA_IMP(CPU C, Memory m, int *cyclesPtr);

// --- TSX ---

// INS_TSX_IMP : Executes TSX_IMP
void INS_TSX_IMP(CPU C, Memory m, int *cyclesPtr);

// -- TXS ---

// INS_TXS_IMP : Executes TXS_IMP
void INS_TXS_IMP(CPU C, Memory m, int *cyclesPtr);

// --- PHA ---

// INS_PHA_IMP : Executes PHA_IMP
void INS_PHA_IMP(CPU C, Memory m, int *cyclesPtr);

// --- PHP ---

// INS_PHP_IMP : Executes PHP_IMP
void INS_PHP_IMP(CPU C, Memory m, int *cyclesPtr);

// --- PLA ---

// INS_PLA_IMP : Executes PLA_IMP
void INS_PLA_IMP(CPU C, Memory m, int *cyclesPtr);

// --- PLP ---

// INS_PLP_IMP : Executes PLP_IMP
void INS_PLP_IMP(CPU C, Memory m, int *cyclesPtr);

// --- AND ---

// INS_AND_IM : Executes AND_IM
void INS_AND_IM(CPU C, Memory m, int *cyclesPtr);

// INS_AND_ZP : Executes AND_ZP
void INS_AND_ZP(CPU C, Memory m, int *cyclesPtr);

// INS_AND_ZPX : Executes AND_ZPX
void INS_AND_ZPX(CPU C, Memory m, int *cyclesPtr);

// INS_AND_AB : Executes AND_AB
void INS_AND_AB(CPU C, Memory m, int *cyclesPtr);

// INS_AND_ABX : Executes AND_ABX
void INS_AND_ABX(CPU C, Memory m, int *cyclesPtr);

// INS_AND_ABY : Executes AND_ABY
void INS_AND_ABY(CPU C, Memory m, int *cyclesPtr);

// INS_AND_INX : Executes AND_INX
void INS_AND_INX(CPU C, Memory m, int *cyclesPtr);

// INS_AND_INY : Executes AND_INY
void INS_AND_INY(CPU C, Memory m, int *cyclesPtr);

// --- JSR ---

// INS_JSR_AB : Executes JSR_AB
void INS_JSR_AB(CPU C, Memory m, int *cyclesPtr);

#endif