MOV R0,#0XFFFFFFFF
MOV R1,#5
MOV R2,#4
RSC R6,R1,#10
SUB R5,R1,R2
SBC R5,R1,R2
RSB R5,R1,#10
ADDS R3,R0,R1
ADC R4,R2,#3
SWI 0X011