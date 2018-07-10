/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:44:35 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/10 15:57:13 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void crash_test(void)
{
    int     status_mine;
    int     status_real;
    char	buffer[256];
    pid_t   p[2];

    //real
    p[0] = fork();
    if ( p[0] == -1 ) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if ( p[0] == 0 ) {
        strcpy(buffer, NULL);
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
    	ft_strcpy(buffer, NULL);
        exit(EXIT_FAILURE);
    }
    waitpid(p[1], &status_mine, 0);
    if (status_real == status_mine)
        printf("[CRASH TEST]\tSRC:NULL  |\t%s",GOOD);
    else
        printf("[CRASH TEST]\tSRC:NULL  |\t%s",BAD);
}

void			test_strcpy(void)
{
	char		buffer_mine[256];
	char		buffer_real[256];

	ft_strcpy(buffer_mine, "copying a string....");
	strcpy(buffer_real, "copying a string....");
	printf("Src :%s | mine:%s\treal:%s\t", "copying a string....",\
			buffer_mine, buffer_real);
	if (strcmp(buffer_mine, buffer_real) == 0)
		printf(GOOD);
	else
		printf(BAD);
	crash_test();
}
