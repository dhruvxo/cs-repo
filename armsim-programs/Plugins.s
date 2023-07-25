mov r0, #02
swi 0x201      @left LED on
mov r0, #01
swi 0x201      @right LED on
mov r0, #03
swi 0x201      @both LEDs on