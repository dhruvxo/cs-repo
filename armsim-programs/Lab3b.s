.data
a:.word 1,2,3,4,5,6,7,8,9
b:.word 0,0,0
.text
mov r0,#0
mov r1,#0
mov r2,#3
mov r9,#0
ldr r6,=b
b rowsum
swi 0x011
rowsum:
l1:mla r3,r0,r2,r1
mov r3,r3,lsl #2
ldr r4,=a
ldr r7,[r4,r3]
add r9,r9,r7
add r1,r1,#1
cmp r1,#3
bne l1
str r9,[r6],#4
add r0,r0,#1
mov r9,#0
mov r1,#0
cmp r0,#3
bne l1
mov pc,lr