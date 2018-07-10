/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:28:53 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 20:27:43 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void loop_test_strdup(char *str)
{
    char    *dup_mine = NULL;
    char    *dup_real = NULL;  

    dup_mine = ft_strdup(str);
    dup_real = strdup(str);
	printf("[Value:%s]\t", str);
    printf("mine:%s\t", dup_mine);
    printf("real:%s\t", dup_real);
	if (strcmp(dup_mine, dup_real) == 0)
		printf(GOOD);
	else
		printf(BAD);
    free(dup_mine);
    free(dup_real);
}

static void crash_test(void)
{
    char    *dup_mine = NULL;
    char    *dup_real = NULL;  
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
        dup_real = strdup(NULL);
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
        dup_mine = ft_strdup(NULL);
        exit(EXIT_FAILURE);
    }
    waitpid(p[1], &status_mine, 0);
    if (status_real == status_mine)
        printf("[CRASH TEST]\tValue:NULL\t%s",GOOD);
    else
        printf("[CRASH TEST]\tValue:NULL\t%s",BAD);
}

void		test_strdup(void)
{
	char 	*src[] = {"copy this string!", "1", "", NULL};
    int     index = 0;

    while (src[index] != NULL)
    {
        loop_test_strdup(src[index]);
        index++;
    }
    crash_test();
}