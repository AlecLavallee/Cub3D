/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:30:48 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/09 14:36:22 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	stop;
	unsigned char	*copy;

	if (s)
	{
		stop = c;
		copy = (unsigned char*)s;
		while (n--)
		{
			if (*copy == stop)
				return ((void *)copy);
			copy++;
		}
	}
	return (NULL);
}
