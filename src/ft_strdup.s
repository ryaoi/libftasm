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

	section .text
_ft_strdup:
	call _ft_strlen		; get the size of the s1
	mov rdx, rax		; store len of s1 for 3rd param of memcpy
	push rdi
	push rsi			; alignemet 16
	mov rdi, rax
	call _malloc		; malloc(len)
	pop rsi
	pop rdi
	mov rsi, rdi
	mov rdi, rax
	call _ft_memcpy
	ret
