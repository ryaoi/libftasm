/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:52:45 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 20:26:08 by ryaoi            ###   ########.fr       */
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
        memset(NULL, 'c', 20);
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
        ft_memset(NULL, 'c', 20);
        exit(EXIT_FAILURE);
    }
    waitpid(p[1], &status_mine, 0);
    if (status_real == status_mine)
        printf("[CRASH TEST]\tDEST:NULL  |\t%s",GOOD);
    else
        printf("[CRASH TEST]\tDEST:NULL  |\t%s",BAD);
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
	crash_test();
}