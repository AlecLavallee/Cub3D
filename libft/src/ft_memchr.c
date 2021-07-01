/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:30:48 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 19:09:29 by user42           ###   ########.fr       */
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
		copy = (unsigned char *)s;
		while (n--)
		{
			if (*copy == stop)
				return ((void *)copy);
			copy++;
		}
	}
	return (NULL);
}
