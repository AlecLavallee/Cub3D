/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/08/11 14:22:17 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical(t_cub *cub, int x)
{
	while (cub->drawStart < cub->drawEnd)
	{
		cub->img_data[(cub->drawStart * cub->sizeline) + (x * cub->bpp / 8)] = (cub->color >> 16) & 0xFF;
		cub->img_data[(cub->drawStart * cub->sizeline) + (x * cub->bpp / 8) + 1] = (cub->color >> 8) & 0xFF;
		cub->img_data[(cub->drawStart * cub->sizeline) + (x * cub->bpp / 8) + 2] = cub->color & 0xFF;
		cub->drawStart++;
	}
}

int		ft_key_hook(int keycode, t_cub *cub)
{
	double rotSpeed = 1.0;

	int worldMap[24][24]={{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}};
	if (keycode == 126)
	{
		ft_putstr("j'avance!\n");
		if (worldMap[(int)(cub->posX + cub->dirX)][(int)cub->posY] == 0)
			cub->posX += cub->dirX;
		if (worldMap[(int)cub->posX][(int)(cub->posY + cub->dirY)] == 0)
			cub->posY += cub->dirY;
		raycast(cub);
	}
	else if (keycode == 125)
	{
		ft_putstr("je recule!\n");
		if (worldMap[(int)(cub->posX - cub->dirX)][(int)cub->posY] == 0)
			cub->posX -= cub->dirX;
		if (worldMap[(int)cub->posX][(int)(cub->posY - cub->dirY)] == 0)
			cub->posY -= cub->dirY;
		raycast(cub);
	}
	else if (keycode == 123)
	{
		ft_putstr("je pivote vers la gauche!\n");
		double	oldDirX = cub->dirX;
		cub->dirX = cub->dirX * cos(rotSpeed) - cub->dirY * sin(rotSpeed);
		cub->dirY = oldDirX * sin(rotSpeed) + cub->dirY * cos(rotSpeed);
		double oldPlaneX = cub->planeX;
		cub->planeX = cub->planeX * cos(rotSpeed) - cub->planeY * sin(rotSpeed);
		cub->planeY = oldPlaneX * sin(rotSpeed) + cub->planeY * cos(rotSpeed);
		raycast(cub);
	}
	else if (keycode == 124)
	{
		ft_putstr("je pivote vers la droite!\n");
		double	oldDirX = cub->dirX;
		cub->dirX = cub->dirX * cos(-rotSpeed) - cub->dirY * sin(-rotSpeed);
		cub->dirY = oldDirX * sin(-rotSpeed) + cub->dirY * cos(-rotSpeed);
		double	oldPlaneX = cub->planeX;
		cub->planeX = cub->planeX * cos(-rotSpeed) - cub->planeY * sin(-rotSpeed);
		cub->planeY = oldPlaneX * sin(-rotSpeed) + cub->planeY * cos(-rotSpeed);
		raycast(cub);
	}
	else
		ft_putstr("touche inconnue!\n");
	return (1);
}

void	raycast_init(t_cub *cub)
{
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
}

void	dda(t_cub *cub)
{
	int worldMap[24][24]={{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}};
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
		if (worldMap[cub->mapX][cub->mapY] > 0)
			cub->hit = 1;
	}
}

void	raycast(t_cub *cub)
{
	int	i;

	i = 0;
	int worldMap[24][24]={{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}};
	mlx_destroy_image(cub->mlx, cub->image);
	cub->image = mlx_new_image(cub->mlx, cub->x_axis, cub->y_axis);
	cub->img_data = mlx_get_data_addr(cub->image, &cub->bpp, &cub->sizeline, &cub->endian);
	while (i++ < cub->x_axis)
	{
		// a degager dans une autre fonction
		cub->cameraX = (2 * i / ((double)cub->x_axis) - 1);
		cub->rayDirX = cub->dirX + cub->planeX * cub->cameraX;
		cub->rayDirY = cub->dirY + cub->planeY * cub->cameraX;
		cub->mapX = (int)cub->posX;
		cub->mapY = (int)cub->posY;
		cub->deltaDistX = fabs(1 / cub->rayDirX);
		cub->deltaDistY = fabs(1 / cub->rayDirY);
		raycast_init(cub);
		cub->hit = 0;
		dda(cub);
		if (cub->side == 0)
			cub->perpWallDist = (cub->mapX - cub->posX + (1 - cub->stepX) / 2) / cub->rayDirX;
		else
			cub->perpWallDist = (cub->mapY - cub->posY + (1 - cub->stepY) / 2) / cub->rayDirY;
		cub->lineHeight = (int)(cub->y_axis / cub->perpWallDist);
		cub->drawStart = -1 * cub->lineHeight / 2 + cub->y_axis / 2;
		if (cub->drawStart < 0)
			cub->drawStart = 0;
		cub->drawEnd = cub->lineHeight / 2 + cub->y_axis / 2;
		if (cub->drawEnd >= cub->y_axis)
			cub->drawEnd = cub->y_axis - 1;
		if (worldMap[cub->mapX][cub->mapY] == 1)
			cub->color = 0xFF0000;
		else if (worldMap[cub->mapX][cub->mapY] == 2)
			cub->color = 0x00FF00;
		else if (worldMap[cub->mapX][cub->mapY] == 3)
			cub->color = 0x0000FF;
		else if (worldMap[cub->mapX][cub->mapY] == 4)
			cub->color = 0xFFFFFF;
		else
			cub->color = 0xFFFF00;
		if (cub->side == 1)
			cub->color /= 2;
		draw_vertical(cub, i);
	}
	mlx_put_image_to_window(cub->mlx, cub->window, cub->image, 0, 0);
}

void	mlx_gestion(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->window = mlx_new_window(cub->mlx, cub->x_axis, cub->y_axis, "Cub3D");
	cub->posX = 22;
	cub->posY = 12;
	cub->planeX = 0;
	cub->planeY = 0.66;
	cub->dirX = -1;
	cub->dirY = 0;
	cub->image = mlx_new_image(cub->mlx, cub->x_axis, cub->y_axis);
	cub->img_data = mlx_get_data_addr(cub->image, &cub->bpp, &cub->sizeline, &cub->endian);
	raycast(cub);
	mlx_key_hook(cub->window, ft_key_hook, cub);
	mlx_loop(cub->mlx);
}
