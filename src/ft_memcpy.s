;-----------------------------------------------
;	ft_memcpy.s
;
;	void *ft_memcpy(void *restrict dst,
;				 const void *restrict src,
;				 size_t n);
;
;	The ft_memcpy() function copies n bytes from
;	memory area src to memory area dst.
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_memcpy

	section .text
_ft_memcpy:
	push rbp
	mov rbp, rsp
	mov rax, rdi
	mov rcx, rdx
	cld
	rep movsb			;mov till rcx = 0
	leave
	ret
