/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/24 06:13:57 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		get_max_len(t_map *ref)
{
	int	len;
	int	max_len;

	len = 0;
	max_len = 0;
	while (ref->next != NULL)
	{
		if (max_len < len)
			max_len = len;
		len = 0;
		while (ref->map[len] != '\0')
			len++;
		ref = ref->next;
	}
	return (max_len);
}

int		*store_line_map(t_cub *cub, t_map *ref, int index)
{
	int	i;
	int	*line;
	int	max;

	i = 0;
	max = cub->map.xsize;
	line = (int*)malloc(sizeof(int) * max);
	while (i < max && ref->map[i] != '\0')
	{
		if (ref->map[i] == 'N' || ref->map[i] == 'S'
			|| ref->map[i] == 'E' || ref->map[i] == 'W')
		{
			cub->camera.posX = (double)index;
			cub->camera.posX += 0.5;
			cub->camera.posY = (double)i;
			cub->camera.posY -= 0.5;
			ref->map[i] = '0';
		}
		line[i] = ref->map[i] - 48;
		i++;
	}
	while (i < max)
		line[i++] = ' ' - 48;
	return (line);
}

int		**allocate_map(t_cub *cub, int index, int max)
{
	int	i;
	int	**map;

	i = 0;
	if (index <= 0 || max <= 0)
		display_error(cub, "Critical error when allocation map!");
	if ((map = (int**)malloc(sizeof(int*) * index)) == NULL)
		display_error(cub, "Critical error when allocation map!");
	while (i < index)
	{
		if ((map[i] = (int*)malloc(sizeof(int) * max)) == NULL)
			display_error(cub, "Critical error when allocation map!");
		i++;
	}
	return (map);
}

void	print_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cub->map.ysize)
	{
		while (j < cub->map.xsize)
		{
			ft_putchar(cub->map.map[i][j] + 48);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

void	check_sprite(t_cub *cub, int i, int j)
{
	// a reverifier!
	if (i == 0 || j == 0)
		display_error(cub, "Map not closed!");
	if (i == cub->map.ysize || j == cub->map.xsize)
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
	if (i == cub->map.ysize || j == cub->map.xsize)
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

void	create_map(t_cub *cub, t_map **map)
{
	int	index;

	index = 0;
	cub->map.xsize = get_max_len(*map);
	cub->map.map = allocate_map(cub, cub->map.ysize, cub->map.xsize);
	while (map[0] != NULL)
	{
		cub->map.map[index] = store_line_map(cub, map[0], index);
		map[0] = map[0]->next;
		index++;
	}
	check_map(cub);
}
