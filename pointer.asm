;^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
;^                   pointer.asm                ^
;^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

~include serial.asm


; TODO: From here down needs reformatting.

;================================================
;=               Stack Operations               =
;================================================

;================================================================
; Push a pointer ( passed in dptr ) onto the stack.
;================================================================
push_pointer:
   lcall pointer_print
   lcall crlf
   pop acc
   pop b
   push dpl
   push dph
   push b
   push acc
   ret

;================================================================
; Pop a pointer off the stack into dptr
;================================================================
pop_pointer:
   pop acc
   pop b
   pop dph
   pop dpl
   push b
   push acc
   lcall pointer_print
   lcall crlf
   ret

;================================================================
; Copy a pointer off the stack into dptr. Offset passed in a.
; Destroys a and R0.
;================================================================
arg_pointer:
   mov R0, a
   add a, #002h ; There's another return frame.
   lcall arg
   mov dph, a
   mov a, R0
   add a, #003h
   lcall arg
   mov dpl, a
   lcall pointer_print
   lcall crlf
   ret

;================================================
;=               Serial Operations              =
;================================================

;================================================================
; Print the contents of dptr to console.
;================================================================
pointer_print:
   push acc
   mov a, dph
   lcall prthex
   mov a, dpl
   lcall prthex
   pop acc
   ret
