/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:23:41 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 17:20:10 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_memcpy(void)
{
	char	buffer1[500];
	char	buffer2[500];

	bzero(buffer1, 500);
	bzero(buffer2, 500);
	char 	*src = "copy this string!\0";
	ft_memcpy(buffer1, src, strlen(src));
	memcpy(buffer2, src, strlen(src));
	printf("Src: %s n:%lu | \t mine:%s real:%s\t", src, strlen(src), buffer1, buffer2);
	if (strcmp(buffer1, buffer2) == 0)
		printf(GOOD);
	else
		printf(BAD);
	bzero(buffer1, 500);
	bzero(buffer2, 500);
	ft_memcpy(buffer1, src, 4);
	memcpy(buffer2, src, 4);
	printf("Src: %s n:%d  | \t mine:%s real:%s\t", src, 4, buffer1, buffer2);
	if (strcmp(buffer1, buffer2) == 0)
		printf(GOOD);
	else
		printf(BAD);

}