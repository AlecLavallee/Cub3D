/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/08/13 16:54:08 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical(t_cub *cub, uint32_t *buffer)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < cub->x_axis)
	{
		while (j < cub->y_axis)
		{
			cub->img_data[(j * cub->sizeline) + (i * cub->bpp / 8)] = (buffer[j] + i) & 0xFF;
			cub->img_data[(j * cub->sizeline) + (i * cub->bpp / 8) + 1] = (buffer[j] + i) & 0xFF;
			cub->img_data[(j * cub->sizeline) + (i * cub->bpp / 8) + 2] = (buffer[j] + i) & 0xFF;
			j++;
		}
		j = 0;
		i++;
	}
}

int		ft_key_hook(int keycode, t_cub *cub)
{
	double rotSpeed = 1.0;

	int worldMap[24][24]={{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}};
	if (keycode == 126)
	{
		if (worldMap[(int)(cub->posX + cub->dirX)][(int)cub->posY] == 0)
			cub->posX += cub->dirX;
		if (worldMap[(int)cub->posX][(int)(cub->posY + cub->dirY)] == 0)
			cub->posY += cub->dirY;
	}
	else if (keycode == 125)
	{
		if (worldMap[(int)(cub->posX - cub->dirX)][(int)cub->posY] == 0)
			cub->posX -= cub->dirX;
		if (worldMap[(int)cub->posX][(int)(cub->posY - cub->dirY)] == 0)
			cub->posY -= cub->dirY;
	}
	else if (keycode == 123)
	{
		double	oldDirX = cub->dirX;
		cub->dirX = cub->dirX * cos(rotSpeed) - cub->dirY * sin(rotSpeed);
		cub->dirY = oldDirX * sin(rotSpeed) + cub->dirY * cos(rotSpeed);
		double oldPlaneX = cub->planeX;
		cub->planeX = cub->planeX * cos(rotSpeed) - cub->planeY * sin(rotSpeed);
		cub->planeY = oldPlaneX * sin(rotSpeed) + cub->planeY * cos(rotSpeed);
	}
	else if (keycode == 124)
	{
		double	oldDirX = cub->dirX;
		cub->dirX = cub->dirX * cos(-rotSpeed) - cub->dirY * sin(-rotSpeed);
		cub->dirY = oldDirX * sin(-rotSpeed) + cub->dirY * cos(-rotSpeed);
		double	oldPlaneX = cub->planeX;
		cub->planeX = cub->planeX * cos(-rotSpeed) - cub->planeY * sin(-rotSpeed);
		cub->planeY = oldPlaneX * sin(-rotSpeed) + cub->planeY * cos(-rotSpeed);
	}
	else
		ft_putstr("touche inconnue!\n");
	raycast(cub);
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

void	texture(t_cub *cub)
{
	cub->texture = NULL;
	cub->texture = malloc(sizeof(char *) * 5);
	int	width = 0;
	int height = 0;
	cub->texture[0] = (char*)mlx_xpm_file_to_image(cub->mlx, "tests/eagle.xpm", &width, &height);
	cub->texture[1] = (char*)mlx_xpm_file_to_image(cub->mlx, "tests/colorstone.xpm", &width, &height);
	cub->texture[2] = (char*)mlx_xpm_file_to_image(cub->mlx, "tests/bluestone.xpm", &width, &height);
	cub->texture[3] = (char*)mlx_xpm_file_to_image(cub->mlx, "tests/greystone.xpm", &width, &height);
	cub->texture[4] = (char*)mlx_xpm_file_to_image(cub->mlx, "tests/barrel.xpm", &width, &height);
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
		
		cub->texNum = worldMap[cub->mapX][cub->mapY] - 1;
		if (cub->side == 0)
			cub->wallX = cub->posY + cub->perpWallDist * cub->rayDirY;
		else
			cub->wallX = cub->posX+ cub->perpWallDist * cub->rayDirX;
		cub->wallX -= floor((cub->wallX));
		cub->texX = (int)(cub->wallX * (double)texWidth);
		if (cub->side == 0 && cub->rayDirX > 0)
			cub->texX = texWidth - cub->texX - 1;
		if (cub->side == 1 && cub->rayDirY < 0)
			cub->texX = texWidth - cub->texX - 1;
		cub->step = 1.0 * texHeight / cub->lineHeight;
		cub->texPos = (cub->drawStart - cub->x_axis / 2 + cub->lineHeight / 2) * cub->step;
		cub->y = cub->drawStart;
		while (cub->y < cub->drawEnd)
		{
			cub->texY = (int)cub->texPos & (texHeight - 1);
			cub->texPos += cub->step;
			// depassement de memoire ici
			cub->color = (unsigned int)cub->texture[cub->texNum][texHeight * cub->texY + cub->texX];
			if (cub->side == 1)
				cub->color = (cub->color >> 1) & 8355711;
			cub->buffer[cub->y][i] = cub->color;
			cub->y++;
		}
	}
	draw_vertical(cub, cub->buffer[0]);
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
	cub->buffer = malloc(sizeof(unsigned int *) * cub->y_axis + 1);
	int k = 0;
	while (k < cub->x_axis)
		cub->buffer[k++] = malloc(sizeof(unsigned int) * cub->x_axis + 1);
	cub->image = mlx_new_image(cub->mlx, cub->x_axis, cub->y_axis);
	cub->img_data = mlx_get_data_addr(cub->image, &cub->bpp, &cub->sizeline, &cub->endian);
	texture(cub);
	raycast(cub);
	mlx_key_hook(cub->window, ft_key_hook, cub);
	mlx_loop(cub->mlx);
}
