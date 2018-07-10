;-----------------------------------------------
;	ft_strcpy.s
;
;   char * strcpy(char * dst, const char * src);
;
;	The strcpy() functions copy the string src
;   to dst (including the terminating `\0'
;   character.)
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_strcpy
	extern _ft_strlen

	section .text
_ft_strcpy:
	push rbp
	mov rbp, rsp
    push rdi
    push rsi
    mov rdi, rsi        ;1st param of ft_strlen
    call _ft_strlen
    pop rsi
    pop rdi
    mov rcx, rax
	rep movsb			;mov till rcx = 0
    mov byte[rdi], 0    ;put '\0' at the end
    leave
	ret
