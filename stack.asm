;^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
;^                   stack.asm                  ^
;^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
; Routines for easy stack manipulations.

; Loads a c-style argument (1-byte) from the stack.
; The argument offset is in a, do not include the
; stack frame bytes. Arguments are zero indexed.
arg:
	mov	R0,	a
	mov	a,	sp
	subb	a,	#004d
	subb	a,	R0
	mov	R0,	a
	mov	a,	@R0
	ret
