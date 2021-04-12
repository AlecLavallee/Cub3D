/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 01:26:57 by alelaval          #+#    #+#             */
/*   Updated: 2021/04/12 16:10:39 by user42           ###   ########.fr       */
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

int		**allocate_map(t_cub *cub, int index, int max)
{
	int	i;
	int	**map;

	i = 0;
	if (index <= 0 || max <= 0)
		display_error(cub, "Critical error when allocating map!");
	if ((map = (int**)malloc(sizeof(int*) * (index + 1))) == NULL)
		display_error(cub, "Critical error when allocating map!");
	while (i < index)
	{
		map[i] = NULL;
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	create_map(t_cub *cub, t_map **map)
{
	int		index;
	void	*prev;

	index = 0;
	cub->map.xsize = get_max_len(*map);
	cub->map.map = allocate_map(cub, cub->map.ysize, cub->map.xsize);
	while (map[0] != NULL)
	{
		cub->map.map[index] = store_line_map(cub, map[0], index);
		free(map[0]->map);
		prev = map[0];
		map[0] = map[0]->next;
		free(prev);
		index++;
	}
	free(map[0]);
	check_map(cub);
}
