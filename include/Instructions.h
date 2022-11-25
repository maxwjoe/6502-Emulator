#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "Memory.h"
#include "CPU6502.h"

// === Status Functions ===

// LDA_SET_STATUS : Set CPU Status Registers based on accumulator from LDA Instruction
void LDA_SET_STATUS(CPU C);

// LDX_SET_STATUS : Set CPU Status Registers based on X Register from LDX Instruction
void LDX_SET_STATUS(CPU C);

// === Instruction Functions ===

// --- LDA ---

// INS_LDA_IM : Executes LDA_IM
void INS_LDA_IM(CPU C, Memory m, int *cyclesPtr);

// INS_LDA_ZP : Executes LDA_ZP
void INS_LDA_ZP(CPU C, Memory m, int *cyclesPtr);

// INS_LDA_ZPX : Executes LDA_ZPX
void INS_LDA_ZPX(CPU C, Memory m, int *cyclesPtr);

// INS_LDA_AB : Executes LDA_AB
void INS_LDA_AB(CPU C, Memory m, int *cyclesPtr);

// --- LDX ---

// INS_LDX_IM : Executes LDX_IM
void INS_LDX_IM(CPU C, Memory m, int *cyclesPtr);

// --- JSR ---

// INS_JSR_AB : Executes JSR_AB
void INS_JSR_AB(CPU C, Memory m, int *cyclesPtr);

#endif