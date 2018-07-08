/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 13:56:03 by ryaoi             #+#    #+#             */
/*   Updated: 2018/07/08 14:08:01 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS
#define LIBFTS

int 	ft_isalpha(int c);
int 	ft_isdigit(int c);
int 	ft_isascii(int c);
int 	ft_isalnum(int c);
int 	ft_toupper(int c);
int 	ft_tolower(int c);
int 	ft_isprint(int c);
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *restrict s1, const char *restrict s2);
size_t	ft_strlen(const char *s);
int		ft_puts(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char	*ft_strdup(const char *s1);

#endif
