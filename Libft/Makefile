# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbook <macbook@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 14:36:45 by alelaval          #+#    #+#              #
#    Updated: 2020/08/20 12:16:44 by macbook          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -I$(INCLUDE)
CFLAGS += -g

AR = ar
AR_FLAGS = -crs

RM = rm -rf
MKDIR = mkdir -p
MAKE = make -C -s

INCLUDE = headers/
HEADERS = $(addprefix $(INCLUDE), \
libft.h)

PATH_BUILD = build/
PATH_SRC = src/
SRC = $(addprefix $(PATH_SRC), ft_isascii.c \
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
	  ft_isspace.c \
	  ft_strcmp.c \
	  get_next_line.c \
	  get_next_line_utils.c)

$(PATH_BUILD)%.o: $(PATH_SRC)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
	
OBJ = $(addprefix $(PATH_BUILD), $(notdir $(SRC:.c=.o)))

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(PATH_BUILD) $(OBJ)
	$(AR) $(AR_FLAGS) $@ $(OBJ)

$(PATH_BUILD):
	$(MKDIR) $(PATH_BUILD)

clean:
	$(RM) $(PATH_BUILD)

fclean: clean
	$(RM) $(NAME)

re: fclean all
