/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 01:39:22 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/29 05:30:15 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		raycast(t_cub *cub)
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
