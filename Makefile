# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/03 18:35:47 by ryaoi             #+#    #+#              #
#    Updated: 2018/07/08 16:07:33 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libfts.a

SRC			= ft_isalpha.s \
			  ft_isdigit.s \
			  ft_isascii.s \
			  ft_isalnum.s \
			  ft_toupper.s \
			  ft_tolower.s \
			  ft_isprint.s \
			  ft_bzero.s \
			  ft_strcat.s \
			  ft_puts.s \
			  ft_strlen.s \
			  ft_memset.s \
			  ft_memcpy.s \
			  ft_strcpy.s \
			  ft_strdup.s

OBJ			= $(addprefix $(OBJ_DIR), $(SRC:%.s=%.o))


HEADER		= ./libfts.h

SRC_DIR  	= ./src/
OBJ_DIR		= ./obj/


$(OBJ_DIR)%.o: $(SRC_DIR)%.s $(HEADER)
	nasm -fmacho64 $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -rf $(OBJ)
	
fclean: clean
		rm -rf $(NAME)

re: fclean all
