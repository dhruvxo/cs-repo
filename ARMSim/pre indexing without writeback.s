.DATA 
A:.WORD 10,20,30,40,50,60,70,80,90,100
RES:.WORD 0

.TEXT
LDR R1,=A
LDR R2,=RES
MOV R4,#0
MOV R5,#1
L1:
LDR R3,[R1,#4]
ADD R4,R4,R3
ADD R5,R5,#1
CMP R5,#11
BNE L1
STR R4,[R2]
SWI 0X011
