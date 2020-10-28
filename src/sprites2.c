/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:17:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/10/28 17:29:40 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		sprite_transform(t_cub *cub)
{
	cub->sprite.invdet = 1.0 /
	(cub->camera.planex * cub->camera.diry - \
	cub->camera.dirx * cub->camera.planey);
	cub->sprite.transformx = cub->sprite.invdet \
	* (cub->camera.diry * cub->sprite.spritex \
	- cub->camera.dirx * cub->sprite.spritey);
	cub->sprite.transformy = cub->sprite.invdet
	* (-cub->camera.planey * cub->sprite.spritex \
	+ cub->camera.planex * cub->sprite.spritey);
	cub->sprite.spritescreenx = (int)((cub->mlx.screenwidth / 2) \
	* (1 + cub->sprite.transformx / cub->sprite.transformy));
}

void		sprite_calc(t_cub *cub)
{
	cub->sprite.spriteheight =
	abs((int)(cub->mlx.screenheight / cub->sprite.transformy));
	cub->sprite.drawstarty =
	-cub->sprite.spriteheight / 2 + cub->mlx.screenheight / 2;
	if (cub->sprite.drawstarty < 0)
		cub->sprite.drawstarty = 0;
	cub->sprite.drawendy = cub->sprite.spriteheight / 2 \
	+ cub->mlx.screenheight / 2;
	if (cub->sprite.drawendy >= cub->mlx.screenheight)
		cub->sprite.drawendy = cub->mlx.screenheight - 1;
	cub->sprite.spritewidth = abs((int)(cub->mlx.screenheight \
	/ cub->sprite.transformy));
	cub->sprite.drawstartx = -cub->sprite.spritewidth \
	/ 2 + cub->sprite.spritescreenx;
	if (cub->sprite.drawstartx < 0)
		cub->sprite.drawstartx = 0;
	cub->sprite.drawendx = cub->sprite.spritewidth \
	/ 2 + cub->sprite.spritescreenx;
	if (cub->sprite.drawendx >= cub->mlx.screenwidth)
		cub->sprite.drawendx = cub->mlx.screenwidth - 1;
}

void		draw_sprite(t_cub *cub)
{
	int stripe;

	stripe = cub->sprite.drawstartx;
	while (stripe < cub->sprite.drawendx)
	{
		cub->camera.texx = (int)(256 * (stripe - (-cub->sprite.spritewidth / 2
		+ cub->sprite.spritescreenx)) * TEX_WIDTH / cub->sprite.spritewidth);
		cub->camera.texx /= 256;
		if (cub->sprite.transformy > 0 && stripe > 0
		&& stripe < cub->mlx.screenwidth
		&& cub->sprite.transformy < cub->camera.zbuffer[stripe])
			draw_textured_sprite(cub, stripe);
		stripe++;
	}
}

void		draw_sprites(t_cub *cub, t_s *sprites)
{
	int i;

	i = 0;
	while (i < cub->sprite.numsprites)
	{
		cub->sprite.spritex = sprites[i].pos.x - cub->camera.posx;
		cub->sprite.spritey = sprites[i].pos.y - cub->camera.posy;
		sprite_transform(cub);
		sprite_calc(cub);
		draw_sprite(cub);
		i++;
	}
}
