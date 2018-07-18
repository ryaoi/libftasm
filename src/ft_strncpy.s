;-----------------------------------------------
;	ft_strncpy.s
;
;   char * ft_strncpy(char * dst, const char * src,
;					size_t n);
;
;	The ft_strncpy() functions copy the string src
;   to dst for n length.
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_strncpy

	section .text
_ft_strncpy:
	push rbp
	mov rbp, rsp
    mov rcx, rdx
	rep movsb			;mov till rcx = 0
    mov byte[rdi], 0    ;put '\0' at the end
	leave
	ret
