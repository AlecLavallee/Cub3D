/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 01:39:22 by alelaval          #+#    #+#             */
/*   Updated: 2020/10/05 15:12:10 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_tex_ptr(t_cub *cub, int index)
{
	if (index == 0)
		return (&cub->map.textures.no);
	if (index == 1)
		return (&cub->map.textures.so);
	if (index == 2)
		return (&cub->map.textures.we);
	if (index == 3)
		return (&cub->map.textures.ea);
	if (index == 4)
		return (&cub->map.textures.sprite);
	return (NULL);
}

int			raycast(t_cub *cub)
{
	int	i;

	i = 0;
	mlx_clear_img(cub->image.img_ptr, cub->mlx.screenheight);
	player_move(cub);
	while (i < cub->mlx.screenwidth)
	{
		cub->camera.hit = 0;
		cub->camera.camerax = (2 * i / (double)cub->mlx.screenwidth - 1);
		ray_init(cub);
		raycast_init(cub);
		dda(cub);
		perp_wall_dist(cub);
		draw_calc(cub);
		text_calc(cub);
		get_tex_num(cub);
		draw(cub, i++);
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.window, \
	cub->image.img_ptr, 0, 0);
	return (0);
}
