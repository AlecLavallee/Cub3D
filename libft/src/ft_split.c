/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:32:07 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/14 17:24:56 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		number(const char *s, char c)
{
	int	i;
	int	sub;

	i = 0;
	sub = 0;
	while (*s)
	{
		if (sub == 1 && *s == c)
			sub = 0;
		if (sub == 0 && *s != c)
		{
			sub = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static int		size(const char *s, char c)
{
	int	size;

	size = 0;
	while (*s != c && *s != '\0')
	{
		size++;
		s++;
	}
	return (size);
}

static char		**panic(char **tab, int index)
{
	while (index--)
		free(tab[index]);
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_word;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	nb_word = number((const char *)s, c);
	tab = (char **)malloc(sizeof(*tab) * (number((const char *)s, c) + 1));
	if (!tab)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s)
			s++;
		tab[index] = ft_substr((const char *)s, 0, size((const char *)s, c));
		if (!tab[index])
			return (panic(tab, index));
		s = s + size(s, c);
		index++;
	}
	tab[index] = NULL;
	return (tab);
}
