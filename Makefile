# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 14:36:45 by alelaval          #+#    #+#              #
#    Updated: 2020/01/29 14:32:23 by alelaval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I.

SRC = parsing.c \
	error.c \
	main.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

RM = rm -f

.PHONY: all bonus clean fclean re
all: $(NAME)

$(NAME): $(OBJ)
	make -C Libft/ 
	make -C Minilibx/
	mv Libft/libft.a . 
	mv Minilibx/libmlx.a .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft.a libmlx.a

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

%_bonus.o:%_bonus.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS) libft.a libmlx.a
	#make clean -C Libft/
	#make clean -C Minilibx/

fclean: clean
	$(RM) $(NAME)
	#make fclean -C Libft/
	#make fclean -C Minilibx/

re: fclean all
