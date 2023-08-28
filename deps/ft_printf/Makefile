# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifern <davifern@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 19:25:49 by davifern          #+#    #+#              #
#    Updated: 2023/01/25 22:13:58 by davifern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
SRC = ft_printf.c ft_utils_numbers.c ft_utils_text.c ft_putnbr.c ft_strlen.c ft_converter.c ft_putnbr_uint.c
CFLAGS += -Wextra -Werror -Wall -g
OBJ = $(SRC:.c=.o)
CC = gcc

all: $(NAME)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(HEADER) $(OBJ)
	@ar -rcs $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.gch

re: fclean all

.PHONY: all bonus clean fclean re
