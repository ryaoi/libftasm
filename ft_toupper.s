;-----------------------------------------------
;	_ft_toupper.s
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
	cmp rdi, 0x61
	jnge _not_lowercase
	cmp rdi, 0x7a
	jg _not_lowercase
	mov rax, rdi
	sub rax, 0x20
	ret

_not_lowercase:
	mov rax, rdi
	ret
