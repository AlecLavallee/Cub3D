/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 01:26:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/29 01:27:35 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_sprite(t_cub *cub, int i, int j)
{
	if (i == 0 || j == 0)
		display_error(cub, "Map not closed!");
	if (i >= cub->map.ysize - 1 || j >= cub->map.xsize - 1)
		display_error(cub, "Map not closed!");
	if (cub->map.map[i - 1][j] == (' ' - 48))
		display_error(cub, "Map not closed!");
	if (cub->map.map[i + 1][j] == (' ' - 48))
		display_error(cub, "Map not closed!");
	if (cub->map.map[i][j - 1] == (' ' - 48))
		display_error(cub, "Map not closed!");
	if (cub->map.map[i][j + 1] == (' ' - 48))
		display_error(cub, "Map not closed!");
}

void	check_tile(t_cub *cub, int i, int j)
{
	if (i == 0 || j == 0)
		display_error(cub, "Map not closed!");
	if (i >= cub->map.ysize - 1 || j >= cub->map.xsize - 1)
		display_error(cub, "Map not closed!");
	if (cub->map.map[i - 1][j] != 1 && cub->map.map[i - 1][j] != 0
		&& cub->map.map[i - 1][j] != 2)
		display_error(cub, "Map not closed!");
	if (cub->map.map[i + 1][j] != 1 && cub->map.map[i + 1][j] != 0
		&& cub->map.map[i + 1][j] != 2)
		display_error(cub, "Map not closed!");
	if (cub->map.map[i][j - 1] != 1 && cub->map.map[i][j - 1] != 0
		&& cub->map.map[i][j - 1] != 2)
		display_error(cub, "Map not closed!");
	if (cub->map.map[i][j + 1] != 1 && cub->map.map[i][j + 1] != 0
		&& cub->map.map[i][j + 1] != 2)
		display_error(cub, "Map not closed!");
}

void	check_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cub->map.ysize)
	{
		while (j < cub->map.xsize)
		{
			if (cub->map.map[i][j] == 0)
				check_tile(cub, i, j);
			if (cub->map.map[i][j] == 2)
				check_sprite(cub, i, j);
			if (cub->map.map[i][j] != 0 && cub->map.map[i][j] != 1
				&& cub->map.map[i][j] != 2)
				cub->map.map[i][j] = 1;
			j++;
		}
		j = 0;
		i++;
	}
}
