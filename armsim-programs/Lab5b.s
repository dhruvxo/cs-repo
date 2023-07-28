.data
src: .ASCIZ "MPCA\n"
srcstr: .ASCIZ "the source string is : "
deststr: .ASCIZ "the destination string is : "
dest: .ASCIZ ""
.text
ldr r0,=src
ldr r1,=dest
loop:
ldrb r2,[r0],#1
strb r2,[r1],#1
cmp r2,#0
BNE loop
ldr r0,=srcstr
swi 0x02
ldr r0,=src
swi 0x02
ldr r0,=deststr
swi 0x02
ldr r0,=dest
swi 0x02
swi 0x011