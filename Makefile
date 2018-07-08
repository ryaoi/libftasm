# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/03 18:35:47 by ryaoi             #+#    #+#              #
#    Updated: 2018/07/08 13:55:24 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libfts.a

SRC_LIB		= ./ft_isalpha.s \
			  ./ft_isdigit.s \
			  ./ft_isascii.s \
			  ./ft_isalnum.s \
			  ./ft_toupper.s \
			  ./ft_tolower.s \
			  ./ft_isprint.s \
			  ./ft_bzero.s \
			  ./ft_strcat.s \
			  ./ft_puts.s \
			  ./ft_strlen.s \
			  ./ft_memset.s \
			  ./ft_memcpy.s \
			  ./ft_strdup.s

OBJ_LIB		= $(SRC_LIB:.s=.o)

%.o:%.s
	nasm -fmacho64 $< -o $@

all: $(NAME)

$(NAME):$(OBJ_LIB)
		ar rc $(NAME) $(OBJ_LIB)
		ranlib $(NAME)

clean:
		rm -rf $(OBJ_LIB)
	
fclean: clean
		rm -rf $(NAME)

re: fclean all
