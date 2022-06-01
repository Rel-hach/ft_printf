# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 02:48:27 by rel-hach          #+#    #+#              #
#    Updated: 2021/12/28 06:01:05 by rel-hach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS := -Wall -Werror -Wextra

SRC := ft_printf.c  first_file.c  second_file.c ft_check_flag.c

OBJ := $(SRC:.c=.o) 

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus : all

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re