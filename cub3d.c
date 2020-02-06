/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:41 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/06 13:39:37 by alelaval         ###   ########.fr       */
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
		printf("Resolution : x = %d, y = %d\n", cub->x_axis, cub->y_axis);
		printf("Colors : floor = %d,%d,%d and ceiling = %d,%d,%d\n", cub->floor[0], cub->floor[1], cub->floor[2], cub->ceiling[0], cub->ceiling[1], cub->ceiling[2]);
	}
	if (ac == 3)
		save();
	if (ac > 3)
		display_error("Too many arguments!");
	return (0);
}
