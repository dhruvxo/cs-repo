@compare the value of r0 and r1 add if r0=r1 else subtract

MOV R0,#15
MOV R1,#5
CMP R0,R1
ADDEQ R2,R0,R1
SUBNE R3,R0,R1
SWI 0X011