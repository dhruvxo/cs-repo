.data
src: .ASCIZ "MPCA"
srcstring: .ASCIZ "The source string is:"
dest: .ASCIZ ""
deststring: .ASCIZ "The destination string is:"

.text
ldr r0,=src
ldr r1,=dest
loop:
ldrb r2,[r0],#1
strb r2,[r1],#1
cmp r2,#0
bne loop

ldr r0,=srcstring
swi 0x02
ldr r0,=src
swi 0x02
ldr r0,=deststring
swi 0x02
ldr r0,=dest
swi 0x02
swi 0x011