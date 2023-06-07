@@Write a program to perform convolution using MUL and MLA instruction (addition of multiplication of respective numbers of location A and B)

.DATA
A: .WORD 1,2,3,4,5
B: .WORD 1,2,3,4,5

.TEXT
LDR R0,=A
LDR R1,=B

MOV R4,#5
MOV R5,#0

L1:LDR R2,[R0],#4
LDR R3,[R1],#4
MUL R4,R2,R3
ADD R5,R4,R5
CMP R4,#0
BNE L1

SWI 0X011