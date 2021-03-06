;-----------------------------------------------
;	ft_cat.s
;
;	void    ft_cat(int fd);
;
;	The ft_cat() function read fd sequentially,
;   writing them to the standard output.
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

%define MACHO_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define READ                3
%define WRITE				4
%define BUFFER_SIZE			4096

    global _ft_cat
    extern _ft_putstr
    extern _ft_strdup
    extern _ft_strjoin
    extern _ft_bzero
    extern _free

    section .text
_ft_cat:
	push rbp
	mov rbp, rsp
	cmp rdi, -1
	jle exit_ft_cats
	xor r15, r15			; stock address for print all
loop_read:
	push r15				;save r15
	push rdi				;rdi should always stock fd
	lea rsi, [rel buffer]
	mov rdx, BUFFER_SIZE
	mov rax, MACHO_SYSCALL(READ)
	syscall
	mov r14, rax			;save ret of READ for later
	pop rdi
	pop r15
	cmp r14, -1
	jz exit_ft_cats
	cmp r15, 0
	jnz joinstr

	push r14
	push rdi
	lea rdi, [rel buffer]
	call _ft_strdup
	mov r15, rax
	pop rdi
	pop r14
	cmp r14, BUFFER_SIZE
	jz loop_read
	jmp print_result

joinstr:
	push r15
	push rdi
	mov rdi, r15
	lea rsi, [rel buffer]
	call _ft_strjoin
	pop rdi
	pop r15

	push r15
	push rax
	push rdi
	mov rdi, r15
	call _free
	pop rdi
	pop rax
	pop r15

	mov r15, rax			;new string

	push rsi
	push rdi
	lea rdi, [rel buffer]
	mov rsi, BUFFER_SIZE
	call _ft_bzero			; clear buffer
	pop rdi
	pop rsi
	cmp r14, -1
	jz exit_ft_cats
	cmp r14, BUFFER_SIZE
	je loop_read

print_result:
	push r15
	mov rdi, r15
	call _ft_putstr
	pop r15

	mov rdi, r15
	call _free
	
exit_ft_cats:
	leave
	ret

    section .bss
buffer: resb BUFFER_SIZE+1
