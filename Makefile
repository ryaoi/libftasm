# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/03 18:35:47 by ryaoi             #+#    #+#              #
#    Updated: 2018/07/10 18:05:07 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libfts.a
TEST_NAME	= test_libfts

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
			  ft_strncpy.s \
			  ft_strdup.s \
			  ft_cat.s \
			  ft_putstr.s \
			  ft_strjoin.s \
			  ft_strsub.s

TEST		= main.c \
			  test_bzero.c \
			  test_memcpy.c \
			  test_memset.c \
			  test_puts.c \
			  test_strcat.c \
			  test_strdup.c \
			  test_strlen.c \
			  test_strjoin.c \
			  test_putstr.c \
			  test_strcpy.c \
			  test_strncpy.c \
			  test_strsub.c

OBJ			= $(addprefix $(OBJ_DIR), $(SRC:%.s=%.o))

OBJ_TEST	= $(addprefix $(OBJ_TEST_DIR), $(TEST:%.c=%.o))

HEADER		= ./libfts.h
HEADER_TEST = ./test/test.h

SRC_DIR  	= ./src/
OBJ_DIR		= ./obj/
OBJ_TEST_DIR	= ./test/

$(OBJ_DIR)%.o: $(SRC_DIR)%.s $(HEADER)
	@mkdir -p $(OBJ_DIR)
	nasm -fmacho64 $< -o $@

$(OBJ_TEST_DIR)%.o : $(OBJ_TEST_DIR)%.c $(HEADER_TEST)
	gcc -Wall -Wextra -Werror -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJ) $(HEADER) $(OBJ_TEST) $(HEADER_TEST)
		ar rc $(NAME) $(OBJ) $(HEADER)
		ranlib $(NAME)
		gcc -Wall -Wextra -Werror $(OBJ_TEST) -o $(TEST_NAME) -L. -lfts

clean:
		rm -rf $(OBJ) $(OBJ_TEST)
	
fclean: clean
		rm -rf $(NAME) $(TEST_NAME)

re: fclean all
