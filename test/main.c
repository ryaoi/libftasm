/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:56:11 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/14 19:18:36 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_retint(const char *limit_str, ...)
{
	int		lim;
	int		i;
	va_list	arg;
	int		(*pf_mine)(int);
	int		(*pf_real)(int);
	int		*tab_test;

	va_start(arg, limit_str);
	pf_mine = va_arg(arg, void*);
	pf_real	= va_arg(arg, void*);
	lim = atoi(limit_str);
	tab_test = va_arg(arg, int *);
	i = 0;
	while(lim)
	{
		printf("[Value:%#x(%c)]\t\tmine:%d\treal:%d\t",\
				tab_test[i], (char)(tab_test[i]), \
				pf_mine(tab_test[i]), pf_real(tab_test[i]));
		if ((pf_mine(tab_test[i]) - pf_real(tab_test[i])) == 0)
			printf(GOOD);
		else
			printf(BAD);
		i++;
		lim--;
	}
	va_end(arg);
}

int main(int ac, char **av)
{
	(void)ac;
	int tab_test[] = {0x61, 0x32, 0x10, 0x12, 0x31, 0x200, 0x54, 0x6a, '3'};
	char	*total = "9";


	printf("======ISALPHA==========\n");
	test_retint(total, &ft_isalpha, &isalpha, &tab_test);

	printf("======ISDIGIT==========\n");
	test_retint(total, &ft_isdigit, &isdigit, &tab_test);

	printf("======ISALNUM==========\n");
	test_retint(total, &ft_isalnum, &isalnum, &tab_test);

	printf("======ISASCII==========\n");
	test_retint(total, &ft_isascii, &isascii, &tab_test);

	printf("======ISPRINT==========\n");
	test_retint(total, &ft_isprint, &isprint, &tab_test);

	printf("======TOUPPER==========\n");
	test_retint(total, &ft_toupper, &toupper, &tab_test);

	printf("======TOLOWER==========\n");
	test_retint(total, &ft_tolower, &tolower, &tab_test);

	printf("======BZERO==========\n");
	test_bzero();

	printf("=======STRCAT==========\n");
	test_strcat();

	printf("=======STRLEN==========\n");
	test_strlen();

	printf("=======PUTS==========\n");
	test_puts();
	
	printf("=======MEMSET==========\n");
	test_memset();

	printf("=======MEMCPY==========\n");
	test_memcpy();

	printf("=======STRDUP==========\n");
	test_strdup();

	printf("==========CAT==========\n");

	int fd = open(__FILE__, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	ft_cat(fd);
	
	ft_cat(open(av[0], O_RDONLY));

	printf("=======ENDCAT==========\n");

	printf("\n\n[*]Bonus!\n\n");

	printf("=======STRJOIN==========\n");
	test_strjoin();

	printf("=======PUTSTR==========\n");
	test_putstr();

	printf("=======STRCPY==========\n");
	test_strcpy();

	printf("=======STRNCPY=========\n");
	test_strncpy();

	printf("=======STRSUB==========\n");
	test_strsub();

	return 0;
}
