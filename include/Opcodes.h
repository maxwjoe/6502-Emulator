#ifndef OPCODES_H
#define OPCODES_H

#include "Memory.h"
#include "CPU6502.h"

// Code Definitions
#define LDA_IM 0xA9  // Load Accumulator (Immediate Mode)
#define LDA_ZP 0xA5  // Load Accumulator (Zero Page Mode)
#define LDA_ZPX 0xB5 // Load Accumulator (Zero Page X Mode)

#define JSR_AB 0x20 // Jump to subroutine (Absolute Mode)

#endif