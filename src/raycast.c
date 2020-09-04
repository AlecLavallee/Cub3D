/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/04 16:46:23 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_init(t_cub *cub)
{
	cub->camera.rayDirX = cub->camera.dirX + cub->camera.planeX \
	* cub->camera.cameraX;
	cub->camera.rayDirY = cub->camera.dirY + cub->camera.planeY \
	* cub->camera.cameraX;
	cub->camera.mapX = (int)cub->camera.posX;
	cub->camera.mapY = (int)cub->camera.posY;
	cub->camera.deltaDistX = fabs(1 / cub->camera.rayDirX);
	cub->camera.deltaDistY = fabs(1 / cub->camera.rayDirY);
}

void	raycast_init(t_cub *cub)
{
	if (cub->camera.rayDirX < 0)
	{
		cub->camera.stepX = -1;
		cub->camera.sideDistX = (cub->camera.posX - cub->camera.mapX) \
		* cub->camera.deltaDistX;
	}
	else
	{
		cub->camera.stepX = 1;
		cub->camera.sideDistX = (cub->camera.mapX + 1.0 - cub->camera.posX) \
		* cub->camera.deltaDistX;
	}
	if (cub->camera.rayDirY < 0)
	{
		cub->camera.stepY = -1;
		cub->camera.sideDistY = (cub->camera.posY - cub->camera.mapY) \
		* cub->camera.deltaDistY;
	}
	else
	{
		cub->camera.stepY = 1;
		cub->camera.sideDistY = (cub->camera.mapY + 1.0 - cub->camera.posY) \
		* cub->camera.deltaDistY;
	}
}

void	perp_wall_dist(t_cub *cub)
{
	if (cub->camera.side == 0)
		cub->camera.perpWallDist = (cub->camera.mapX - cub->camera.posX + (1 - cub->camera.stepX) / 2) / cub->camera.rayDirX;
	else
		cub->camera.perpWallDist = (cub->camera.mapY - cub->camera.posY + (1 - cub->camera.stepY) / 2) / cub->camera.rayDirY;
}

void	dda(t_cub *cub)
{
	int worldMap[24][24]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	while (cub->camera.hit == 0)
	{
		if (cub->camera.sideDistX < cub->camera.sideDistY)
		{
			cub->camera.sideDistX += cub->camera.deltaDistX;
			cub->camera.mapX += cub->camera.stepX;
			cub->camera.side = 0;
		}
		else
		{
			cub->camera.sideDistY += cub->camera.deltaDistY;
			cub->camera.mapY += cub->camera.stepY;
			cub->camera.side = 1;
		}
		if (worldMap[cub->camera.mapX][cub->camera.mapY] > 0)
			cub->camera.hit = 1;
	}
}

void	draw_calc(t_cub *cub)
{
	cub->camera.lineHeight = (int)(cub->mlx.screenHeight / cub->camera.perpWallDist);
	cub->camera.drawStart = -1 * cub->camera.lineHeight / 2 + cub->mlx.screenHeight / 2;
	if (cub->camera.drawStart < 0)
		cub->camera.drawStart = 0;
	cub->camera.drawEnd = cub->camera.lineHeight / 2 + cub->mlx.screenHeight / 2;
	if (cub->camera.drawEnd >= cub->mlx.screenHeight)
		cub->camera.drawEnd = cub->mlx.screenHeight - 1;
}