/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:55:22 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 14:55:53 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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

}