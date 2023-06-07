@@Write a program to perform convolution using MUL and MLA instruction (addition of multiplication of respective numbers of location A and B)

.DATA
A: .WORD 1,2,3,4,5
B: .WORD 1,2,3,4,5

.TEXT
LDR R0,=A
LDR R1,=B

MOV R6,#5
MOV R5,#0

L1:LDR R2,[R0],#4
LDR R3,[R1],#4
MLA R5,R2,R3,R5
SUB R6,R6,#1
CMP R6,#0
BNE L1

SWI 0X011