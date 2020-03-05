/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:41 by alelaval          #+#    #+#             */
/*   Updated: 2020/03/05 10:32:52 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	t_cub	*cub;

	if (!(cub = (t_cub*)malloc(sizeof(t_cub))))
	{
		display_error("Structure affectation failed, critical memory failure!");
		return (-1);
	}
	if (ac == 1)
		display_error("There's no arguments!");
	if (ac == 2)
	{
		parsing(av[1], cub);
	}
	if (ac == 3)
		save();
	if (ac > 3)
		display_error("Too many arguments!");
	return (0);
}
