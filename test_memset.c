/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:52:45 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 15:22:45 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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

}