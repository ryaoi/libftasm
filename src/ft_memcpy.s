;-----------------------------------------------
;	_ft_memcpy.s
;
;	void *memcpy(void *restrict dst,
;				 const void *restrict src,
;				 size_t n);
;
;	The memcpy() function copies n bytes from
;	memory area src to memory area dst.
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_memcpy

	section .text
_ft_memcpy:
	mov rax, rdi
	mov rcx, rdx
	rep movsb			;mov till rcx = 0
	ret
