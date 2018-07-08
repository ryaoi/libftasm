/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:56:22 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 15:22:49 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_strlen(void)
{
	int len = ft_strlen("AAAAAAA\0");
	int len_real = strlen("AAAAAAA\0");
	printf("[Value:%s]\tmine:%d\treal:%d\t", "AAAAAAA\0", len, len_real);
	if (len == len_real)
		printf(GOOD);
	else
		printf(BAD);
	len = ft_strlen("\0");
	len_real = strlen("\0");
	printf("[Value:%s]\tmine:%d\treal:%d\t", "\0", len, len_real);
	if (len == len_real)
		printf(GOOD);
	else
		printf(BAD);
}
