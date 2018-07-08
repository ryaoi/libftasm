/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:28:53 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 19:18:13 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_strdup(void)
{
    char    *dup_mine = NULL;
    char    *dup_real = NULL;  
	char 	src[500] = "copy this string!";

    dup_mine = ft_strdup(src);
    dup_real = strdup(src);
	printf("[Value:%s]\t", src);
    printf("mine:%s\t", dup_mine);
    printf("real:%s\t", dup_real);
	if (strcmp(dup_mine, dup_real) == 0)
		printf(GOOD);
	else
		printf(BAD);
    free(dup_mine);
    free(dup_real);
}