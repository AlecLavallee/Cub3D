/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/11 09:54:06 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		is_positive;
	long	nbr;

	is_positive = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		is_positive = 1;
	}
	if (is_positive)
		ft_putchar_fd('-', fd);
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + 48, fd);
	}
	if (nbr <= 9)
		ft_putchar_fd(nbr + 48, fd);
}
