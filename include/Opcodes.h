#ifndef OPCODES_H
#define OPCODES_H

// Note : Defines Code : Description (Addr Mode, CPU Cycles) : Flags (C, T) => C = Complete,  T = Tested

// LDA : Load Accumulator

#define LDA_IM 0xA9  // Load Accumulator (Immediate Mode, 2) : C
#define LDA_ZP 0xA5  // Load Accumulator (Zero Page Mode, 3) : C
#define LDA_ZPX 0xB5 // Load Accumulator (Zero Page X Mode, 4) : C
#define LDA_AB 0xAD  // Load Accumulator (Absolute Mode, 4) : C
#define LDA_ABX 0xBD // Load Accumulator (Absolute X Mode, 4 + 1 if page cross)
#define LDA_ABY 0xB9 // Load Accumulator (Absolute Y Mode, 4 + 1 if page cross)
#define LDA_INX 0xA1 // Load Accumulator (Indirect X, 6)
#define LDA_INY 0xB1 // Load Accumulator (Indirect Y, 5 + 1 if page cross)

// LDX : Load X Register

#define LDX_IM 0xA2  // Load X Register (Immediate Mode, 2) : C
#define LDX_ZP 0xA6  // Load X Register (Zero Page Mode, 3) : C
#define LDX_ZPY 0xB6 // Load X Register (Zero Page Y Mode, 4) : C
#define LDX_AB 0xAE  // Load X Register (Absolute Mode, 4) : C
#define LDX_ABY 0xBE // Load X Register (Absolute Y Mode, 4 + 1 if page cross) : C*

// LDY : Load Y Register

#define LDY_IM 0xA0  // Load Y Register (Immediate Mode, 2) : C
#define LDY_ZP 0xA4  // Load Y Register (Zero Page Mode, 3) : C
#define LDY_ZPX 0xB4 // Load Y Register (Zero Page X Mode, 4) : C
#define LDY_AB 0xAC  // Load Y Register (Absolute Mode, 4) : C
#define LDY_ABX 0xBC // Load Y Register (Absolute X Mode, 4 + 1 if page cross) : C*

// JSR : Jump to Subroutine

#define JSR_AB 0x20 // Jump to subroutine (Absolute Mode) : C

#endif