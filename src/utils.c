/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:37:52 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/29 05:31:42 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void		set_textures(t_cub *cub)
{
	cub->image.img_ptr = NULL;
	cub->image.img_data = NULL;
	cub->map.textures.no.image.img_ptr = NULL;
	cub->map.textures.no.image.img_data = NULL;
	cub->map.textures.so.image.img_ptr = NULL;
	cub->map.textures.so.image.img_data = NULL;
	cub->map.textures.we.image.img_ptr = NULL;
	cub->map.textures.we.image.img_data = NULL;
	cub->map.textures.ea.image.img_ptr = NULL;
	cub->map.textures.ea.image.img_data = NULL;
	cub->map.textures.sprite.image.img_ptr = NULL;
	cub->map.textures.sprite.image.img_data = NULL;
}

t_cub		*init_cub(t_cub *cub)
{
	cub->flags = 0;
	set_textures(cub);
	cub->map.map = NULL;
	cub->map.line = NULL;
	cub->mlx.window = NULL;
	cub->camera.dirx = -1.0;
	cub->camera.diry = 0.0;
	cub->camera.planex = 0.0;
	cub->camera.planey = 0.66;
	cub->camera.hit = 0;
	cub->camera.rotspeed = 0.15;
	cub->player.movespeed = 0.15;
	return (cub);
}

void		get_tex_num(t_cub *cub)
{
	if (cub->camera.side == 0 && cub->camera.raydirx > 0)
		cub->camera.texnum = 0;
	else if (cub->camera.side == 0 && cub->camera.raydirx < 0)
		cub->camera.texnum = 1;
	else if (cub->camera.side == 1 && cub->camera.raydiry > 0)
		cub->camera.texnum = 2;
	else
		cub->camera.texnum = 3;
}

unsigned	get_color_rgb(unsigned char *color)
{
	unsigned ret_color;

	ret_color = 0;
	ret_color += color[0];
	ret_color += color[1];
	ret_color += color[2];
	return (ret_color);
}
