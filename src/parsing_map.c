/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/29 04:53:50 by alelaval         ###   ########.fr       */
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
			cub->camera.posx = (double)index;
			cub->camera.posx += 0.5;
			cub->camera.posy = (double)i;
			cub->camera.posy -= 0.5;
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
