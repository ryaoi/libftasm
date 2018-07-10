/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:39:18 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/10 15:43:47 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		test_putstr(void)
{
	printf("1st test:\n");
	ft_putstr("TESTING PUT WITHOUT NEWLINE!");
	printf("2nd test:\n");
	ft_putstr(" AND HERE IS THE NEWLINE!\n");
	printf("3rd test with NULL\n");
	ft_putstr(NULL);
}
