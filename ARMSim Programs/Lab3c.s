.data
a:.word 0,0,0,0,0,0,0,0,0
.text
mov r0,#0
mov r1,#0
mov r2,#3
mov r9,#1
b dihard
swi 0x011
dihard:
l1:mla r3,r0,r2,r1
mov r3,r3,lsl #2
ldr r4,=a
str r9,[r4,r3]
add r1,r1,#1
add r0,r0,#1
add r9,r9,r9
cmp r0,#3
bne l1
mov pc,lr