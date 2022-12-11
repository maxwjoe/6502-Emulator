#ifndef ADDRESS_MODES_H
#define ADDRESS_MODES_H

#include "Memory.h"
#include "CPU6502.h"

// ADDR_XXX : Functions return address to operate on in memory

// --- XXX : Available addressing modes on 6502 ---

// IMP : Implied Mode (Register to Register operations, Not included here as it does not have address logic)
// IM : Immediate Mode (Uses value at program counter for operations, Not included here as it does have address logic)
// ZP : Zero Page Mode (Loads the byte at program counter [0xXX], 16-bit address 0x00XX on zero page)
// ZPX : Same as ZP Mode but offset by X Register value
// ZPY : Same as ZP Mode but offset by Y Register value
// AB : Absolute Mode (Loads a 16-bit word from program counter as memory address)
// ABX : Same as AB but offset by X Register value
// ABY : Same as AB but offset by Y Register value
// INX : Indirect X (Loads ZP Address, offsets by X register, reads at this address and uses data as operation address)
// INY : Indirect Y (Loads ZP Address, offsets by Y register, reads at this address and uses data as operation address)

// --- Addressing Mode Declarations ---

// ADDR_ZP : Zero Page Addressing Mode (1 CPU Cycle)
BYTE ADDR_ZP(CPU C, Memory m, int *cyclesPtr);

// ADDR_ZPX : Zero Page X Addressing Mode (2 CPU Cycles)
BYTE ADDR_ZPX(CPU C, Memory m, int *cyclesPtr);

// ADDR_ZPY : Zero Page Y Addressing Mode (2 CPU Cycles)
BYTE ADDR_ZPY(CPU C, Memory m, int *cyclesPtr);

// ADDR_AB : Absolute Addressing Mode (2 CPU Cycles)
WORD ADDR_AB(CPU C, Memory m, int *cyclesPtr);

// ADDR_ABX : Absolute X Addressing Mode (2 CPU Cycles)
WORD ADDR_ABX(CPU C, Memory m, int *cyclesPtr);

// ADDR_ABY : Absolute Y Addressing Mode (2 CPU Cycles)
WORD ADDR_ABY(CPU C, Memory m, int *cyclesPtr);

// ADDR_INX : Indirect X Addressing Mode (3 CPU Cycles)
WORD ADDR_INX(CPU C, Memory m, int *cyclesPtr);

// ADDR_INY : Indirect Y Addressing Mode (3 CPU Cycles)
WORD ADDR_INY(CPU C, Memory m, int *cyclesPtr);

#endif