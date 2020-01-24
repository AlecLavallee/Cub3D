/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:41 by alelaval          #+#    #+#             */
/*   Updated: 2020/01/24 16:31:45 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_putstr("There's no arguments!\n");
	if (ac == 2)
		parsing(av[1]);
	if (ac == 3)
		save();
	if (ac > 3)
		ft_putstr("Too many arguments!\n");
	return (0);
}
