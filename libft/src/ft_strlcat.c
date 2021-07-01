/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:53:33 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 19:03:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strnlen(char *str, size_t len)
{
	char	*start;

	if (!str)
		return (0);
	start = str;
	while (len-- && *str)
		str++;
	return (str - start);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		srclen;
	size_t		destlen;

	srclen = ft_strlen(src);
	destlen = ft_strnlen(dst, dstsize);
	dstsize -= destlen;
	if (!src || !dst || dstsize == 0)
		return (destlen + srclen);
	dst += destlen;
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (destlen + srclen);
}
