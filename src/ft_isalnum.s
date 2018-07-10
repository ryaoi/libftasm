;-----------------------------------------------
;	_ft_isalnum.s
;
;	int		ft_isalnum(int c);
;
;	This 64-bit function tests for any character
;	for which _ft_isalpha(3) or 
;	_ft_isdigit(3) is true
;
;	ryaoi@student.42.fr
;
;-----------------------------------------------

	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

	section .text
_ft_isalnum:
	push rbp
	mov rbp, rsp
	call _ft_isalpha
	cmp rax, 1
	je _exit
	call _ft_isdigit
_exit:
	leave
	ret
