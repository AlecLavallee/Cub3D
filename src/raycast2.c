/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/10/05 15:01:23 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		text_calc(t_cub *cub)
{
	if (cub->camera.side == 0)
		cub->camera.wallx = cub->camera.posy + cub->camera.perpwalldist
		* cub->camera.raydiry;
	else
		cub->camera.wallx = cub->camera.posx + cub->camera.perpwalldist
		* cub->camera.raydirx;
	cub->camera.wallx -= floor(cub->camera.wallx);
	cub->camera.texx = (int)(cub->camera.wallx * (double)TEX_WIDTH);
	if (cub->camera.side == 0 && cub->camera.raydirx > 0)
		cub->camera.texx = TEX_WIDTH - cub->camera.texx - 1;
	if (cub->camera.side == 1 && cub->camera.raydiry < 0)
		cub->camera.texx = TEX_WIDTH - cub->camera.texx - 1;
	cub->camera.step = 1.0 * TEX_HEIGHT / cub->camera.lineheight;
	cub->camera.texpos = (double)(cub->camera.drawstart -
	cub->mlx.screenheight / 2 + cub->camera.lineheight / 2) * cub->camera.step;
}

void		draw_scanline(t_cub *cub, int x, t_vec limit, int color)
{
	unsigned	*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;

	img_ptr = (unsigned*)mlx_get_data_addr(cub->image.img_ptr,
	&bpp, &size_line, &endian);
	while (limit.x++ < limit.y)
		img_ptr[(limit.x * size_line / 4) + x] = color;
}

unsigned	get_color_row(t_cub *cub)
{
	t_texture	*tex_ptr;
	unsigned	*color_ptr;
	unsigned	color;

	tex_ptr = get_tex_ptr(cub, cub->camera.texnum);
	color_ptr = (unsigned*)mlx_get_data_addr(tex_ptr->image.img_ptr,
	&tex_ptr->image.bpp, &tex_ptr->image.linesize, &tex_ptr->image.endian);
	color = \
	(unsigned)(color_ptr[TEX_HEIGHT * cub->camera.texy + cub->camera.texx]);
	if (cub->camera.side == 1)
		color = (unsigned)(color >> 1) & 8355711;
	return (color);
}

void		draw_textured_row(t_cub *cub, int x, int y)
{
	unsigned	*img_data;
	int			bpp;
	int			size_line;
	int			endian;

	img_data = (unsigned*)mlx_get_data_addr(cub->image.img_ptr, \
	&bpp, &size_line, &endian);
	img_data[(y * size_line / 4) + x] = (unsigned)get_color_row(cub);
}

void		draw(t_cub *cub, int x)
{
	int		y;
	int		height;
	int		begin;
	int		end;

	y = cub->camera.drawstart;
	height = (int)(cub->mlx.screenheight / cub->camera.perpwalldist);
	begin = -height / 2 + cub->mlx.screenheight / 2;
	end = 0;
	if (begin < 0)
		begin = 0;
	draw_scanline(cub, x, (t_vec){0, begin - 1},
	get_color_rgb(cub->map.colorceiling));
	while (y++ < cub->camera.drawend)
	{
		cub->camera.texy = (int)cub->camera.texpos & (TEX_HEIGHT - 1);
		cub->camera.texpos += cub->camera.step;
		end = height / 2 + cub->mlx.screenheight / 2;
		if (end >= cub->mlx.screenheight)
			end = cub->mlx.screenheight - 1;
		draw_textured_row(cub, x, y);
	}
	draw_scanline(cub, x, (t_vec){end + 1, cub->mlx.screenheight - 1}, \
		get_color_rgb(cub->map.colorfloor));
}
