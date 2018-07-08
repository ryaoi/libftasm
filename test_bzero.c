/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:52:10 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 14:55:01 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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

}