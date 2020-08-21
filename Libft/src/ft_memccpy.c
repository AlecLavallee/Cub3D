/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:44:46 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/11 16:15:04 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	stop;
	unsigned char	*s1;
	unsigned char	*s2;

	if (dst && src)
	{
		stop = c;
		s1 = dst;
		s2 = (unsigned char*)src;
		while (n--)
		{
			*s1 = *s2++;
			if (*s1++ == stop)
				return ((void*)s1);
		}
	}
	return (NULL);
}
