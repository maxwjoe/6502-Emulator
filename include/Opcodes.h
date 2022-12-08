#ifndef OPCODES_H
#define OPCODES_H

// --- File Format ---

// #define [OP_NAME] 0x[CODE] // Description (Addressing Mode, CPU Cycles) : FLAGS
// FLAGS : C = Complete, T = Tested , FLAG + * = Has Active TODO Item

// --- Opcode Definitions ---

// LDA : Load Accumulator

#define LDA_IM 0xA9  // Load Accumulator (Immediate Mode, 2) : C, T
#define LDA_ZP 0xA5  // Load Accumulator (Zero Page Mode, 3) : C, T
#define LDA_ZPX 0xB5 // Load Accumulator (Zero Page X Mode, 4) : C, T
#define LDA_AB 0xAD  // Load Accumulator (Absolute Mode, 4) : C, T
#define LDA_ABX 0xBD // Load Accumulator (Absolute X Mode, 4 + 1 if page cross) : C*, T*
#define LDA_ABY 0xB9 // Load Accumulator (Absolute Y Mode, 4 + 1 if page cross) : C*, T*
#define LDA_INX 0xA1 // Load Accumulator (Indirect X, 6) : C*, T*
#define LDA_INY 0xB1 // Load Accumulator (Indirect Y, 5 + 1 if page cross) : C*, T*

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

// STA : Store Accumulator

#define STA_ZP 0x85  // Store Accumulator (Zero Page Mode, 3) : C
#define STA_ZPX 0x95 // Store Accumulator (Zero Page X Mode, 4) : C
#define STA_AB 0x8D  // Store Accumulator (Absolute Mode, 4) : C
#define STA_ABX 0x9D // Store Accumulator (Absolute X Mode, 5) : C
#define STA_ABY 0x99 // Store Accumulator (Absolute Y Mode, 5) : C
#define STA_INX 0x81 // Store Accumulator (Indirect X Mode, 6) : C
#define STA_INY 0x91 // Store Accumulator (Indirect Y Mode, 6) : C

// STX : Store X Register

#define STX_ZP 0x86  // Store X Register (Zero Page Mode, 3) : C
#define STX_ZPY 0x96 // Store X Register (Zero Page Y Mode, 4) : C
#define STX_AB 0x8E  // Store X Register (Absolute Mode, 4) : C

// STY : Store Y Register

#define STY_ZP 0x84  // Store Y Register (Zero Page Mode, 3) : C
#define STY_ZPX 0x94 // Store Y Register (Zero Page Y Mode, 4) : C
#define STY_AB 0x8C  // Store Y Register (Absolute Mode, 4) : C

// TAX : Transfer Accumulator to X Register

#define TAX_IMP 0xAA // Transfer Accumulator to X Register (Implied, 2) : C

// TAY : Transfer Accumulator to Y Register

#define TAY_IMP 0xA8 // Transfer Accumulator to Y Register (Implied, 2) : C

// TXA : Transfer X Register to Accumulator

#define TXA_IMP 0x8A // Transfer X Register to Accumulator (Implied, 2) : C

// TYA : Transfer Y Register to Accumulator

#define TYA_IMP 0x98 // Transfer Y Register to Accumulator (Implied, 2) : C

// JSR : Jump to Subroutine

#define JSR_AB 0x20 // Jump to subroutine (Absolute Mode, 6) : C

#endif