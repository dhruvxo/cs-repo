@Program to find the sum of n numbers using conditional branch and store the result in memory location

.DATA
	A:.BYTE 10,20,30,40,50,60,70,80,90
	RES:.BYTE 0

.TEXT
LDR R0,=A
LDR R1,=RES
MOV R3,#0
MOV R4,#0

l:
LDRB R2,[R0]
ADD R3,R3,R2
ADD R4,R4,#1
CMP R4,#9
ADD R0,R0,#1
BNE l
STRB R3,[R1]
SWI 0X011