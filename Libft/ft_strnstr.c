/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:42:21 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/17 14:15:09 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			found;

	i = -1;
	found = 1;
	if (!ft_strlen(n))
		return ((char *)h);
	while (*(h + ++i) && i < len)
	{
		j = 0;
		if (*(h + i) == *(n + 0))
		{
			k = i;
			found = 1;
			while (*(h + k) && *(n + j) && j < len && k < len)
				if (*(h + k++) != *(n + j++))
					found = 0;
			if (found && !*(n + j))
				return ((char *)h + i);
		}
	}
	return (NULL);
}
