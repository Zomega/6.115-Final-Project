mov P1, #0FF ; Just in case, not that it should change anything.
mov r0, #080h

input_loop:
	rl R0
	; Here do the pull low pull high dealio...
	mov R1, 0
	mov P1, R0
	lcall delay ; TODO Time carefully.
	mov P1, #0FF ; TODO may need small delay after this? Hopefully the inc cycle is enough.
	tc_measure_loop:
		inc R1
		cjne P1, #0FF
	mov a, R1
	lcall send_byte
	cjne r0, #080, input_loop
