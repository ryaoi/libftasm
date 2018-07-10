/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:56:22 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 20:28:40 by ryaoi            ###   ########.fr       */
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
        strlen(NULL);
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
        ft_strlen(NULL);
        exit(EXIT_FAILURE);
    }
    waitpid(p[1], &status_mine, 0);
    if (status_real == status_mine)
        printf("[CRASH TEST]\tValue:NULL |\t%s",GOOD);
    else
        printf("[CRASH TEST]\tValue:NULL |\t%s",BAD);
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
	crash_test();
}
