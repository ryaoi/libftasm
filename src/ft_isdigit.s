;-----------------------------------------------
;	_ft_isdigit.s
;
;	This 64-bit function tests for a decimal
;	digit character
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_isdigit

	section .text
_ft_isdigit:
	cmp rdi, 0x30
	jnge _not_digit
	cmp rdi, 0x39
	jg _not_digit
	mov rax, 1
	ret

_not_digit:
	xor rax, rax
	ret
