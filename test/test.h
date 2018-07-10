/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:54:27 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/10 16:10:38 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST
#define TEST

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>
#include <strings.h>
#include <fcntl.h>
#include "../libfts.h"

#define GOOD  "\033[1;32m[GOOD]\n\033[0m"
#define BAD "\033[1;31m[BAD]\n\033[0m"

void	test_bzero(void);
void	test_memset(void);
void	test_strcat(void);
void	test_strlen(void);
void	test_puts(void);
void	test_memcpy(void);
void	test_strdup(void);
void	test_strjoin(void);
void	test_putstr(void);
void	test_strcpy(void);
void	test_strncpy(void);

#endif
