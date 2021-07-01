/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:54:40 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 19:25:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	*tmp;
	size_t			i;

	if (dst && src)
	{
		tmp = (unsigned char *)(malloc(sizeof(unsigned char) * len));
		if (tmp == NULL)
			return (NULL);
		i = len;
		s1 = dst;
		s2 = (unsigned char *)src;
		while (len--)
			tmp[len] = s2[len];
		while (i--)
			s1[i] = tmp[i];
		free(tmp);
	}
	return (dst);
}
