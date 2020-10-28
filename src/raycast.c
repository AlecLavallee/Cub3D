/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/10/28 17:46:08 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_cub *cub)
{
	cub->camera.hit = 0;
	cub->camera.raydirx = cub->camera.dirx + cub->camera.planex
	* cub->camera.camerax;
	cub->camera.raydiry = cub->camera.diry + cub->camera.planey
	* cub->camera.camerax;
	cub->camera.mapx = (int)cub->camera.posx;
	cub->camera.mapy = (int)cub->camera.posy;
	cub->camera.deltadistx = fabs(1.0 / cub->camera.raydirx);
	cub->camera.deltadisty = fabs(1.0 / cub->camera.raydiry);
}

void	raycast_init(t_cub *cub)
{
	if (cub->camera.raydirx < 0)
	{
		cub->camera.stepx = -1;
		cub->camera.sidedistx = (cub->camera.posx - (double)cub->camera.mapx)
		* cub->camera.deltadistx;
	}
	else
	{
		cub->camera.stepx = 1;
		cub->camera.sidedistx = ((double)cub->camera.mapx + 1.0
		- cub->camera.posx) * cub->camera.deltadistx;
	}
	if (cub->camera.raydiry < 0)
	{
		cub->camera.stepy = -1;
		cub->camera.sidedisty = (cub->camera.posy - (double)cub->camera.mapy)
		* cub->camera.deltadisty;
	}
	else
	{
		cub->camera.stepy = 1;
		cub->camera.sidedisty = ((double)cub->camera.mapy + 1.0
		- cub->camera.posy) * cub->camera.deltadisty;
	}
}

void	perp_wall_dist(t_cub *cub)
{
	if (cub->camera.side == 0)
		cub->camera.perpwalldist =
		((double)cub->camera.mapx - cub->camera.posx +
		(1.0 - (double)cub->camera.stepx) / 2.0) / cub->camera.raydirx;
	else
		cub->camera.perpwalldist =
		((double)cub->camera.mapy - cub->camera.posy +
		(1.0 - (double)cub->camera.stepy) / 2.0) / cub->camera.raydiry;
}

void	dda(t_cub *cub)
{
	while (cub->camera.hit == 0)
	{
		if (cub->camera.sidedistx < cub->camera.sidedisty)
		{
			cub->camera.sidedistx += cub->camera.deltadistx;
			cub->camera.mapx += cub->camera.stepx;
			cub->camera.side = 0;
		}
		else
		{
			cub->camera.sidedisty += cub->camera.deltadisty;
			cub->camera.mapy += cub->camera.stepy;
			cub->camera.side = 1;
		}
		if (cub->map.map[cub->camera.mapx][cub->camera.mapy] == 1)
			cub->camera.hit = 1;
	}
}

void	draw_calc(t_cub *cub)
{
	cub->camera.lineheight =
	(int)(cub->mlx.screenheight / cub->camera.perpwalldist);
	cub->camera.drawstart =
	-1 * cub->camera.lineheight / 2 + cub->mlx.screenheight / 2;
	if (cub->camera.drawstart < 0)
		cub->camera.drawstart = 0;
	cub->camera.drawend =
	cub->camera.lineheight / 2 + cub->mlx.screenheight / 2;
	if (cub->camera.drawend >= cub->mlx.screenheight)
		cub->camera.drawend = cub->mlx.screenheight - 1;
}
