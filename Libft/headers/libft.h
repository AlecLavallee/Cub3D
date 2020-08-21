/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:59:44 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/10 12:07:01 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef LIBFT_H
#	define LIBFT_H
#	include <stdlib.h>
#	include <unistd.h>
#	include "get_next_line.h"

typedef struct		s_map
{
	char			*map;
	struct s_map	*prev;
	struct s_map	*next;
}					t_map;

int				ft_lstsize(t_map *lst);
t_map			*ft_lstnew(void *content);
t_map			*ft_lstlast(t_map *lst);
t_map			*ft_lstmap(t_map *lst, void *(*f)(void*)
				, void (*del)(void *));
void			ft_lstadd_front(t_map **alst, t_map *new);
void			ft_lstadd_back(t_map **alst, t_map *new);
void			ft_lstdelone(t_map *lst, void (*del)(void *));
void			ft_lstclear(t_map **lst, void (*del)(void *));
void			ft_lstiter(t_map *lst, void (*f)(void *));
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strnstr(const char *h, const char *n, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/* added functions*/
void			ft_putstr(char* str);
void			ft_putchar(char c);
int				ft_isspace(int c);
int				ft_strcmp(const char *s1, const char *s2);
#	endif
