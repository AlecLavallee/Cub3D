/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:37:52 by alelaval          #+#    #+#             */
/*   Updated: 2021/04/21 16:01:37 by user42           ###   ########.fr       */
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
	cub->player.movespeed = 0.20;
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
	unsigned			ret_color;
	unsigned char		*bytes_color;

	ret_color = 0;
	bytes_color = (unsigned char*)&ret_color;
	bytes_color[0] = color[2];
	bytes_color[1] = color[1];
	bytes_color[2] = color[0];
	return (ret_color);
}

void		check_screen_size(t_cub *cub)
{
	int x;
	int y;

	x = cub->mlx.screenwidth;
	y = cub->mlx.screenheight;
	mlx_get_screen_size(cub->mlx.mlx, &x, &y);
	if (x <= cub->mlx.screenwidth)
		cub->mlx.screenwidth = x;
	if (y <= cub->mlx.screenheight)
		cub->mlx.screenheight = y;
	if (cub->mlx.screenwidth <= 50)
		cub->mlx.screenwidth = 50;
	if (cub->mlx.screenheight <= 50)
		cub->mlx.screenheight = 50;
}
