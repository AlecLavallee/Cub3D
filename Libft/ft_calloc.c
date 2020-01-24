/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:28:09 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/08 09:35:03 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			memsize;
	unsigned char	*ptr;

	memsize = count * size;
	if (!(ptr = (unsigned char*)malloc(memsize)))
		return (NULL);
	while (memsize--)
		ptr[memsize] = 0;
	return ((void*)ptr);
}
