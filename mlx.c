/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/26 13:50:54 by alelaval         ###   ########.fr       */
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

/*void	dda(t_cub *cub)
{
	cub->hit = 0;
	printf("DDA!\n");
	while (cub->hit == 0)
	{
		printf("Oi!\n");
		if (cub->sideDistX < cub->sideDistY)
		{
			printf("1!\n");
			cub->sideDistX += cub->deltaDistX;
			cub->mapX += cub->stepX;
			cub->side = 0;
		}
		else
		{
			printf("2!\n");
			cub->sideDistX += cub->deltaDistY;
			cub->mapY += cub->stepY;
			cub->side = 1;
		}
		if (cub->map[0][0] > 0)
			cub->hit = 1;
	}
}

void	raycast(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->x_axis)
	{
		cub->cameraX = (2 * i / (double)cub->x_axis - 1);
		i++;
		cub->rayDirX = cub->dirX + cub->planeX * cub->cameraX;
		cub->rayDirY = cub->dirY + cub->planeY * cub->cameraX;
		cub->mapX = (int)cub->posX;
		cub->mapY = (int)cub->posY;
		cub->deltaDistX = fabs(1 / cub->rayDirX);
		cub->deltaDistY = fabs(1 / cub->rayDirY);
		cub->side = 0;
		printf("%f\n", cub->rayDirX);
		printf("%f\n", cub->rayDirY);
		printf("%d\n", cub->mapX);
		printf("%d\n", cub->mapY);
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
		printf("%d\n", cub->sideDistX);
		printf("%d\n", cub->sideDistY);
		dda(cub);
		if (cub->side == 0)
			cub->perpWallDist = (cub->mapX - cub->posX + (1 - cub->stepX) / 2) / cub->rayDirX;
		else
			cub->perpWallDist = (cub->mapY - cub->posY + (1 - cub->stepY) / 2) / cub->rayDirY;
		cub->color = 255255;
		if (cub->side == 1)
			cub->color = cub->color / 2;
		cub->lineHeight = (cub->x_axis / cub->perpWallDist);
		cub->drawStart = -cub->lineHeight / 2 + cub->x_axis / 2;
		if (cub->drawStart < 0)
			cub->drawStart = 0;
		cub->drawEnd = cub->lineHeight / 2 + cub->y_axis / 2;
		if (cub->drawEnd >= cub->y_axis)
			cub->drawEnd = cub->y_axis - 1;
		draw_vertical(cub, i);
	}
}*/

void	minimap(t_cub *cub)
{
	int	i;
	int	j;
	int	k;
	int color;

	i = 0;
	j = 0;
	k = 0;
	color = 0xFFFFFF;
	while (i < cub->y_axis)
	{
		j = 0;
		while (j < cub->x_axis)
		{
			while (k < 30)
			{
				cub->img_data[((i * 4) * j) + (i + 4)] = color;
				k++;
			}
			k = 0;
			j++;
		}
		i++;
	}
}

void	mlx_gestion(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->window = mlx_new_window(cub->mlx, cub->x_axis, cub->y_axis, "Cub3D");
	cub->image = mlx_new_image(cub->mlx, cub->x_axis, cub->y_axis);
	cub->img_data = mlx_get_data_addr(cub->image, &cub->bpp, &cub->sizeline, &cub->endian);
	printf("oi!\n");
	minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->image, 0, 0);
	printf("minimap\n");
	mlx_loop(cub->mlx);
}
