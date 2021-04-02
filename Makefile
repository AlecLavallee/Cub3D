# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 14:36:45 by alelaval          #+#    #+#              #
#    Updated: 2021/04/02 11:36:49 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

MKDIR = mkdir -p
MAKE = make -s -C
MAKE_BONUS = make -s -C libft/
MAKE_MLX = make -s -C mlx/
RM = rm -rf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I headers/ -I mlx/ -I libft/headers/
CFLAGS += -g
LFLAGS = -L$(LIBFT_PTH)headers/
LFLAGS = -L$(LIBFT_PTH) -lft
LFLAGS += -Lmlx/ -lmlx_Linux
LFLAGS += -lXext -lX11 -lm

MLX_PTH = mlx/
MLX = $(addprefix $(MLX_PTH), libmlx_Linux.a)

LIBFT_PTH = libft/
LIBFT = $(addprefix $(LIBFT_PTH), libft.a)

PATH_S = src/
SRC = $(addprefix $(PATH_S), \
	mlx.c \
	parsing_map.c \
	parsing_map2.c \
	parsing.c \
	parsing2.c \
	colors.c \
	free.c \
	mvmt.c \
	mvmt2.c \
	raycast.c \
	raycast2.c \
	raycast3.c \
	sprites.c \
	sprites2.c \
	sprites3.c \
	loader.c \
	utils.c \
	save.c \
	save2.c \
	error.c \
	cub3d.c)

PATH_B = build/
OBJ = $(addprefix $(PATH_B), $(notdir $(SRC:.c=.o)))

.PHONY: all clean fclean re
all: $(LIBFT) $(MLX) $(PATH_B) $(NAME)

$(NAME): $(OBJ) 
	$(CC) $^ -o $@ $(LFLAGS)

$(PATH_B)%.o: $(PATH_S)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE_BONUS)

$(MLX):
	$(MAKE_MLX)

$(PATH_B):
	$(MKDIR) build/
	
clean:
	$(RM) $(PATH_B) && $(MAKE) $(LIBFT_PTH) clean
	make clean -s -C mlx/
	make fclean -s -C libft/

fclean: clean
	$(RM) $(NAME) && $(MAKE) $(LIBFT_PTH) fclean

re: fclean all
