;-----------------------------------------------
;	ft_strjoin.s
;
;	char *ft_strjoin(char *s1, char *s1)
;
;	The ft_strjoin() concatenate the string s1
;   and the string s2 and return the allocated
;   address of the concatenated string
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

    global  _ft_strjoin
    extern  _ft_strlen
    extern  _ft_strcpy
    extern  _ft_strcat
    extern _malloc

    section .text
_ft_strjoin:
    push r15
    push rdi
    push rsi
    call _ft_strlen
    pop rsi
    pop rdi
    mov r15, rax
    push rdi
    push rsi
    mov rdi, rsi
    call _ft_strlen
    pop rsi
    pop rdi
    add r15, rax
    push rdi
    push rsi
    mov rdi, rax
    call _malloc
    cmp rax, 0
    jz  strjoin_exit
    pop rsi
    pop rdi

    mov r15, rax
    push rdi
    push rsi
    mov rsi, rdi            ;2nd param of strcpy
    mov rdi, r15            ;1st param of strcpy
    call _ft_strcpy
    pop rsi
    pop rdi

    push rdi
    push rsi
    mov rdi, r15            ;1st param of strcat
    call _ft_strcat
    pop rsi
    pop rdi

    mov rax, r15            ; return new address
strjoin_exit:
    pop r15
    ret
