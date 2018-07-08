;-----------------------------------------------
;	_ft_isascii.s
;
;	This 64-bit function tests for an ASCII
;	character, which is any character between
;	0 and 127 inclusive
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_isascii

	section .text
_ft_isascii:
	cmp rdi, 0x0
	jnge _not_ascii
	cmp rdi, 0x127
	jg   _not_ascii
	mov rax, 1
	ret

_not_ascii:
	xor rax, rax
	ret
