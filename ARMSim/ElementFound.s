.DATA 
    A:.WORD 10,20,30,40,50,60,70
    MSG1:.ASCIZ "Element found"
    MSG2:.ASCIZ "Element not found"

.TEXT
    MOV R1,#10
    MOV R2,#0
    MOV R3,#7
    LDR R5,=A 
    MOV R6,#4
    ADD R4,R2,R3
    MOV R4,R4,LSR #1
L1: CMP R2,R3
    BGT NOTFOUND
    ADD R4,R2,R3
    MOV R4,R4,LSR #1
    MLA R7,R6,R4,R5
    LDR R8,[R7]
    CMP R1,R8
    BEQ FOUND
    BMI LOWER
    BGT UPPER

    FOUND: LDR R0,=MSG1
            SWI 0X02
            SWI 0X011

    UPPER: ADD R2,R4,#1
            B L1
    
    LOWER: SUB R3,R4,#1
            B L1

    NOTFOUND: LDR R0,=MSG2
               SWI 0X02
               SWI 0X011