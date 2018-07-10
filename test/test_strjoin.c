/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:35:49 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/10 15:38:43 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_strjoin(void)
{
	char	*joined;

	joined = ft_strjoin("abcd", "efgh");
	printf("Param s1:%s | s2:%s -> %s\n", "abcd", "efgh", joined);
	free(joined);
	joined = ft_strjoin("abcd", NULL);
	printf("Param s1:%s | s2:%s -> %s\n", "abcd", NULL, joined);
	joined = ft_strjoin(NULL, "efgh");
	printf("Param s1:%s | s2:%s -> %s\n", NULL, "efgh", joined);
}
