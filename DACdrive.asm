; This file contains code designed to drive the 2 DACS.
; It make

~include vector.asm

disp_beam_enable:
	ret

disp_beam_disable:
	ret

disp_move_beam:
	; push the vector in R3 and R4 out to the DAC 
	ret
