/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strsub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:45:54 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/10 19:47:56 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_strsub(void)
{
	char	*src = "@@@@Cut this string!@@@@";

	char *result = ft_strsub(src, 4, 16);
	printf("Src: %s start:%d len:%d -> result:%s\n", src, 4, 16, result);
	free(result);
	result = ft_strsub(NULL, 4, 16);
	printf("Src: %s start:%d len:%d -> result:%s\n", NULL, 4, 16, result);
	free(result);
	result = ft_strsub(src, strlen(src), 16);
	printf("Src: %s start:%lu len:%d -> result:%s\n", src, strlen(src), 16, result);
	free(result);
	result = ft_strsub(src, 0, 100);
	printf("Src: %s start:%d len:%d -> result:%s\n", src, 0, 100, result);
	free(result);
}
