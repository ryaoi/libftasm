;-----------------------------------------------
;	ft_putstr.s
;
;   void ft_putstr(char *s)
;
;	This 64-bit function write the string s, 
;	and a terminating newline character,
;	to the stream stdout
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

%define MACHO_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

	global _ft_putstr
	extern _ft_strlen

	section .text
_ft_putstr:
	push rdi
	push rsi
	call _ft_strlen
	pop rsi
	pop rdi
	mov rdx, rax
	mov rsi, rdi
	mov rdi, STDOUT
	mov rax, MACHO_SYSCALL(WRITE)
	syscall
	ret
