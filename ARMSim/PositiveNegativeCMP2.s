@this code checks the value in R0 and makes branching decisions based on the comparison result v2

MOV R0,#5
CMP R0,#0
MOVEQ R2,#1
SWIEQ 0X011
MOVMI R2,#3
SWIMI 0X011
MOVPL R2,#2
SWIPL 0X011