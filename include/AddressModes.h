#ifndef ADDRESS_MODES_H
#define ADDRESS_MODES_H

#include "Memory.h"
#include "CPU6502.h"

// ADDR_XXX : Functions return value to operate on in INS_XXX_XXX Functions
// Handles the various addressing modes available on the 6502

// ADDR_IM : Immediate Addressing Mode
BYTE ADDR_IM(CPU C, Memory m, int *cyclesPtr);

// ADDR_ZP : Zero Page Addressing Mode
BYTE ADDR_ZP(CPU C, Memory m, int *cyclesPtr);

// ADDR_ZPX : Zero Page X Addressing Mode
BYTE ADDR_ZPX(CPU C, Memory m, int *cyclesPtr);

// ADDR_AB : Absolute Addressing Mode
BYTE ADDR_AB(CPU C, Memory m, int *cyclesPtr);

// ADDR_ABX : Absolute X Addressing Mode
BYTE ADDR_ABX(CPU C, Memory m, int *cyclesPtr);

// ADDR_ABY : Absolute Y Addressing Mode
BYTE ADDR_ABY(CPU C, Memory m, int *cyclesPtr);

// ADDR_INX : Indirect X Addressing Mode
BYTE ADDR_INX(CPU C, Memory m, int *cyclesPtr);

// ADDR_INY : Indirect Y Addressing Mode
BYTE ADDR_INY(CPU C, Memory m, int *cyclesPtr);

#endif