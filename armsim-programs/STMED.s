@The STMED (Store Multiple with Increment Before) instruction stores the values of registers R0 and R1 to memory, starting from the address held in register R13 (the stack pointer). After storing the values, the stack pointer (R13) is incremented to point to the next memory location.

.TEXT
MOV R0,#4
MOV R1,#5
STMED R13!,{R0,R1}
.END