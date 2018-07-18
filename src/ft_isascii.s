;-----------------------------------------------
;	ft_isascii.s
;
;	int ft_isascii(int c);
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
	push rbp
	mov rbp, rsp
	cmp rdi, 0x0
	jnge _not_ascii
	cmp rdi, 0x7F
	jg   _not_ascii
	mov rax, 1
	leave
	ret

_not_ascii:
	xor rax, rax
	leave
	ret
