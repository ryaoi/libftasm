;-----------------------------------------------
;	_ft_memset.s
;
;	void *memset(void *b, int c, size_t len);
;
;	The memset() function writes len bytes of 
;	value c (converted to an unsigned char) to
;	the string b
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_memset

	section .text
_ft_memset:
	mov rax, rsi
	mov rcx, rdx
	rep stosb			;scan till hitting al
	mov rax, rdi
	ret
