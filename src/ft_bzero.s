;-----------------------------------------------
;	_ft_bzero.s
;
;	This 64-bit function writes n zeroed bytes
;	to the string s. If n is zero, ft_zbero does
;	notrhing.
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_bzero

	section .text
_ft_bzero:
	cmp rsi, 0				;check if n is zero
	je _exit
	mov rdx, rsi
_bzero_loop:
	mov byte[rdi], 0
	dec rdx
	inc rdi
	cmp rdx, 0
	jg _bzero_loop
_exit:
	ret
