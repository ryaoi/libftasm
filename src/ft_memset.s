;-----------------------------------------------
;	ft_memset.s
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
	push rbp
	mov rbp, rsp
	push rdi
	mov rax, rsi
	mov rcx, rdx
	rep stosb			;untill rcx=0
	mov rax, rdi
	pop rdi
	mov rax, rdi
	leave
	ret
