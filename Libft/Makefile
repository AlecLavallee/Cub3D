# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 14:36:45 by alelaval          #+#    #+#              #
#    Updated: 2020/01/27 12:56:26 by alelaval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I.
SRC = ft_isascii.c \
  	  ft_memchr.c \
	  ft_putnbr_fd.c \
	  ft_strlcpy.c	\
  	  ft_substr.c \
	  ft_atoi.c \
	  ft_isdigit.c	\
  	  ft_memcmp.c \
	  ft_putstr_fd.c \
	  ft_strlen.c \
	  ft_tolower.c \
	  ft_isprint.c \
  	  ft_memcpy.c \
	  ft_split.c \
  	  ft_strmapi.c \
  	  ft_toupper.c \
	  ft_bzero.c \
  	  ft_itoa.c \
	  ft_memmove.c \
	  ft_strchr.c \
	  ft_strncmp.c \
	  ft_calloc.c \
  	  ft_memset.c \
	  ft_strdup.c \
  	  ft_strnstr.c \
	  ft_isalnum.c \
	  ft_putchar_fd.c \
	  ft_strjoin.c \
	  ft_strrchr.c \
	  ft_isalpha.c \
	  ft_memccpy.c \
	  ft_putendl_fd.c \
	  ft_strlcat.c \
	  ft_strtrim.c \
	  ft_putstr.c \
	  ft_putchar.c \
	  ft_strcmp.c \
	  get_next_line.c \
	  get_next_line_utils.c

SRC_BONUS = ft_lstnew_bonus.c \
	  ft_lstdelone_bonus.c \
	  ft_lstclear_bonus.c \
	  ft_lstadd_front_bonus.c \
	  ft_lstadd_back_bonus.c \
	  ft_lstsize_bonus.c \
	  ft_lstiter_bonus.c \
	  ft_lstmap_bonus.c \
	  ft_lstlast_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

RM = rm -f

.PHONY: all bonus clean fclean re
all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

%_bonus.o:%_bonus.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

bonus: $(OBJ) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
