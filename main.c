
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>
#include <strings.h>
#include "libfts.h"

#define GOOD  "\033[1;32m[GOOD]\n\033[0m"
#define BAD "\033[1;31m[BAD]\n\033[0m"

void	test_bzero(void)
{
	char dst_mine1[20] = "ABCDEFGHIJK";
	char dst_real1[20] = "ABCDEFGHIJK";

	printf("[Value:%s]\t", dst_mine1);
	ft_bzero(dst_mine1, 20);
	bzero(dst_real1, 20);
	if (strcmp(dst_mine1, dst_real1) == 0)
		printf(GOOD);
	else
		printf(BAD);

	strcpy(dst_mine1,"!");
	strcpy(dst_real1,"!");
	printf("[Value:%s]\t", dst_mine1);
	ft_bzero(dst_mine1, 20);
	bzero(dst_real1, 20);
	if (strcmp(dst_mine1, dst_real1) == 0)
		printf(GOOD);
	else
		printf(BAD);

}

void	test_strcat(void)
{
	char dst_mine1[100] = "ABCDEFGHIJK\0";
	char dst_real1[100] = "ABCDEFGHIJK\0";
	char	*ret_mine = NULL;
	char	*ret_real = NULL;

	printf("[s1:%s, s2:%s] -> ", dst_mine1, "LMNOP");
	ret_mine = ft_strcat(dst_mine1, "LMNOP\0");
	ret_real = strcat(dst_real1, "LMNOP\0");
	printf("s1:%s\t", dst_mine1);
	if (strcmp(ret_mine, ret_real) == 0)
		printf(GOOD);
	else
		printf(BAD);

	bzero(dst_mine1, 100);
	bzero(dst_real1, 100);
	printf("[s1:%s, s2:%s] -> ", dst_mine1, "TESTINGTESITNITNITN");
	ret_mine = ft_strcat(dst_mine1, "TESTINGTESITNITNITN");
	ret_real = strcat(dst_real1, "TESTINGTESITNITNITN");
	printf("s1:%s\t", dst_mine1);
	if (strcmp(ret_mine, ret_real) == 0)
		printf(GOOD);
	else
		printf(BAD);

}

void		test_strlen(void)
{
	int len = ft_strlen("AAAAAAA\0");
	int len_real = strlen("AAAAAAA\0");
	printf("[Value:%s]\tmine:%d\treal:%d\t", "AAAAAAA\0", len, len_real);
	if (len == len_real)
		printf(GOOD);
	else
		printf(BAD);
	len = ft_strlen("\0");
	len_real = strlen("\0");
	printf("[Value:%s]\tmine:%d\treal:%d\t", "\0", len, len_real);
	if (len == len_real)
		printf(GOOD);
	else
		printf(BAD);
}

void		test_puts(void)
{
	int		ret;
	int		ret_real;
	
	ret = ft_puts("testing puts!");
	ret_real = puts("testing puts!");
	printf("mine :%d\t real:%d\n", ret, ret_real);
	if (ret == ret_real)
		printf(GOOD);
	else
		printf(BAD);

	ret = ft_puts("");
	ret_real = puts("");
	printf("mine :%d\t real:%d\n", ret, ret_real);
	if (ret == ret_real)
		printf(GOOD);
	else
		printf(BAD);
}

void		test_memset(void)
{
	char	buffer1[500];
	char	buffer2[500];

	bzero(buffer1, 500);
	bzero(buffer2, 500);
	ft_memset(buffer1, 'c', 10);
	memset(buffer2, 'c', 10);
	printf("Param:buffer[500], 'c', 10 | \t mine:%s real:%s\t", buffer1, buffer2);
	if (strcmp(buffer1, buffer2) == 0)
		printf(GOOD);
	else
		printf(BAD);
	bzero(buffer1, 500);
	bzero(buffer2, 500);
	ft_memset(buffer1, '1', 0);
	memset(buffer2, '1', 0);
	printf("Param:buffer[500], '1', 0  | \t mine:%s real:%s\t", buffer1, buffer2);
	if (strcmp(buffer1, buffer2) == 0)
		printf(GOOD);
	else
		printf(BAD);

}

void		test_memcpy(void)
{
	char	buffer1[500];
	char	buffer2[500];

	bzero(buffer1, 500);
	bzero(buffer2, 500);
	char 	*src = "copy this string!";
	ft_memcpy(buffer1, src, strlen(src));
	memcpy(buffer2, src, strlen(src));
	printf("Src: %s n:%lu | \t mine:%s real:%s\t", src, strlen(src), buffer1, buffer2);
	if (strcmp(buffer1, buffer2) == 0)
		printf(GOOD);
	else
		printf(BAD);
	bzero(buffer1, 500);
	bzero(buffer2, 500);
	ft_memcpy(buffer1, src, 4);
	memcpy(buffer2, src, 4);
	printf("Src: %s n:%lu | \t mine:%s real:%s\t", src, strlen(src), buffer1, buffer2);
	if (strcmp(buffer1, buffer2) == 0)
		printf(GOOD);
	else
		printf(BAD);

}

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

int main()
{
	
	int tab_test[] = {0x61, 0x32, 0x10, 0x12, 0x31, 0x200, 0x54, 0x6a};
	char	*total = "8";


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

	return 0;
}
