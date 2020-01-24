/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:17:46 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/14 13:09:47 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ref;

	if (!s)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ref = str;
	if (start > ft_strlen(s))
	{
		str[0] = '\0';
		return (str);
	}
	while (*(s + start) && len--)
	{
		*str++ = *(s + start);
		start++;
	}
	*str = '\0';
	return (ref);
}
