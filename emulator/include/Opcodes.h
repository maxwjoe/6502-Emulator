#ifndef OPCODES_H
#define OPCODES_H

// --- File Format ---

// #define [OP_NAME] 0x[CODE] // Description (Addressing Mode, CPU Cycles) : FLAGS
// FLAGS : C = Complete, T = Tested , FLAG + * = Has Active TODO Item

// --- Opcode Definitions ---

// NOP : No Operation

#define NOP_IM 0xEA // No Operation (Immediate Mode, 2) :

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

// TSX : Transfer Stack Pointer to X Register

#define TSX_IMP 0xBA // Transfer Stack Pointer to X Register (Implied, 2) : C

// TXS : Transfer X Register to Stack Pointer

#define TXS_IMP 0x9A // Transfer X Register to Stack Pointer (Implied, 2) : C

// PHA : Push Accumulator

#define PHA_IMP 0x48 // Push Accumulator to Stack (Implied, 3) : C

// PHP : Push Processor Status

#define PHP_IMP 0x08 // Push Processor Status to Stack (Implied, 3) : C

// PLA : Pull Accumulator

#define PLA_IMP 0x68 // Pull value from stack and store in accumulator (Implied, 4) : C

// PLP : Pull Processor Status

#define PLP_IMP 0x28 // Pull value from stack and store as processor status (Implied, 4) : C

// AND : Logical AND on Accumulator

#define AND_IM 0x29  // Logical AND on Accumulator (Immediate Mode, 2) : C
#define AND_ZP 0x25  // Logical AND on Accumulator (Zero Page Mode, 3) : C
#define AND_ZPX 0x35 // Logical AND on Accumulator (Zero Page X Mode, 4) : C
#define AND_AB 0x2D  // Logical AND on Accumulator (Absolute Mode, 4) : C
#define AND_ABX 0x3D // Logical AND on Accumulator (Absolute X Mode, 4 + 1 if Page Cross) : C
#define AND_ABY 0x39 // Logical AND on Accumulator (Absolute Y Mode, 4 + 1 if Page Cross) : C
#define AND_INX 0x21 // Logical AND on Accumulator (Indirect X Mode, 6) : C
#define AND_INY 0x31 // Logical AND on Accumulator (Indirect Y Mode, 5 + 1 if Page Cross) : C

// EOR : Exclusive OR (XOR) on Accumulator

#define EOR_IM 0x49  // Logical XOR on Accumulator (Immediate Mode, 2) : C
#define EOR_ZP 0x45  // Logical XOR on Accumulator (Zero Page Mode, 3) : C
#define EOR_ZPX 0x55 // Logical XOR on Accumulator (Zero Page X Mode, 4) : C
#define EOR_AB 0x4D  // Logical XOR on Accumulator (Absolute Mode, 4) : C
#define EOR_ABX 0x5D // Logical XOR on Accumulator (Absolute X Mode, 4 + 1 if Page Cross) : C
#define EOR_ABY 0x59 // Logical XOR on Accumulator (Absolute Y Mode, 4 + 1 if Page Cross) : C
#define EOR_INX 0x41 // Logical XOR on Accumulator (Indirect X Mode, 6) : C
#define EOR_INY 0x51 // Logical XOR on Accumulator (Indirect Y Mode, 5 + 1 if Page Cross) : C

// ORA : Inclusive OR (OR) on Accumulator

#define ORA_IM 0x09  // Logical OR on Accumulator (Immediate Mode, 2) : C
#define ORA_ZP 0x05  // Logical OR on Accumulator (Zero Page Mode, 3) : C
#define ORA_ZPX 0x15 // Logical OR on Accumulator (Zero Page X Mode, 4) : C
#define ORA_AB 0x0D  // Logical OR on Accumulator (Absolute Mode, 4) : C
#define ORA_ABX 0x1D // Logical OR on Accumulator (Absolute X Mode, 4 + 1 if Page Cross) : C
#define ORA_ABY 0x19 // Logical OR on Accumulator (Absolute Y Mode, 4 + 1 if Page Cross) : C
#define ORA_INX 0x01 // Logical OR on Accumulator (Indirect X Mode, 6) : C
#define ORA_INY 0x11 // Logical OR on Accumulator (Indirect Y Mode, 5 + 1 if Page Cross) : C

// BIT : Bit Test

#define BIT_ZP 0x24 // Bit Test (Zero Page Mode, 3) : C
#define BIT_AB 0x2C // Bit Test (Absolute Mode, 4) : C

// ADC : Add With Carry

#define ADC_IM 0x69  // Add With Carry (Immediate Mode, 2) :
#define ADC_ZP 0x65  // Add With Carry (Zero Page Mode, 3) :
#define ADC_ZPX 0x75 // Add With Carry (Zero Page X Mode, 4) :
#define ADC_AB 0x6D  // Add With Carry (Absolute Mode, 4) :
#define ADC_ABX 0x7D // Add With Carry (Absolute X Mode, 4 + 1 if Page Cross) :
#define ADC_ABY 0x79 // Add With Carry (Absolute Y Mode, 4 + 1 if Page Cross) :
#define ADC_INX 0x61 // Add With Carry (Indirect X Mode, 6) :
#define ADC_INY 0x71 // Add With Carry (Indirect Y Mode, 5 + 1 if Page Cross) :

// SBC : Subtract With Carry

#define SBC_IM 0xE9  // Subtract With Carry (Immediate Mode, 2) :
#define SBC_ZP 0xE5  // Subtract With Carry (Zero Page Mode, 3) :
#define SBC_ZPX 0xF5 // Subtract With Carry (Zero Page X Mode, 4) :
#define SBC_AB 0xED  // Subtract With Carry (Absolute Mode, 4) :
#define SBC_ABX 0xFD // Subtract With Carry (Absolute X Mode, 4 + 1 if Page Cross) :
#define SBC_ABY 0xF9 // Subtract With Carry (Absolute Y Mode, 4 + 1 if Page Cross) :
#define SBC_INX 0xE1 // Subtract With Carry (Indirect X Mode, 6) :
#define SBC_INY 0xF1 // Subtract With Carry (Indirect Y Mode, 5 + 1 if Page Cross) :

// CMP : Compare Accumulator

#define CMP_IM 0xC9  // Compare Accumulator (Immediate Mode, 2) :
#define CMP_ZP 0xC5  // Compare Accumulator (Zero Page Mode, 3) :
#define CMP_ZPX 0xD5 // Compare Accumulator (Zero Page X Mode, 4) :
#define CMP_AB 0xCD  // Compare Accumulator (Absolute Mode, 4) :
#define CMP_ABX 0xDD // Compare Accumulator (Absolute X Mode, 4 + 1 if Page Cross) :
#define CMP_ABY 0xD9 // Compare Accumulator (Absolute Y Mode, 4 + 1 if Page Cross) :
#define CMP_INX 0xC1 // Compare Accumulator (Indirect X Mode, 6) :
#define CMP_INY 0xD1 // Compare Accumulator (Indirect Y Mode, 5 + 1 if Page Cross) :

// CPX : Compare X Register

#define CPX_IM 0xE0 // Compare X Register (Immediate Mode, 2) :
#define CPX_ZP 0xE4 // Compare X Register (Zero Page Mode, 3) :
#define CPX_AB 0xEC // Compare X Register (Absolute Mode, 4) :

// CPY : Compare Y Register

#define CPY_IM 0xC0 // Compare Y Register (Immediate Mode, 2) :
#define CPY_ZP 0xC4 // Compare Y Register (Zero Page Mode, 3) :
#define CPY_AB 0xCC // Compare Y Register (Absolute Mode, 4) :

// JSR : Jump to Subroutine

#define JSR_AB 0x20 // Jump to subroutine (Absolute Mode, 6) : C

#endif