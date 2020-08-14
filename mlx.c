/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/08/14 16:09:31 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical(t_cub *cub, unsigned int **buffer)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	(void)buffer;
	while (i < cub->y_axis)
	{
		while (j < cub->x_axis)
		{
			cub->img_data[(i * cub->sizeline) + (j * cub->bpp / 8)] = (buffer[i][j] >> 16) & 0xFF;
			cub->img_data[(i * cub->sizeline) + (j * cub->bpp / 8) + 1] = (buffer[i][j] >> 8) & 0xFF;
			cub->img_data[(i * cub->sizeline) + (j * cub->bpp / 8) + 2] = buffer[i][j] & 0xFF;
			j++;
		}
		j = 0;
		i++;
	}
}

int		ft_key_hook(int keycode, t_cub *cub)
{
	double rotSpeed = 1.0;

	int worldMap[24][24]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
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
	
	int worldMap[24][24]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
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
	cub->texture = malloc(sizeof(unsigned int *) * 8);
	int	width = 0;
	int height = 0;
	
	(void)width;
	(void)height;
	int x = 0;
	int y = 0;
	cub->texture[0] = malloc(sizeof(unsigned int) * texWidth * texHeight);
	cub->texture[1] = malloc(sizeof(unsigned int) * texWidth * texHeight);
	cub->texture[2] = malloc(sizeof(unsigned int) * texWidth * texHeight);
	cub->texture[3] = malloc(sizeof(unsigned int) * texWidth * texHeight);
	cub->texture[4] = malloc(sizeof(unsigned int) * texWidth * texHeight);
	cub->texture[5] = malloc(sizeof(unsigned int) * texWidth * texHeight);
	cub->texture[6] = malloc(sizeof(unsigned int) * texWidth * texHeight);
	cub->texture[7] = malloc(sizeof(unsigned int) * texWidth * texHeight);
	
	while (x < texWidth)
	{
		while (y < texHeight)
		{
			int ycolor = y * 256 / texHeight;
			int xycolor = y * 128 / texHeight + x * 128 / texWidth;
			int xorcolor = x * 256 / texWidth;
			cub->texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
    		cub->texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
    		cub->texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
    		cub->texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
    		cub->texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
    		cub->texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
    		cub->texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
    		cub->texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //not flat grey texture
			y++;
		}
		y = 0;
		x++;
	}
}

void	raycast(t_cub *cub)
{
	int	i;

	i = 0;
	int worldMap[24][24]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
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
			cub->wallX = cub->posX + cub->perpWallDist * cub->rayDirX;
		cub->wallX -= floor((cub->wallX));

		cub->texX = (int)(cub->wallX * (double)texWidth);
		if (cub->side == 0 && cub->rayDirX > 0)
			cub->texX = texWidth - cub->texX - 1;
		if (cub->side == 1 && cub->rayDirY < 0)
			cub->texX = texWidth - cub->texX - 1;
		
		cub->step = 1.0 * texHeight / cub->lineHeight;
		cub->texPos = (cub->drawStart - cub->y_axis / 2 + cub->lineHeight / 2) * cub->step;
		cub->y = cub->drawStart;
		while (cub->y < cub->drawEnd)
		{
			cub->texY = (int)cub->texPos & (texHeight - 1);
			cub->texPos += cub->step;
			// depassement de memoire ici
			//printf("texNum : %d, texY : %d, texX : %d\n", cub->texNum, cub->texX, cub->texY);
			cub->color = cub->texture[cub->texNum][texHeight * cub->texY + cub->texX];
			printf("color raw : %c\n", cub->texture[cub->texNum][texHeight * cub->texY + cub->texX]);
			printf("color : %u\n", cub->color);
			if (cub->side == 1)
				cub->color = (cub->color >> 1) & 8355711;
			cub->buffer[cub->y][i] = cub->color;
			cub->y++;
		}
	}
	draw_vertical(cub, cub->buffer);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->image, 0, 0);
	i = 0;
	cub->y = 0;
	while (cub->y < cub->y_axis)
	{
		while (i < cub->x_axis)
		{
			cub->buffer[cub->y][i] = 0;
			i++;
		}
		i = 0;
		cub->y++;
	}
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
	texture(cub);
	cub->buffer = malloc(sizeof(unsigned int *) * cub->y_axis + 1);
	int k = 0;
	while (k < cub->y_axis)
		cub->buffer[k++] = malloc(sizeof(unsigned int) * cub->x_axis + 1);
	raycast(cub);
	mlx_key_hook(cub->window, ft_key_hook, cub);
	mlx_loop(cub->mlx);
}
