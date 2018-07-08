;-----------------------------------------------
;	_ft_cat.s
;
;	void    ft_cats(int fd);
;
;	The ft_cats() function read fd sequentially,
;   writing them to the standard output.
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

%define MACHO_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define READ                3
%define WRITE				4
%define BUFFER_SIZE			10

    global _ft_cats
    extern _ft_putstr
    extern _ft_strdup
    extern _ft_strjoin
    extern _free

    section .text
_ft_cats:
    cmp rdi, -1
    jz exit_ft_cats
    push r15
    xor r15, r15
loop_read:
    lea rsi, [rel buffer]            ; void *buf
    mov rdx, BUFFER_SIZE             ; size_t nbyte
    mov rax, MACHO_SYSCALL(READ)     ; read
    syscall
    push rax
    cmp r15, 0
    jnz concatenate
    lea rdi, [rel buffer]            ; void *buf
    call _ft_strdup
    mov r15, rax
    pop rax
    cmp rax, -1
    jz exit_ft_cats
    cmp rax, 0
    jz loop_read
    jmp print_str
concatenate:
    mov rdi, r15
    lea rsi, [rel buffer]
    call _ft_strjoin
    mov rdi, r15
    mov r15, rax
    call _free
    pop rax
    cmp rax, -1
    jz exit_ft_cats
    cmp rax, 0
    jz loop_read
print_str:
    mov rdi, rsi
   call _ft_putstr              ; just for now
   mov rdi, r15
   call _free
exit_ft_cats:
    pop r15
    ret

    section .bss
buffer: resb BUFFER_SIZE

