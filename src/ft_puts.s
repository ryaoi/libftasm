;-----------------------------------------------
;	ft_puts.s
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

	global _ft_puts
	extern _ft_strlen

	section .text
_ft_puts:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je	_succesful_exit
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
	mov rdx, endline.len
	lea rsi, [rel endline.string]
	mov rax, MACHO_SYSCALL(WRITE)
	syscall
	cmp rax, 0
	jge _succesful_exit
	mov rax, -1				; EOF
	leave
	ret

_succesful_exit:
	mov rax, 10
	leave
	ret

	section .data
endline:
	.string db 10
	.len equ $ - endline.string
