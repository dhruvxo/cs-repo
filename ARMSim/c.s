@the code checks whether the value in R0 is equal to 5. If it is, it triggers a software interrupt

;IF(R0!=5) {R1=R1+R0-R2}
MOV R0,#4
MOV R1,#10
MOV R2,#20
CMP R0,#5
SWIEQ 0X011
BNE L
L: 
ADD R3,R1,R0
SUB R1,R3,R2