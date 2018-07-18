;-----------------------------------------------
;	ft_strdup.s
;
;	char *ft_strdup(const char *s1)
;
;	The ft_strdup() function allocates sufficient
;	memory for a copy of the string s1, does the
;	copy, and returns a pointer to it.
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

	section .text
_ft_strdup:
	push rdi			;align for malloc
	call _ft_strlen		; get the size of the s1
	mov rdi, rax
	add rdi, 1			; +1 for '\0'
	call _malloc		; malloc(len)
	cmp rax, 0
	je	strdup_fail		; if malloc = NULL then return 
	mov rdi, rax
	pop rsi
	push rax			; save return address
	call _ft_strcpy
	pop rax				; get return address
	ret

strdup_fail:
	pop rdi
	ret
