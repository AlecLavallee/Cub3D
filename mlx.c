/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/03/04 17:56:44 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical(t_cub *cub, int x)
{
	while (cub->drawStart < cub->drawEnd)
	{
		mlx_pixel_put(cub->mlx, cub->window, x, cub->drawStart, cub->color);
		cub->drawStart++;
	}
}

void	dda(t_cub *cub)
{
	cub->hit = 0;
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
			cub->sideDistY += cub->deltaDistY;
			cub->mapY += cub->stepY;
			cub->side = 1;
		}
		printf("mapX : %d, mapY : %d\n", cub->mapX, cub->mapY);
		if (cub->file.map[cub->mapX][cub->mapY] > 0)
			cub->hit = 1;
	}
}

void	raycast(t_cub *cub)
{
	int	i;

	i = 0;
	cub->posX = 1;
	cub->posY = 1;
	cub->planeX = 0;
	cub->planeY = 0.66;
	cub->dirX = -1;
	cub->dirY = 0;
	cub->color = 255;
	while (i < cub->x_axis)
	{
		cub->cameraX = (2 * i / (double)cub->x_axis - 1);
		cub->rayDirX = cub->dirX + cub->planeX * cub->cameraX;
		cub->rayDirY = cub->dirY + cub->planeY * cub->cameraX;
		cub->mapX = (int)cub->posX;
		cub->mapY = (int)cub->posY;
		cub->deltaDistX = fabs(1 / cub->rayDirX);
		cub->deltaDistY = fabs(1 / cub->rayDirY);
		cub->side = 0;
		printf("\nrayDirX : %f\n", cub->rayDirX);
		printf("rayDirY : %f\n", cub->rayDirY);
		printf("mapX : %d\n", cub->mapX);
		printf("mapY : %d\n", cub->mapY);
		printf("cameraX :%f\n", cub->cameraX);
		printf("deltaDistX : %f\n", cub->deltaDistX);
		printf("deltaDistY : %f\n", cub->deltaDistY);
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
		printf("sideDistX : %d\n", cub->sideDistX);
		printf("sideDistY : %d\n", cub->sideDistY);
		dda(cub);
		if (cub->side == 0)
			cub->perpWallDist = (cub->mapX - cub->posX + (1 - cub->stepX) / 2) / cub->rayDirX;
		else
			cub->perpWallDist = (cub->mapY - cub->posY + (1 - cub->stepY) / 2) / cub->rayDirY;
		// wip
		cub->lineHeight = (int)(cub->y_axis / cub->perpWallDist);
		cub->drawStart = (-1 * cub->lineHeight) / 2 + cub->y_axis / 2;
		if (cub->drawStart < 0)
			cub->drawStart = 0;
		cub->drawEnd = cub->lineHeight / 2 + cub->y_axis / 2;
		if (cub->drawEnd >= cub->y_axis)
			cub->drawEnd = cub->y_axis - 1;
		draw_vertical(cub, i);
		i++;
	}
}

void	minimap(t_cub *cub)
{
	int	i;
	int	j;
	int	k;
	int m;

	i = 0;
	while (i < cub->map_y)
	{
		j = 0;
		while (j < cub->map_x - 1)
		{
			m = 0;
			while (m < 20)
			{
				k = 0;
				while (k < 20)
				{
					if (cub->file.map[i][j] == '1')
						mlx_pixel_put(cub->mlx, cub->window, j * 20 + k, i * 20 + m, INT32_MAX);
					k++;
				}
				m++;
				if (cub->file.map[i][j] != '1')
					mlx_pixel_put(cub->mlx, cub->window, j * 20 + k, i * 20 + m, INT16_MAX);
			}
			j++;
		}
		i++;
	}
	printf("i : %d, j : %d, k : %d\n", i, j, k);
}

void	mlx_gestion(t_cub *cub)
{
	printf("Resolution : y = %d, x = %d\n", cub->y_axis, cub->x_axis);
	printf("Colors : floor = %d,%d,%d and ceiling = %d,%d,%d\n", cub->floor[0], cub->floor[1], cub->floor[2], cub->ceiling[0], cub->ceiling[1], cub->ceiling[2]);
	printf("map_x = %d, map_y = %d\n", cub->map_x, cub->map_y);
	cub->mlx = mlx_init();
	cub->window = mlx_new_window(cub->mlx, cub->x_axis, cub->y_axis, "Cub3D");
	cub->image = mlx_new_image(cub->mlx, cub->x_axis, cub->y_axis);
	cub->img_data = mlx_get_data_addr(cub->image, &cub->bpp, &cub->sizeline, &cub->endian);
	printf("Raycasting!\n");
	//minimap(cub);
	//mlx_put_image_to_window(cub->mlx, cub->window, cub->image, 500, 500);
	printf("Avant la loop\n");
	raycast(cub);
	printf("w : %d, h : %d\n", cub->x_axis, cub->y_axis);
	mlx_loop(cub->mlx);
}
