#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "CPU6502.h"
#include "Memory.h"

// === ABOUT OPERATIONS ===

// OPER_XXX : given an address, OPER functions carry out the logic of each opcode
// OPER_XXX functions are not directly executed by the CPU, they are called inside of INS_XXX_YYY

// === OPERATION DECLARATIONS ===

// OPER_LDA : Implements LDA Instruction
void OPER_LDA(CPU C, WORD address);

// OPER_LDX : Implements LDX Instruction
void OPER_LDX(CPU C, WORD address);

// OPER_LDY : Implements LDY Instruction
void OPER_LDY(CPU C, WORD address);

// OPER_STA : Implements STA Instruction
void OPER_STA(CPU C, WORD address);

// OPER_STX : Implements STX Instruction
void OPER_STX(CPU C, WORD address);

// OPER_STY : Implements STY Instruction
void OPER_STY(CPU C, WORD address);

// OPER_AND : Implements AND Instruction
void OPER_AND(CPU C, WORD address);

// OPER_EOR : Implements EOR Instruction
void OPER_EOR(CPU C, WORD address);

// OPER_ORA : Implements ORA Instruction
void OPER_ORA(CPU C, WORD address);

// OPER_BIT : Implements BIT Instruction
void OPER_BIT(CPU C, WORD address);

// OPER_ADC : Implements ADC Instruction
void OPER_ADC(CPU C, WORD address);

// OPER_SBC : Implements SBC Instruction
void OPER_SBC(CPU C, WORD address);

// === STATUS REGISTER DEFINITIONS ===

// STAT_Accumulator : Sets processor status based on Accumulator register
void STAT_Accumulator(CPU C);

// STAT_XRegister : Sets processor status based on X register
void STAT_XRegister(CPU C);

// STAT_YRegister : Sets processor status based on Y register
void STAT_YRegister(CPU C);

// STAT_ADC : Sets processor status based on Add with carry operation
void STAT_ADC(CPU C, WORD accumulator, WORD valueToAdd, WORD sum);

// === UNUSED (Immediate Mode only Instructions) ===

// // OPER_TAX : Implements TAX Instruction
// void OPER_TAX(CPU C, int *cyclesPtr, WORD address);

// // OPER_TAY : Implements TAY Instruction
// void OPER_TAY(CPU C, int *cyclesPtr, WORD address);

// // OPER_TXA : Implements TXA Instruction
// void OPER_TXA(CPU C, int *cyclesPtr, WORD address);

// // OPER_TYA : Implements TYA Instruction
// void OPER_TYA(CPU C, int *cyclesPtr, WORD address);

// // OPER_TSX : Implements TSX Instruction
// void OPER_TSX(CPU C, int *cyclesPtr, WORD address);

// // OPER_TXS : Implements TXS Instruction
// void OPER_TXS(CPU C, int *cyclesPtr, WORD address);

// // OPER_PHA : Implements PHA Instruction
// void OPER_PHA(CPU C, int *cyclesPtr, WORD address);

// // OPER_PHP : Implements PHP Instruction
// void OPER_PHP(CPU C, int *cyclesPtr, WORD address);

// // OPER_PLA : Implements PLA Instruction
// void OPER_PLA(CPU C, int *cyclesPtr, WORD address);

// // OPER_PLP : Implements PLP Instruction
// void OPER_PLP(CPU C, int *cyclesPtr, WORD address);

#endif