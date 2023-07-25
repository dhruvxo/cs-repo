;diagonal
.text
	mov r0, #0	;r0=X coordinate
	mov r1, #0	;r1=y coordinate
	mov r7, #0
	ldr r8,=num
	ldr r8,[r8]
	ldr r2,=str

loop:
	swi 0x0204	;display a string on the screen (R2: address)
	bl sum
	cmp r0,#39
	cmp r1,#39
	addne r0,r0,#3
	addne r1,r1,#1
	swieq 0x11
	b loop

sum: cmp r7,r8
	addne r7,r7,#10
	bne sum
	swi 0x206
	mov r7,#0
	mov pc, lr

.data
str: .asciz "PESU"
num: .word 50000