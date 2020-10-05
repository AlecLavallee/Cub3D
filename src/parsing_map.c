/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/10/05 18:04:26 by alelaval         ###   ########.fr       */
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

void	ft_set_orient(t_cub *cub, t_vec_d dir, t_vec_d plane)
{
	cub->camera.dirx = dir.x;
	cub->camera.diry = dir.y;
	cub->camera.planex = plane.x;
	cub->camera.planey = plane.y;
}

void	set_orientation(t_cub *cub, char c)
{
	if (c == 'N')
		ft_set_orient(cub, (t_vec_d){-1.0, 0.0}, (t_vec_d){0.0, 0.66});
	if (c == 'S')
		ft_set_orient(cub, (t_vec_d){1.0, 0.0}, (t_vec_d){0.0, -0.66});
	if (c == 'W')
		ft_set_orient(cub, (t_vec_d){0.0, -1.0}, (t_vec_d){-0.66, 0.0});
	if (c == 'E')
		ft_set_orient(cub, (t_vec_d){0.0, 1.0}, (t_vec_d){0.66, 0.0});
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
			set_orientation(cub, ref->map[i]);
			ref->map[i] = '0';
		}
		line[i] = ref->map[i] - 48;
		i++;
	}
	while (i < max)
		line[i++] = ' ' - 48;
	return (line);
}
