;-----------------------------------------------
;	ft_toupper.s
;
;	int		ft_toupper(int c);
;
;	This 64-bit function converts a lower-case
;	letter to the corresponding upper-case
;	letter.
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_toupper

	section .text
_ft_toupper:
	push rbp
	mov rbp, rsp
	cmp rdi, 0x61
	jnge _not_lowercase
	cmp rdi, 0x7a
	jg _not_lowercase
	mov rax, rdi
	sub rax, 0x20
	leave
	ret

_not_lowercase:
	mov rax, rdi
	leave
	ret
