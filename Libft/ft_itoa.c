/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:30:03 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/15 11:04:15 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ranks(int n)
{
	unsigned int	nbr;
	size_t			i;

	nbr = (n < 0) ? -n : n;
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t			nb_ranks;
	unsigned int	nbr;
	char			*str;

	nbr = (n < 0) ? -n : n;
	nb_ranks = (n < 0) ? ft_ranks(n) + 1 : ft_ranks(n);
	if (!(str = (char*)malloc(sizeof(char) * (nb_ranks + 1))))
		return (NULL);
	str[nb_ranks] = '\0';
	while (nb_ranks--)
	{
		str[nb_ranks] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
