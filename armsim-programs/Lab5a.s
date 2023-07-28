.data
str: .ASCIZ "MPCA"
length: .ASCIZ "0"
disp: .ASCIZ ; "Length of the string is"

.text
ldr r0,=str
ldr r1,=length
mov r2,#0
loop:
ldrb r3,[r0],#1
cmp r3,#0
addne r2,r2,#1
bne loop
strb r2,[r1]
ldr r0,=disp
swi 0x02
ldr r0,=length
swi 0x02
swi 0x01