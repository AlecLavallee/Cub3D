/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/08/25 01:52:13 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	texture(t_cub *cub)
{
	cub->texture = NULL;
	cub->texture = malloc(sizeof(void *) * 5);
	int	width = 0;
	int height = 0;

	cub->texture[0] = mlx_xpm_file_to_image(cub->mlx, "textures/bluestone.xpm", &width, &height);
	cub->texture[1] = mlx_xpm_file_to_image(cub->mlx, "textures/eagle.xpm", &width, &height);
	cub->texture[2] = mlx_xpm_file_to_image(cub->mlx, "textures/purplestone.xpm", &width, &height);
	cub->texture[3] = mlx_xpm_file_to_image(cub->mlx, "textures/pillar.xpm", &width, &height);
	cub->texture[4] = mlx_xpm_file_to_image(cub->mlx, "textures/bluestone.xpm", &width, &height);
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
	return(1);
}

void	ray_init(t_cub *cub)
{
	cub->rayDirX = cub->dirX + cub->planeX * cub->cameraX;
	cub->rayDirY = cub->dirY + cub->planeY * cub->cameraX;
	cub->mapX = (int)cub->posX;
	cub->mapY = (int)cub->posY;
	cub->deltaDistX = fabs(1 / cub->rayDirX);
	cub->deltaDistY = fabs(1 / cub->rayDirY);
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

void	mlx_clear_img(void *img_ptr, int height_res)
{
	char	*img_ret;
	int		bit_per_pix;
	int		size_line;
	int		endian;

	img_ret = mlx_get_data_addr(img_ptr, &bit_per_pix, &size_line, &endian);
	ft_bzero(img_ret, size_line * height_res);
}

void	perp_wall_dist(t_cub *cub)
{
	if (cub->side == 0)
		cub->perpWallDist = (cub->mapX - cub->posX + (1 - cub->stepX) / 2) / cub->rayDirX;
	else
		cub->perpWallDist = (cub->mapY - cub->posY + (1 - cub->stepY) / 2) / cub->rayDirY;
}

void	draw_calc(t_cub *cub)
{
	cub->lineHeight = (int)(cub->y_axis / cub->perpWallDist);
	cub->drawStart = -1 * cub->lineHeight / 2 + cub->y_axis / 2;
	if (cub->drawStart < 0)
		cub->drawStart = 0;
	cub->drawEnd = cub->lineHeight / 2 + cub->y_axis / 2;
	if (cub->drawEnd >= cub->y_axis)
		cub->drawEnd = cub->y_axis - 1;
}

void	text_calc(t_cub	*cub)
{
	int worldMap[24][24]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	cub->texNum = worldMap[cub->mapX][cub->mapY] - 1;
	if (cub->side == 0)
		cub->wallX = cub->posY + cub->perpWallDist * cub->rayDirY;
	else
		cub->wallX = cub->posX + cub->perpWallDist * cub->rayDirX;
	cub->wallX -= floor(cub->wallX);

	cub->texX = (int)(cub->wallX * (double)texWidth);
	if (cub->side == 0 && cub->rayDirX > 0)
		cub->texX = texWidth - cub->texX - 1;
	if (cub->side == 1 && cub->rayDirY < 0)
		cub->texX = texWidth - cub->texX - 1;
	
	cub->step = 1.0 * texHeight / cub->lineHeight;
    cub->texPos = (double)(cub->drawStart - cub->y_axis / 2 + cub->lineHeight / 2) * cub->step;
}

void    draw(t_cub *cub, int x)
{
    char		*img_ptr = NULL;
    unsigned	*color_ptr = NULL;
    int			bpp;
    int			size_line;
    int			endian;
    unsigned    color;
    int         y;

    color = 0;
    y = cub->drawStart;
    while (y < cub->drawEnd)
    {
        cub->texY = (int)cub->texPos & (texHeight - 1);
        cub->texPos += cub->step;
        color_ptr = (unsigned*)mlx_get_data_addr(cub->texture[cub->texNum], &bpp, &size_line, &endian);
        color = (unsigned int)(color_ptr[texHeight * cub->texY + cub->texX]);
        if (cub->side == 1)
          color = (unsigned)(color >> 1) & 8355711;
        img_ptr = mlx_get_data_addr(cub->image, &bpp, &size_line, &endian);
        img_ptr[(y * size_line) + (x * bpp / 8)] = (color >> 16) & 0xFF;
        img_ptr[(y * size_line) + (x * bpp / 8) + 1] = (color >> 8) & 0xFF;
        img_ptr[(y * size_line) + (x * bpp / 8) + 2] = color & 0xFF;
        y++;
    }
}

void	raycast(t_cub *cub)
{
	int	i;

	i = 0;
	mlx_clear_img(cub->image, cub->y_axis);
	while (i++ < cub->x_axis)
	{
		cub->hit = 0;
		cub->cameraX = (2 * i / (double)cub->x_axis - 1);
		ray_init(cub);
		raycast_init(cub);
		dda(cub);
		perp_wall_dist(cub);
		draw_calc(cub);
		text_calc(cub);
		draw(cub, i);
	}
	mlx_put_image_to_window(cub->mlx, cub->window, cub->image, 0, 0);
}

void	mlx_gestion(t_cub *cub)
{
	cub->posX = 22;
	cub->posY = 12;
	cub->planeX = 0.0;
	cub->planeY = 0.66;
	cub->dirX = -1.0;
	cub->dirY = 0;
	cub->mlx = mlx_init();
	cub->window = mlx_new_window(cub->mlx, cub->x_axis, cub->y_axis, "Cub3D");
	cub->image = mlx_new_image(cub->mlx, cub->x_axis, cub->y_axis);
	mlx_clear_img(cub->image, cub->x_axis);
	texture(cub);
	raycast(cub);
	mlx_key_hook(cub->window, ft_key_hook, cub);
	mlx_loop(cub->mlx);
}
