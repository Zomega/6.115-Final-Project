;^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
;^                   vector.asm                 ^
;^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
; A Library of 2D vector operations
;
; * R3 and R4 are reserved for storing the vector
;
; * It is assumed that R0 and R1 are free for
;   temp registers. 
;
; * It is assumed that a is free for temp
;   operations.

~include serial.asm
~include pointer.asm

;================================================
;=               Stack Operations               =
;================================================

push_vector:
	;TODO:  pop_pointer
	push	r3
	push	r4
	;TODO:	push_pointer
	ret

pop_vector:
	;TODO:  pop_pointer
	pop	r4
	pop	r3
	;TODO:	push_pointer
	ret

;================================================
;=               Serial Operations              =
;================================================

; Send a vector out over the serial line.
send_vector:
	;TODO: Make this
	ret

; Reads a vector over the serial line and 
receive_vector:
	;TODO: Make this
	ret

; Like receive_vector, but sends the received
; vector back over the line. Intended for
; console debugging.
read_vector:
	lcall receive_vector
	lcall send_vector
	ret

;================================================
;=             Vector Math Operations           =
;================================================

; Replaces the vector in R3 and R4 with a version
; multiplied with a
scale_vector:
	;TODO: Make this
	ret

; pops two vectors off the stack and adds them.
; The result is placed in R3 and R4
add_vector;
	;TODO: Make this
	ret

; pops two vectors off the stack and subtracts them.
; The result is placed in R3 and R4
add_vector;
	;TODO: Make this
	ret
