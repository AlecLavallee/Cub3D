/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:28:28 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/09 14:33:42 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*tmp;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len++])
		;
	if (!(tmp = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	while (len--)
		tmp[len] = s[len];
	return (tmp);
}
