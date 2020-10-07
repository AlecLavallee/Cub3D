/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:16:47 by alelaval          #+#    #+#             */
/*   Updated: 2020/10/07 17:10:39 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_swap(t_s *x1, t_s *x2)
{
	t_s	x3;

	x3 = *x1;
	*x1 = *x2;
	*x2 = x3;
}

int		count_sprites(t_cub *cub)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < cub->map.ysize)
	{
		j = -1;
		while (++j < cub->map.xsize)
			if (cub->map.map[i][j] == 2)
				count++;
	}
	return (count);
}

double	get_sprite_dist(t_cub *cub, t_vec_d pos)
{
	return ((cub->camera.posx - pos.x)\
		* (cub->camera.posx - pos.x)\
		+ (cub->camera.posy - pos.y)\
		* (cub->camera.posy - pos.y));
}

t_s		*get_sprites(t_cub *cub)
{
	t_s		*sprites;
	int		count;
	int		i;
	int		j;

	count = count_sprites(cub);
	cub->sprite.numsprites = count;
	if (!(sprites = (t_s*)malloc(sizeof(t_s) * count)))
		return (NULL);
	i = 0;
	while (i < cub->map.ysize)
	{
		j = 0;
		while (j < cub->map.xsize)
		{
			if (cub->map.map[i][j] == 2)
			{
				sprites[--count].pos = (t_vec_d){j + 0.5, i + 0.5};
				sprites[count].dist = get_sprite_dist(cub, sprites[count].pos);
			}
			j++;
		}
		i++;
	}
	return (sprites);
}

void	combsort_sprites(t_s *sprites, int len)
{
	int		i;

	i = 0;
	while (i + 1 < len)
	{
		if (sprites[i].dist < sprites[i + 1].dist)
		{
			ft_swap(&sprites[i], &sprites[i + 1]);
			i = 0;
		}
		i++;
	}
}
