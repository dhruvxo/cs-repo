@this code checks the value in R0 and makes branching decisions based on the comparison result

MOV R0,#5
CMP R0,#0
MOVEQ R2,#1
BEQ L1
MOVMI R2,#3
BMI L1
MOVPL R2,#2
BPL L1
L1:SWI 0X011