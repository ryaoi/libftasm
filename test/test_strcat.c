/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:55:22 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 20:26:44 by ryaoi            ###   ########.fr       */
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
        strcat(NULL, "aaa");
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
        ft_strcat(NULL, "aaa");
        exit(EXIT_FAILURE);
    }
    waitpid(p[1], &status_mine, 0);
    if (status_real == status_mine)
        printf("[CRASH TEST]\tDEST:NULL  |\t%s",GOOD);
    else
        printf("[CRASH TEST]\tDEST:NULL  |\t%s",BAD);
}

static void crash_test2(void)
{
	char dst_mine1[100] = "ABCDEFGHIJK\0";
	char dst_real1[100] = "ABCDEFGHIJK\0";
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
        strcat(dst_real1, NULL);
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
        ft_strcat(dst_mine1, NULL);
        exit(EXIT_FAILURE);
    }
    waitpid(p[1], &status_mine, 0);
    if (status_real == status_mine)
        printf("[CRASH TEST]\tSRC:NULL   |\t%s",GOOD);
    else
        printf("[CRASH TEST]\tSRC:NULL  |\t%s",BAD);
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
	crash_test();
	crash_test2();
}