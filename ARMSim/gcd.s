.TEXT

MOV R0,#40
MOV R1,#36
GCD:
 CMP R0,R1
 BEQ RES
 BLT L
 SUB R0,R0,R1
 B GCD

L:
SUB R1,R1,R0
B GCD

RES:
MOV R2,R0
B GCD