;streaming right TO left 
.DATA
NUM1: .WORD 15000
str: .asciz "PESU"
.text
mov r0,#39 ; r0=x axis 
mov r1,#7 ; r1=y axis 
mov r7,#0
ldr r8,=NUM1
ldr r8,[r8] 
ldr r2,=str
loop: swi 0x204 ;to display a string on the screen (r2:addr) 
bl sum
cmp r0,#0
subne r0,r0,#1
swieq 0x11
b loop
sum: 
cmp r7,r8
addne r7,r7,#1
bne sum
swi 0x206
mov r7,#0
mov pc,lr