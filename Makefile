# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 14:36:45 by alelaval          #+#    #+#              #
#    Updated: 2020/09/18 16:33:57 by alelaval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

MKDIR = mkdir -p
MAKE = make -s -C
MAKE_BONUS = make bonus -s -C 
RM = rm -rf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I headers/
CFLAGS += -I $(LIBFT_PTH)headers/
CFLAGS += -I /usr/X11/include
CFLAGS += -g
LFLAGS = -L$(LIBFT_PTH) -lft
LFLAGS += -lmlx -framework OpenGL -framework AppKit

LIBFT_PTH = libft/
LIBFT = $(addprefix $(LIBFT_PTH), libft.a)

PATH_S = src/
SRC = $(addprefix $(PATH_S), \
	mlx.c \
	parsing_map.c \
	parsing.c \
	parsing2.c \
	colors.c \
	flood.c \
	free.c \
	mvmt.c \
	raycast.c \
	raycast2.c \
	loader.c \
	utils.c \
	save.c \
	error.c \
	cub3d.c)

PATH_B = build/
OBJ = $(addprefix $(PATH_B), $(notdir $(SRC:.c=.o)))

.PHONY: all clean fclean re
all: $(LIBFT) $(PATH_B) $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@ $(LFLAGS)

$(PATH_B)%.o: $(PATH_S)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE_BONUS) $(LIBFT_PTH)

$(PATH_B):
	$(MKDIR) build/
	
clean:
	$(RM) $(PATH_B) && $(MAKE) $(LIBFT_PTH) clean

fclean: clean
	$(RM) $(NAME) && $(MAKE) $(LIBFT_PTH) fclean

re: fclean all
