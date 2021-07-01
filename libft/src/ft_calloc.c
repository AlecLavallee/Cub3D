/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:28:09 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 19:27:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			memsize;
	unsigned char	*ptr;

	memsize = count * size;
	ptr = (unsigned char *)malloc(memsize);
	if (ptr == NULL)
		return (NULL);
	while (memsize--)
		ptr[memsize] = 0;
	return ((void *)ptr);
}
