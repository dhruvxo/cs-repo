;write a program to count the number or occurrence of a character in a string
.text
LDR r0, =text ;loading the address of text
LDR r1, =char ;loading the address of character
LDRB r2, [r1] ;loading the character
MOV r4,#0 ;number of occurances

LOOP: LDRB r3, [r0], #1
CMP r3, #0 ;checking if end of string
BEQ EXIT

CMP r3,r2 ;checking if character is equal
ADDEQ r4,r4,#1
B LOOP

;printing the output
EXIT:
LDR r0, =occur
SWI 0x02
ADD r0,r4,#48
SWI 0x00

.data
text: .asciz "HelloWorlddd"
char: .asciz "d"
occur: .asciz "Number of Occurences="