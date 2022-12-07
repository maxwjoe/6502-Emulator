#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "Memory.h"
#include "CPU6502.h"

// === Status Functions ===

// LDA_SET_STATUS : Set CPU Status Registers based on accumulator from LDA Instruction
void LDA_SET_STATUS(CPU C);

// LDX_SET_STATUS : Set CPU Status Registers based on X Register from LDX Instruction
void LDX_SET_STATUS(CPU C);

// LDY_SET_STATUS : Set CPU Status Registers based on Y Register from LDX Instruction
void LDY_SET_STATUS(CPU C);

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

// --- JSR ---

// INS_JSR_AB : Executes JSR_AB
void INS_JSR_AB(CPU C, Memory m, int *cyclesPtr);

#endif