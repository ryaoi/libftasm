;-----------------------------------------------
;	_ft_strsub.s
;
;   char * strsub(char * str, unsigned int start, 
;	size_t len);
;
;	The strsub() functions copy the string from start
;   Allocates (with malloc(3)) and returns a “fresh” 
;	substring from the string given as argument. 
;	The substring begins at indexstart and is
;	of size len. If start and len aren’t refering
;	to a valid substring, the behavior is undefined.
;	If the allocation fails, the function returns NULL.
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_strsub
	extern _malloc
	extern _ft_strncpy
	extern _ft_strlen

	section .text
_ft_strsub:
	push rbp
	mov rbp, rsp
	add rsp, 0x20
	cmp rdi, 0					; if str = NULL
	jz exit_fail_strsub
	cmp rdx, 0					; if len = NULL
	jz exit_fail_strsub
	mov [rsp-0x8], rdi
	mov [rsp-0x10], rsi
	mov [rsp-0x18], rdx
	push rdi
	call _ft_strlen
	pop rdi
	cmp rax, [rsp-0x10]		; if start >= len(str)
	jg exit_fail_strsub
	mov rdi, [rsp-0x18]
	call _malloc
	cmp rax, 0					; if malloc = NULL
	jz exit_fail_strsub
	mov rdi, rax
	mov rsi, [rsp-0x8]
	add rsi, [rsp-0x10]
	mov rdx, [rsp-0x18]
	call _ft_strncpy			; if strncpy = NULL
	cmp rax, 0
	jz exit_fail_strsub
	jmp exit_strsub

exit_fail_strsub:
	xor rax, rax
exit_strsub:
	sub rsp, 0x20
    leave
	ret
