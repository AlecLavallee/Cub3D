/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:17:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/10/09 17:43:34 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# include <stdio.h>
unsigned	get_color_sprite(t_cub *cub)
{
	t_texture	*tex_ptr;
	unsigned	*color_ptr;
	unsigned	color;

	tex_ptr = get_tex_ptr(cub, 4);
	color_ptr = (unsigned*)mlx_get_data_addr(tex_ptr->image.img_ptr,
	&tex_ptr->image.bpp, &tex_ptr->image.linesize, &tex_ptr->image.endian);
	color = \
	(unsigned)(color_ptr[TEX_HEIGHT * cub->camera.texy + cub->camera.texx]);
	if (cub->camera.side == 1)
		color = (unsigned)(color >> 1) & 8355711;
	return (color);
}

void		draw_sprite_row(t_cub *cub, int x, int y)
{
	unsigned	*img_data;
	int			bpp;
	int			size_line;
	int			endian;

	img_data = (unsigned*)mlx_get_data_addr(cub->image.img_ptr,
	&bpp, &size_line, &endian);
	img_data[(y * size_line / 4) + x] = get_color_sprite(cub);
}

void	sprite_transform(t_cub *cub)
{
	cub->sprite.invdet = 1.0 / (cub->camera.planex * cub->camera.diry - cub->camera.dirx * cub->camera.planey);
	printf("invdet : %f\n", cub->sprite.invdet);
	cub->sprite.transformx = cub->sprite.invdet * (cub->camera.diry * cub->sprite.spritex - cub->camera.dirx * cub->sprite.spritey);
	cub->sprite.transformy = cub->sprite.invdet * (-cub->camera.planey * cub->sprite.spritex + cub->camera.planex * cub->sprite.spritey);
	printf("transformx : %f, transformy : %f\n", cub->sprite.transformx, cub->sprite.transformy);
}

void	sprite_calc(t_cub *cub)
{
	cub->sprite.spriteheight = abs((int)(cub->mlx.screenheight / cub->sprite.transformy));
	cub->sprite.drawstarty = -cub->sprite.spriteheight / 2 + cub->mlx.screenheight / 2;
	if (cub->sprite.drawstarty < 0)
		cub->sprite.drawstarty = 0;
	cub->sprite.drawendy = cub->sprite.spriteheight / 2 + cub->mlx.screenheight / 2;
	if (cub->sprite.drawendy >= cub->mlx.screenheight)
		cub->sprite.drawendy = cub->mlx.screenheight - 1;

	cub->sprite.spritewidth = abs((int)(cub->mlx.screenheight / cub->sprite.transformy));
	cub->sprite.drawstartx = -cub->sprite.spritewidth / 2 + cub->sprite.spritescreenx;
	if (cub->sprite.drawstartx < 0)
		cub->sprite.drawstartx = 0;
	cub->sprite.drawendx = cub->sprite.spritewidth / 2 + cub->sprite.spritescreenx;
	if (cub->sprite.drawendx >= cub->mlx.screenwidth)
		cub->sprite.drawendx = cub->mlx.screenwidth - 1;
}

void	sprite_draw(t_cub *cub, int stripe)
{
	int y;
	int d;

	cub->camera.texx = (int)(256 * (stripe - (-cub->sprite.spritewidth / 2 + cub->sprite.spritescreenx) * TEX_WIDTH / cub->sprite.spritewidth / 256));		printf("stripe : %d, transY : %f, zbuffer : %f\n", stripe, cub->sprite.transformy, cub->camera.zbuffer[stripe]);
	if (cub->sprite.transformy > 0 && stripe > 0 && stripe < cub->mlx.screenwidth && cub->sprite.transformy < cub->camera.zbuffer[stripe])
	{
		y = cub->sprite.drawstarty;
	 	while (y < cub->sprite.drawendy)
		{
			d = (y) * 256 - cub->mlx.screenheight * 128 + cub->sprite.spriteheight * 128;
			cub->camera.texy = ((d * TEX_HEIGHT) / cub->sprite.spriteheight) / 256;
			draw_sprite_row(cub, stripe, y);
			y++;
		}
	}
}

void	draw_sprites(t_cub *cub, t_s *sprites)
{
	int i;
	int stripe;

	i = 0;
	while (i < cub->sprite.numsprites)
	{
		printf("%f, %f\n", sprites[i].pos.x, sprites[i].pos.y);	
		cub->sprite.spritex = sprites[i].pos.x - cub->camera.posx;
		cub->sprite.spritey = sprites[i].pos.y - cub->camera.posy;
		printf("spritex : %f, spritey : %f\n", cub->sprite.spritex, cub->sprite.spritey);
		sprite_transform(cub);
		cub->sprite.spritescreenx = (int)((cub->mlx.screenwidth / 2) * (1 + cub->sprite.transformx / cub->sprite.transformy));
		printf("spritescreenx : %d\n", cub->sprite.spritescreenx);
		sprite_calc(cub);
		printf("startx : %d, endx : %d\n", cub->sprite.drawstartx, cub->sprite.drawendx);
		stripe = cub->sprite.drawstartx;
		while (stripe < cub->sprite.drawendx)
		{
			sprite_draw(cub, stripe);
			stripe++;
		}
		i++;
	}
}