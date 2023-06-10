@@Write an assembly language program using arm instruction to complete the following using sub-routines: factorial, GCD

.DATA
MOV R0,#12
MOV R1,#1
BL FACTORIAL
SWI 0X011

FACTORIAL:
MUL R1,R0,R1
SUBS R0,R0,#1
BNE FACTORIAL