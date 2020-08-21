/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:54:40 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/17 15:44:13 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	tmp[len];
	size_t			i;

	if (dst && src)
	{
		i = len;
		s1 = dst;
		s2 = (unsigned char *)src;
		while (len--)
			tmp[len] = s2[len];
		while (i--)
			s1[i] = tmp[i];
	}
	return (dst);
}
