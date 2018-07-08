;-----------------------------------------------
;	_ft_strdup.s
;
;	char *strdup(const char *s1)
;
;	The strdup() function allocates sufficient
;	memory for a copy of the string s1, does the
;	copy, and returns a pointer to it.
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_memcpy
	extern _ft_bzero

	section .text
_ft_strdup:
	call _ft_strlen		; get the size of the s1
	mov rdx, rax		; store len of s1 for 3rd param of memcpy
	push rdi
	mov rdi, rax
	call _malloc		; malloc(len)
	cmp rax, 0
	je	strdup_fail		; if malloc = NULL then return 
	mov rdi, rax		;	1st param for bzero
	mov rsi, rdx		;	2nd param for bzero
	call _ft_bzero
	pop rdi
	mov rsi, rdi
	mov rdi, rax
	dec rdi
	call _ft_memcpy

	ret

strdup_fail:
	pop rdi
	ret