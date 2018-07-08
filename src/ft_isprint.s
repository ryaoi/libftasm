;-----------------------------------------------
;	_ft_isprint.s
;
;	This 64-bit function tests for any printing
;	character, including space (` ').
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_isprint

	section .text
_ft_isprint:
	cmp rdi, 0x20
	jnge _not_print
	cmp rdi, 0x127
	jg _not_print
	mov rax, 1
	ret

_not_print:
	xor rax, rax
	ret
