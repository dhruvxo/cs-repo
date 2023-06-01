;Write an ALP to add 2 32bit numbers loaded from memory and store the result in memory

.DATA
	
	N1: .WORD 0X00000005
	N2: .WORD 0X00000004
	S: .WORD 0X00000000

.TEXT
LDR R0,=N1
LDR R1,=N2
LDR R2,=S
LDR R3,[R0]
LDR R4,[R1]
ADD R5,R3,R4
STR R5,[R2]
SWI 0X011