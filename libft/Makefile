# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbook <macbook@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 14:36:45 by alelaval          #+#    #+#              #
#    Updated: 2020/09/07 14:33:31 by macbook          ###   ########.fr        #
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

SRC_BONUS = $(addprefix $(PATH_SRC), ft_isascii.c \
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
	  get_next_line_utils.c \
	  ft_lstadd_back_bonus.c \
	  ft_lstadd_front_bonus.c \
	  ft_lstclear_bonus.c \
	  ft_lstdelone_bonus.c \
	  ft_lstiter_bonus.c \
	  ft_lstlast_bonus.c \
	  ft_lstmap_bonus.c \
	  ft_lstnew_bonus.c \
	  ft_lstsize_bonus.c)

$(PATH_BUILD)%.o: $(PATH_SRC)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
	
OBJ = $(addprefix $(PATH_BUILD), $(notdir $(SRC:.c=.o)))

OBJ_BONUS = $(addprefix $(PATH_BUILD), $(notdir $(SRC_BONUS:.c=.o)))

.PHONY: all bonus clean fclean re
all: $(NAME)

$(NAME): $(PATH_BUILD) $(OBJ)
	$(AR) $(AR_FLAGS) $@ $(OBJ)

bonus: $(PATH_BUILD) $(OBJ_BONUS)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJ_BONUS)

$(PATH_BUILD):
	$(MKDIR) $(PATH_BUILD)

clean:
	$(RM) $(PATH_BUILD)

fclean: clean
	$(RM) $(NAME)

re: fclean all
