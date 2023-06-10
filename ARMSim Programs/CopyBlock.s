@To copy a block of 512 bytes if data from location A to location B if the rate of data transfer rate is 32 bytes


.DATA
A:.WORD 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
B:.WORD 0

.TEXT
LDR R0,=A
LDR R11,=B
MOV R10,#1
ADD R10,R10,#1
CMP R10,#17
BNE L
SWI 0X011
L:
LDMIA R0!,{R1-R8}
STMIA R11!,{R1-R8}
