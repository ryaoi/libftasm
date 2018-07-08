/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_puts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:23:11 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 15:23:19 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_puts(void)
{
	int		ret;
	int		ret_real;
	
	ret = ft_puts("testing puts!");
	ret_real = puts("testing puts!");
	printf("mine :%d\t real:%d\n", ret, ret_real);
	if (ret == ret_real)
		printf(GOOD);
	else
		printf(BAD);

	ret = ft_puts("");
	ret_real = puts("");
	printf("mine :%d\t real:%d\n", ret, ret_real);
	if (ret == ret_real)
		printf(GOOD);
	else
		printf(BAD);
}
