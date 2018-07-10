/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:23:41 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 20:25:04 by ryaoi            ###   ########.fr       */
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
        memcpy(NULL, "aaaaaa", 6);
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
        ft_memcpy(NULL, "aaaaaa", 6);
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
    int     status_mine;
    int     status_real;
	char	buffer1[500];
	char	buffer2[500];
    pid_t   p[2];


	bzero(buffer1, 500);
	bzero(buffer2, 500);
    //real
    p[0] = fork();
    if ( p[0] == -1 ) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if ( p[0] == 0 ) {
        memcpy(buffer1, NULL, 6);
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
        ft_memcpy(buffer2, NULL, 6);
        exit(EXIT_FAILURE);
    }
    waitpid(p[1], &status_mine, 0);
    if (status_real == status_mine)
        printf("[CRASH TEST]\tSRC:NULL   |\t%s",GOOD);
    else
        printf("[CRASH TEST]\tSRC:NULL   |\t%s",BAD);
}

void		loop_test_memcpy(char *src, size_t len)
{
	char	buffer1[500];
	char	buffer2[500];

	bzero(buffer1, 500);
	bzero(buffer2, 500);

	ft_memcpy(buffer1, src, len);
	memcpy(buffer2, src, len);
	printf("Src: %30s n:%3lu | \t mine:%s real:%s\t", src, len, buffer1, buffer2);
	if (strcmp(buffer1, buffer2) == 0)
		printf(GOOD);
	else
		printf(BAD);
}

void		test_memcpy(void)
{
	char	*src[] = {"Copy this string!!!!", "Copy this string!!!!", "", NULL};
	size_t	len[] = {strlen(src[0]), 4, 0, 0};
	int		index = 0;

	while (src[index] != NULL)
	{
		loop_test_memcpy(src[index], len[index]);
		index++;
	}
	crash_test();
	crash_test2();
}