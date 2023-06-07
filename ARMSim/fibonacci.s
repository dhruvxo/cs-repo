@@generate fibonacci series and store them in an array

.DATA
fibonacci: .WORD 0,0,0,0,0,0,0,0,0,0

.TEXT
MOV R0,#0
MOV R1,#1
LDR R2,=fibonacci

STR R0,[R2],#4
STR R1,[R2],#4
MOV R3,#8

CMP R3,#0
BEQ L1
ADD R2,R0,R1
STR R4,[R2],#4
MOV R0,R1
MOV R1,R4
SUBS R3,R3,#1
BEQ L2
L1: SWI 0X011