/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:07:07 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/10 17:49:04 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void crash_test(void)
{
    int     status_mine;
    int     status_real;
    char	buffer[512];
    pid_t   p[2];

    //real
    p[0] = fork();
    if ( p[0] == -1 ) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if ( p[0] == 0 ) {
    	strncpy(buffer, NULL, 10);
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
    	ft_strncpy(buffer, NULL, 10);
        exit(EXIT_FAILURE);
    }
    waitpid(p[1], &status_mine, 0);
    if (status_real == status_mine)
        printf("[CRASH TEST]\tSRC:NULL  |\t%s",GOOD);
    else
        printf("[CRASH TEST]\tSRC:NULL  |\t%s",BAD);
}


void		test_strncpy(void)
{
	char	dst_mine[512];
	char	dst_real[512];

	char	*str = "COPYING THIS STRING?";
	bzero(dst_mine, 512);
	bzero(dst_real, 512);
	ft_strncpy(dst_mine, str, 7);
	strncpy(dst_real, str, 7);
	printf("Src :%s length:%d | mine:%s\treal:%s\t", str, 7, dst_mine, dst_real);
	if (strcmp(dst_mine, dst_real) == 0)
		printf(GOOD);
	else
		printf(BAD);
	ft_strncpy(dst_mine, str, strlen(str));
	strncpy(dst_real, str, strlen(str));
	printf("Src :%s length:%lu | mine:%s\treal:%s\t", str, strlen(str), dst_mine, dst_real);
	if (strcmp(dst_mine, dst_real) == 0)
		printf(GOOD);
	else
		printf(BAD);
	crash_test();
}
