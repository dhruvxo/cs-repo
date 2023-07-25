@the code checks two conditions: whether R0 is equal to R1 and whether R2 is equal to R3. If both conditions are true, it increments the value in R4 by 1

;IF((R0==R1)&&(R2==R3)) R4++

MOV R0,#10
MOV R1,#10
MOV R2,#10
MOV R3,#10
MOV R4,#0
CMP R0,R1
BEQ L1
SWINE 0X011
L1: CMP R2,R3
BEQ L2
SWINE 0X011
L2: ADD R4,R4,#1