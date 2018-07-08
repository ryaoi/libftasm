;-----------------------------------------------
;	_ft_strlen.s
;
;	This 64-bit function computes the length
;	of the string s.
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_strlen

	section .text
_ft_strlen:
	push rcx
	push rbx
	mov rbx, rdi
	xor al, al
	mov rcx, 0xFFFFFFFF
	repne scasb			;scan till hitting al
	sub rdi, rbx
	sub rdi, 0x1
	mov rax, rdi
	pop rbx
	pop rcx
	ret
