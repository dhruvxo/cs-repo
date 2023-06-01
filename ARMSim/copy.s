;Write and ALP to copy n numbers from location a to location b

.DATA 
LOC1:.WORD 10,20,30,40,50
LOC2:.WORD 0,0,0,0,0

.TEXT
LDR R1,=LOC1
LDR R2,=LOC2
MOV R3,#1

L1:
LDR R4,[R1],#4
STR R4,[R2]
ADD R3,R3,#1
CMP R3,#6
BNE L1
SWI 0X011