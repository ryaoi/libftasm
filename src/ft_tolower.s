;-----------------------------------------------
;	ft_tolower.s
;
;	int		ft_tolower(int c);
;
;	This 64-bit function converts a upper-case
;	letter to the corresponding lower-case
;	letter.
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_tolower

	section .text
_ft_tolower:
	push rbp
	mov rbp, rsp
	cmp rdi, 0x41
	jnge _not_uppercase
	cmp rdi, 0x5a
	jg _not_uppercase
	mov rax, rdi
	add rax, 0x20
	leave
	ret

_not_uppercase:
	mov rax, rdi
	leave
	ret
