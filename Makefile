# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifern <davifern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 13:18:58 by davifern          #+#    #+#              #
#    Updated: 2023/09/23 14:40:31 by davifern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################## VARIABLES DEFINITIONS ###############################
NAME = fractol
MAKE = make --no-print-directory
HEADER = inc/fractol.h
SRC = src/fractals.c src/utils.c src/hooks.c src/main.c src/ft_atof.c
DIR_LIBFT = ./deps/libft/
LIBFT = $(DIR_LIBFT)/libft.a
DIR_PRINTF = ./deps/ft_printf/
PRINTF = $(DIR_PRINTF)/libftprintf.a
CC = gcc
CFLAGS += -Wextra -Werror -Wall -MMD -g -I deps/mlx -I deps/ft_printf -I inc

# This line itself doesn't actually generate the object files; it just sets up the 
# names that will be used when the object files are generated
OBJ = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

################################# RULES ####################################### 
# -C <path> option. This changes the current path to the path '<path>', -s silent
all: 
	$(MAKE) -sC $(DIR_PRINTF)
	$(MAKE) -sC $(DIR_LIBFT)
	$(MAKE) -sC deps/mlx
	$(MAKE) $(NAME)
# This pattern rule tells make how to build a .o file from a corresponding .c file 
# (and ensures that the object files are recompiled if the header file, indicated 
# by $(HEADER), changes). It specifies that the command $(CC) $(CFLAGS) -c $< -o $@ 
# should be used to compile each .c file into a corresponding .o file.
# This is a pattern rule that specifies how to build an object file (.o) from a 
# corresponding source file (.c). It also depends on the $(HEADER) file, meaning the
# object files will be recompiled if the header file changes.
# $(CC) $(CFLAGS) -c $< -o $@: This is the command that actually compiles each .c 
# file into an .o file. $< is the first dependency (the .c file in this case) and $@ 
# is the target (the .o file).
%.o : %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) Makefile $(LIBFT) $(PRINTF)
	$(CC) $(OBJ) -O3 -Ldeps/mlx -lmlx -framework OpenGL -framework AppKit -Ldeps/ft_printf -Ldeps/libft -lftprintf -lft -o $(NAME)

clean:
	rm -f *.out src/*.o src/*.d
	rm -rf *.dSYM
	@$(MAKE) clean -C $(DIR_LIBFT)
	@$(MAKE) clean -C $(DIR_PRINTF)

fclean: clean
	rm -f $(NAME)
	rm -f *.gch

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re