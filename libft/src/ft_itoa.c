/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:30:03 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 19:43:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ranks(int n)
{
	unsigned int	nbr;
	size_t			i;

	if (n < 0)
		nbr = -n;
	else
		nbr = n;
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

void	no_ternaries(unsigned int *nbr, size_t *nb_ranks, int n)
{
	if (n < 0)
		*nbr = -n;
	else
		*nbr = n;
	if (n < 0)
		*nb_ranks = ft_ranks(n) + 1;
	else
		*nb_ranks = ft_ranks(n);
}

char	*ft_itoa(int n)
{
	size_t			nb_ranks;
	unsigned int	nbr;
	char			*str;

	no_ternaries(&nbr, &nb_ranks, n);
	str = (char *)malloc(sizeof(char) * (nb_ranks + 1));
	if (str == NULL)
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
