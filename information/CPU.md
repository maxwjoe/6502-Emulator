# 6502 CPU Implementation Notes

### Structure Definition

> The CPU is represented in software by the C structure "cpu6502" which has been typedeffed  
> as a pointer to be CPU = cpu6502\*. The structure represents all the internals of the 6502.
>
> - PC : Program Counter (16 Bit)
> - SP : Stack Pointer (8 Bit)
> - A : Accumulator (8 Bit)
> - X : X Register (8 Bit)
> - Y : Y Register (8 Bit)
> - PS : Processor Status Register (8 Bit)
> - ops : Array of function pointers to hold CPU Instruction Logic (Length = 0xFF = 255)
