.data
a:.word 1,2,3,4,5
.text
ldr r1,=a
mov r3,#1
l1:ldr r2,[r1],#4
cmp r2,#2
beq l2
add r3,r3,#1
cmp r3,#6
beq l1
bne l3
l2:mov r0,#1
swi 0x011
l3:mov r0,#0
swi 0x011