;-----------------------------------------------
;	ft_isprint.s
;
;	int		ft_isprint(int c);
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
	push rbp
	mov rbp, rsp
	cmp rdi, 0x20
	jnge _not_print
	cmp rdi, 0x7E
	jg _not_print
	mov rax, 1
	leave
	ret

_not_print:
	xor rax, rax
	leave
	ret
