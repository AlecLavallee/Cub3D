/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/23 19:30:55 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical(int x, int drawStart, int drawEnd, int color)
{
	while (drawStart < drawEnd)
	{
		mlx_pixel_put(cub->mlx, cub->)
	}
}
void	dda(t_cub *cub)
{
	while (cub->hit == 0)
	{
		if (cub->sideDistX < cub->sideDistY)
		{
			cub->sideDistX += cub->deltaDistX;
			cub->mapX += cub->stepX;
			cub->side = 0;
		}
		else
		{
			cub->sideDistX += cub->deltaDistY;
			cub->mapY += cub->stepY;
			cub->side = 1;
		}
		if (cub->map[cub->mapX][cub->mapY] > 0)
			cub->hit = 0;
	}
}

void	raycast(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->x_axis)
	{
		cub->cameraX = (2 * i / (double)cub->x_axis - 1);
		cub->rayDirX = cub->dirX + cub->planeX * cub->cameraX;
		cub->rayDirY = cub->dirY + cub->planeY * cub->cameraX;
		cub->mapX = cub->posX;
		cub->mapY = cub->posY;
		cub->deltaDistX = fabs(1 / cub->rayDirX);
		cub->deltaDistY = fabs(1 / cub->rayDirY);
		cub->side = 0;
		if (cub->rayDirX < 0)
		{
			cub->stepX = -1;
			cub->sideDistX = (cub->posX - cub->mapX) * cub->deltaDistX;
		}
		else
		{
			cub->stepX = 1;
			cub->sideDistX = (cub->mapX + 1.0 - cub->posX) * cub->deltaDistX;
		}
		if (cub->rayDirY < 0)
		{
			cub->stepY = -1;
			cub->sideDistY = (cub->posY - cub->mapY) * cub->deltaDistY;
		}
		else
		{
			cub->stepY = 1;
			cub->sideDistY = (cub->mapY + 1.0 - cub->posY) * cub->deltaDistY;
		}
		dda(cub);
		if (cub->side == 0)
			cub->perpWallDist = (cub->mapX - cub->posX + (1 - cub->stepX) / 2) / cub->rayDirX;
		else
			cub->perpWallDist = (cub->mapY - cub->posY + (1 - cub->stepY) / 2) / cub->rayDirY;
		cub->color = 255;
		if (cub->side == 1)
			color = color / 2;
		mlx_pixel_put(cub->mlx, cub->window, i, )
	}
}

void	mlx_gestion(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->window = mlx_new_window(cub->mlx, cub->x_axis, cub->y_axis, "Cub3D");
	cub->image = mlx_new_image(cub->mlx, cub->x_axis, cub->y_axis);
	cub->img_data = \
	mlx_get_data_addr(cub->image, &cub->bpp, &cub->sizeline, &cub->endian);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->image, 0, 0);
	mlx_loop(cub->mlx);
	while (1)
		raycast(cub);
}
