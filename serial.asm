;^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
;^                   serial.asm                 ^
;^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
; This package is primaraly adapted from MinMon,
; which is (c) SBL 2001.

; Consider doing this with interrupts?

init_serial:
	mov	tmod,	#20h
	mov	tcon,	#41h
	mov	th1,	#0fdh
	mov	scon,	#50h
	ret

;TODO: Reformat below this.

;===============================================================
; subroutine sndchr
; this routine takes the chr in the acc and sends it out the
; serial port.
;===============================================================
sndchr:
   clr  scon.1            ; clear the tx  buffer full flag.
   mov  sbuf,a            ; put chr in sbuf
txloop:
   jnb  scon.1, txloop    ; wait till chr is sent
   ret
;===============================================================
; subroutine getchr
; this routine reads in a chr from the serial port and saves it
; in the accumulator.
;===============================================================
getchr:
   jnb  ri, getchr        ; wait till character received
   mov  a,  sbuf          ; get character
   anl  a,  #7fh          ; mask off 8th bit
   clr  ri                ; clear serial status bit
   ret

;===============================================================
; subroutine prthex
; this routine takes the contents of the acc and prints it out
; as a 2 digit ascii hex number.
;===============================================================
prthex:
   push acc
   lcall binasc           ; convert acc to ascii
   lcall sndchr           ; print first ascii hex digit
   mov   a,  r2           ; get second ascii hex digit
   lcall sndchr           ; print it
   pop acc
   ret

;===============================================================
; subroutine getbyt
; this routine reads in an 2 digit ascii hex number from the
; serial port. the result is returned in the acc.
;===============================================================
getbyt:
   lcall getchr           ; get msb ascii chr
   lcall ascbin           ; conv it to binary
   swap  a                ; move to most sig half of acc
   mov   b,  a            ; save in b
   lcall getchr           ; get lsb ascii chr
   lcall ascbin           ; conv it to binary
   orl   a,  b            ; combine two halves
   ret

; TODO: write a read.

;===============================================================
; subroutine binasc
; binasc takes the contents of the accumulator and converts it
; into two ascii hex numbers.  the result is returned in the
; accumulator and r2.
;===============================================================
binasc:
   mov   r2, a            ; save in r2
   anl   a,  #0fh         ; convert least sig digit.
   add   a,  #0f6h        ; adjust it
   jnc   noadj1           ; if a-f then readjust
   add   a,  #07h
noadj1:
   add   a,  #3ah         ; make ascii
   xch   a,  r2           ; put result in reg 2
   swap  a                ; convert most sig digit
   anl   a,  #0fh         ; look at least sig half of acc
   add   a,  #0f6h        ; adjust it
   jnc   noadj2           ; if a-f then re-adjust
   add   a,  #07h
noadj2:
   add   a,  #3ah         ; make ascii
   ret

;===============================================================
; subroutine ascbin
; this routine takes the ascii character passed to it in the
; acc and converts it to a 4 bit binary number which is returned
; in the acc.
;===============================================================
ascbin:
   clr   errorf
   add   a,  #0d0h        ; if chr < 30 then error
   jnc   notnum
   clr   c                ; check if chr is 0-9
   add   a,  #0f6h        ; adjust it
   jc    hextry           ; jmp if chr not 0-9
   add   a,  #0ah         ; if it is then adjust it
   ret
hextry:
   clr   acc.5            ; convert to upper
   clr   c                ; check if chr is a-f
   add   a,  #0f9h        ; adjust it
   jnc   notnum           ; if not a-f then error
   clr   c                ; see if char is 46 or less.
   add   a,  #0fah        ; adjust acc
   jc    notnum           ; if carry then not hex
   anl   a,  #0fh         ; clear unused bits
   ret
notnum:
   setb  errorf           ; if not a valid digit
   ljmp  endloop
