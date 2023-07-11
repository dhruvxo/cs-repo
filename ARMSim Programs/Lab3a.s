.data
a:.word 1,2,3,4,5,6,7,8,9
b:.word 1,1,1,1,1,1,1,1,1
pro:.word 0,0,0,0,0,0,0,0,0
.TEXT
ldr r0,=a
ldr r1,=b
ldr r2,=pro
mov r3,#0
mov r4,#0
mov r5,#3
mov r6,#0
l1:mla r7,r3,r5,r6
mov r7,r7,lsl #2
ldr r8,[r0,r7]
mla r7,r6,r5,r4
mov r7,r7,lsl #2
ldr r9,[r1,r7]
mul r10,r8,r9
add r11,r11,r10
add r6,r6,#1
cmp r6,#3
bne l1
str r11,[r2],#4
mov r6,#0
add r4,r4,#1
cmp r4,#3
bne l1
mov r6,#0
mov r4,#0
add r3,r3,#1
cmp r3,#3
bne l1
swi 0x011
