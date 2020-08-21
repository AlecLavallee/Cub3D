# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbook <macbook@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 14:36:45 by alelaval          #+#    #+#              #
#    Updated: 2020/08/20 13:04:56 by macbook          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

MKDIR = mkdir -p
MAKE = make -s -C
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
	parsing_file.c \
	parsing.c \
	colors.c \
	flood.c \
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
	$(MAKE) $(LIBFT_PTH)

$(PATH_B):
	$(MKDIR) build/
	
clean:
	$(RM) $(PATH_B) && $(MAKE) $(LIBFT_PTH) clean

fclean: clean
	$(RM) $(NAME) && $(MAKE) $(LIBFT_PTH) fclean

re: fclean all
