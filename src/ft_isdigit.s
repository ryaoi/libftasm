;-----------------------------------------------
;	ft_isdigit.s
;
;	int		isdigit(int c);
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
	push rbp
	mov rbp, rsp
	cmp rdi, 0x30
	jnge _not_digit
	cmp rdi, 0x39
	jg _not_digit
	mov rax, 1
	leave
	ret

_not_digit:
	xor rax, rax
	leave
	ret
