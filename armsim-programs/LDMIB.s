.DATA
A:.WORD 10,20,30

.TEXT
LDR R0,=A
LDMIB R0!,{R1-R3}