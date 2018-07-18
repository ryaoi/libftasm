;-----------------------------------------------
;	ft_isalpha.s
;
;	int		ft_isalpha(int c);
;
;	This 64-bit function tests for any character
;	for which isupper(3) or islower(3) is true
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_isalpha

	section .text
_ft_isalpha:
	push rbp
	mov rbp, rsp
	cmp rdi, 0x41
	jnge _check_lower
	cmp rdi, 0x5a
	jg   _check_lower
	jmp _is_alpha

_check_lower:
	cmp rdi, 0x61
	jnge _not_alpha
	cmp rdi, 0x7a
	jg _not_alpha
	jmp _is_alpha

_not_alpha:
	xor rax, rax
	leave
	ret
_is_alpha:
	mov rax, 1
	leave
	ret
