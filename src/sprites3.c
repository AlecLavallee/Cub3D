/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:16:21 by alelaval          #+#    #+#             */
/*   Updated: 2020/10/28 17:17:57 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned	get_color_sprite(t_cub *cub)
{
	t_texture	*tex_ptr;
	int			*color_ptr;
	int			color;

	tex_ptr = &cub->map.textures.sprite;
	color_ptr = (int*)mlx_get_data_addr(tex_ptr->image.img_ptr,
	&tex_ptr->image.bpp, &tex_ptr->image.linesize, &tex_ptr->image.endian);
	color = (int)(color_ptr[TEX_WIDTH * cub->camera.texy + cub->camera.texx]);
	return (color);
}

void		draw_sprite_pixel(t_cub *cub, int x, int y, unsigned color)
{
	unsigned	*img_data;
	int			bpp;
	int			size_line;
	int			endian;

	img_data = (unsigned*)mlx_get_data_addr(cub->image.img_ptr, \
	&bpp, &size_line, &endian);
	img_data[(y * size_line / 4) + x] = (unsigned)color;
}

void		draw_textured_sprite(t_cub *cub, int stripe)
{
	int			y;
	unsigned	color;

	y = cub->sprite.drawstarty;
	while (y < cub->sprite.drawendy)
	{
		cub->camera.texy = (y) * 256 - cub->mlx.screenheight * 128
		+ cub->sprite.spriteheight * 128;
		cub->camera.texy = ((cub->camera.texy * TEX_HEIGHT)
		/ cub->sprite.spriteheight) / 256;
		color = get_color_sprite(cub);
		if ((color & 0x00FFFFFF) != 0)
			draw_sprite_pixel(cub, stripe, y, color);
		y++;
	}
}
