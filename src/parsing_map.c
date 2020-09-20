/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/20 21:27:23 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		get_index_map(t_map *ref)
{
	int	size;

	size = 0;
	while (ref->next != NULL)
	{
		ref = ref->next;
		size++;
	}
	return (size);
}

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
		while (ref->map[len] != '\0')
			len++;
		ref = ref->next;
	}
	return (max_len);
}

int		*store_line_map(t_cub *cub, t_map *ref, int max)
{
	int	i;
	int	*line;

	i = 0;
	if ((line = (int*)malloc(sizeof(int) * max)) == NULL)
		display_error(cub, "Critical error when allocation map!");
	while (ref->map[i] < max && ref->map[i] != '\n')
	{
		line[i] = ref->map[i];
		i++;
		max++;
	}
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
		if ((map[i] = (int*)malloc(sizeof(int) * max - 1)) == NULL)
			display_error(cub, "Critical error when allocation map!");
		i++;
	}
	return (map);
}

void	create_map(t_cub *cub, t_map **map)
{
	int	max;
	int	index;

	max = get_max_len(*map);
	index = get_index_map(*map);
	cub->map.map = allocate_map(cub, index, max);
	while (map[0]->next != NULL)
	{
		cub->map.map[index] = store_line_map(cub, *map, max);
		index++;
	}
}
