~include vector.asm
~include serial.asm
~include DACdrive.asm

.org 1000h
disp_elem_table_bp:
; Nothing goes here, this is a table for shapes.
.org 1100h

disp_get_elem_pointer:
	; TODO ensure a < 16. Look into checking `ov' after ***
	mov b, #008h
	mul ab
	mov dptr, #disp_elem_table_bp
	mov dpl, a ; Note this requires the table starts at dpl 00
	ret

; Dispatches requests to subroutines that handle the rest.
disp_elem:
	mov a, @dptr
	; Now we switch on the value of a.
	check_if_ellipse:
	cjne a, #'E', check_if_line_seg

	case_ellipse:
		lcall disp_render_ellipse
		ret
	check_if_line_seg:
	cjne a, #'L', check_if_point

	case_line_seg:
		lcall disp_render_line_seg
		ret

	check_if_point:
	cjne a, #'P', case_nullshape

	case_point:
		lcall disp_render_point
		ret

	case_nullshape:
		; Here we do nothing.
		ret


# THESE SHOULD MAKE HEAVY USE OF THE VECTOR LIBRARY AND DACDRIVE CODE
disp_render_ellipse: #TODO: Do this...
	ret

disp_render_line_seg: #TODO: Do this...
	ret

disp_render_point: #TODO: Do this...
	ret
		
