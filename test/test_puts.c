/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_puts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:23:11 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/10 15:59:57 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void crash_test(void)
{
    int     status_mine;
    int     status_real;
    pid_t   p[2];

    //real
    p[0] = fork();
    if ( p[0] == -1 ) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if ( p[0] == 0 ) {
        puts(NULL);
        exit(EXIT_FAILURE);
    }
    waitpid(p[0], &status_real, 0);

    //mine
    p[1] = fork();
    if ( p[1] == -1 ) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if ( p[1] == 0 ) {
    	ft_puts(NULL);
        exit(EXIT_FAILURE);
    }
    waitpid(p[1], &status_mine, 0);
    if (status_real == status_mine)
        printf("[CRASH TEST]\tSRC:NULL  |\t%s",GOOD);
    else
        printf("[CRASH TEST]\tSRC:NULL  |\t%s",BAD);
}

void		test_puts(void)
{
	int		ret;
	int		ret_real;
	
	ret = ft_puts("testing puts!");
	ret_real = puts("testing puts!");
	printf("mine :%d\t real:%d\t", ret, ret_real);
	if (ret == ret_real)
		printf(GOOD);
	else
		printf(BAD);

	ret = ft_puts("");
	ret_real = puts("");
	printf("mine :%d\t real:%d\t", ret, ret_real);
	if (ret == ret_real)
		printf(GOOD);
	else
		printf(BAD);
	crash_test();
}
