/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:52:10 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 20:24:24 by ryaoi            ###   ########.fr       */
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
        bzero(NULL, 'c');
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
        ft_bzero(NULL, 'c');
        exit(EXIT_FAILURE);
    }
    waitpid(p[1], &status_mine, 0);
    if (status_real == status_mine)
        printf("[CRASH TEST]\tValue:NULL |\t%s",GOOD);
    else
        printf("[CRASH TEST]\tValue:NULL |\t%s",BAD);
}

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
	crash_test();
}