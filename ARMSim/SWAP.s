.DATA
A:.WORD 10

.TEXT
LDR R0,=A
LDR R1,[R0]
MOV R2,#20
STR R2,[R0]
MOV R2,R1