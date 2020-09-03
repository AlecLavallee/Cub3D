/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/03 02:09:20 by macbook          ###   ########.fr       */
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

	cub->texture[0] = mlx_xpm_file_to_image(cub->mlx.mlx, "textures/bluestone.xpm", &width, &height);
	cub->texture[1] = mlx_xpm_file_to_image(cub->mlx.mlx, "textures/eagle.xpm", &width, &height);
	cub->texture[2] = mlx_xpm_file_to_image(cub->mlx.mlx, "textures/purplestone.xpm", &width, &height);
	cub->texture[3] = mlx_xpm_file_to_image(cub->mlx.mlx, "textures/pillar.xpm", &width, &height);
	cub->texture[4] = mlx_xpm_file_to_image(cub->mlx.mlx, "textures/bluestone.xpm", &width, &height);
}

int		ft_key_hook(int keycode, t_cub *cub)
{
	double rotSpeed = 1.0;

	int worldMap[24][24]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	if (keycode == 126)
	{
		if (worldMap[(int)(cub->camera.posX + cub->camera.dirX)][(int)cub->camera.posY] == 0)
			cub->camera.posX += cub->camera.dirX;
		if (worldMap[(int)cub->camera.posX][(int)(cub->camera.posY + cub->camera.dirY)] == 0)
			cub->camera.posY += cub->camera.dirY;
	}
	else if (keycode == 125)
	{
		if (worldMap[(int)(cub->camera.posX - cub->camera.dirX)][(int)cub->camera.posY] == 0)
			cub->camera.posX -= cub->camera.dirX;
		if (worldMap[(int)cub->camera.posX][(int)(cub->camera.posY - cub->camera.dirY)] == 0)
			cub->camera.posY -= cub->camera.dirY;
	}
	else if (keycode == 123)
	{
		double	oldDirX = cub->camera.dirX;
		cub->camera.dirX = cub->camera.dirX * cos(rotSpeed) - cub->camera.dirY * sin(rotSpeed);
		cub->camera.dirY = oldDirX * sin(rotSpeed) + cub->camera.dirY * cos(rotSpeed);
		double oldPlaneX = cub->camera.planeX;
		cub->camera.planeX = cub->camera.planeX * cos(rotSpeed) - cub->camera.planeY * sin(rotSpeed);
		cub->camera.planeY = oldPlaneX * sin(rotSpeed) + cub->camera.planeY * cos(rotSpeed);
	}
	else if (keycode == 124)
	{
		double	oldDirX = cub->camera.dirX;
		cub->camera.dirX = cub->camera.dirX * cos(-rotSpeed) - cub->camera.dirY * sin(-rotSpeed);
		cub->camera.dirY = oldDirX * sin(-rotSpeed) + cub->camera.dirY * cos(-rotSpeed);
		double	oldPlaneX = cub->camera.planeX;
		cub->camera.planeX = cub->camera.planeX * cos(-rotSpeed) - cub->camera.planeY * sin(-rotSpeed);
		cub->camera.planeY = oldPlaneX * sin(-rotSpeed) + cub->camera.planeY * cos(-rotSpeed);
	}
	else
		ft_putstr("touche inconnue!\n");
	raycast(cub);
	return(1);
}

void	ray_init(t_cub *cub)
{
	cub->camera.rayDirX = cub->camera.dirX + cub->camera.planeX * cub->camera.cameraX;
	cub->camera.rayDirY = cub->camera.dirY + cub->camera.planeY * cub->camera.cameraX;
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
		cub->camera.sideDistX = (cub->camera.posX - cub->camera.mapX) * cub->camera.deltaDistX;
	}
	else
	{
		cub->camera.stepX = 1;
		cub->camera.sideDistX = (cub->camera.mapX + 1.0 - cub->camera.posX) * cub->camera.deltaDistX;
	}
	if (cub->camera.rayDirY < 0)
	{
		cub->camera.stepY = -1;
		cub->camera.sideDistY = (cub->camera.posY - cub->camera.mapY) * cub->camera.deltaDistY;
	}
	else
	{
		cub->camera.stepY = 1;
		cub->camera.sideDistY = (cub->camera.mapY + 1.0 - cub->camera.posY) * cub->camera.deltaDistY;
	}
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
	if (cub->camera.side == 0)
		cub->camera.perpWallDist = (cub->camera.mapX - cub->camera.posX + (1 - cub->camera.stepX) / 2) / cub->camera.rayDirX;
	else
		cub->camera.perpWallDist = (cub->camera.mapY - cub->camera.posY + (1 - cub->camera.stepY) / 2) / cub->camera.rayDirY;
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

void	text_calc(t_cub	*cub)
{
	int worldMap[24][24]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	cub->camera.texNum = worldMap[cub->camera.mapX][cub->camera.mapY] - 1;
	if (cub->camera.side == 0)
		cub->camera.wallX = cub->camera.posY + cub->camera.perpWallDist * cub->camera.rayDirY;
	else
		cub->camera.wallX = cub->camera.posX + cub->camera.perpWallDist * cub->camera.rayDirX;
	cub->camera.wallX -= floor(cub->camera.wallX);

	cub->camera.texX = (int)(cub->camera.wallX * (double)texWidth);
	if (cub->camera.side == 0 && cub->camera.rayDirX > 0)
		cub->camera.texX = texWidth - cub->camera.texX - 1;
	if (cub->camera.side == 1 && cub->camera.rayDirY < 0)
		cub->camera.texX = texWidth - cub->camera.texX - 1;
	
	cub->camera.step = 1.0 * texHeight / cub->camera.lineHeight;
    cub->camera.texPos = (double)(cub->camera.drawStart - cub->mlx.screenHeight / 2 + cub->camera.lineHeight / 2) * cub->camera.step;
}

void	draw_scanline(t_cub *cub, int x, t_vec limit, int color)
{
	unsigned	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;

	img_ptr = (unsigned*)mlx_get_data_addr(cub->image.img_ptr, &bpp, &size_line, &endian);
	while (limit.x++ < limit.y)
	{
        img_ptr[(limit.x * size_line / 4) + x] = color;
	}
}

void	draw_textured_row(t_cub *cub, int x, int y)
{
	unsigned	*img_ptr;
    unsigned	*color_ptr;
	int			bpp;
    int			size_line;
    int			endian;
	unsigned	color;
	
	color_ptr = (unsigned*)mlx_get_data_addr(cub->texture[cub->camera.texNum], &bpp, &size_line, &endian);
    color = (unsigned)(color_ptr[texHeight * cub->camera.texY + cub->camera.texX]);
	if (cub->camera.side == 1)
      color = (unsigned)(color >> 1) & 8355711;
    img_ptr = (unsigned*)mlx_get_data_addr(cub->image.img_ptr, &bpp, &size_line, &endian);
	img_ptr[(y * size_line / 4) + x] = color;
}

void    draw(t_cub *cub, int x)
{
    int         y;
	int			height;
	int			begin;
	int			end;

    y = cub->camera.drawStart;
	height = (int)(cub->mlx.screenHeight / cub->camera.perpWallDist);
	begin = -height / 2 + cub->mlx.screenHeight / 2;
	if (begin < 0)
		begin = 0;
    while (y < cub->camera.drawEnd)
    {
        cub->camera.texY = (int)cub->camera.texPos & (texHeight - 1);
        cub->camera.texPos += cub->camera.step;
		draw_scanline(cub, x, (t_vec){0, begin - 1}, 0xFF0000);
		end = height / 2 + cub->mlx.screenHeight / 2;
		if (end >= cub->mlx.screenHeight)
			end = cub->mlx.screenHeight - 1;
		draw_textured_row(cub, x, y);
        draw_scanline(cub, x, (t_vec){end + 1, cub->mlx.screenHeight - 1}, 0x00FF00);
		y++;
    }
}

void	raycast(t_cub *cub)
{
	int	i;

	i = 0;
	mlx_clear_img(cub->image.img_ptr, cub->mlx.screenHeight);
	while (i++ < cub->mlx.screenWidth)
	{
		cub->camera.hit = 0;
		cub->camera.cameraX = (2 * i / (double)cub->mlx.screenWidth - 1);
		ray_init(cub);
		raycast_init(cub);
		dda(cub);
		perp_wall_dist(cub);
		draw_calc(cub);
		text_calc(cub);
		draw(cub, i);
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.window, cub->image.img_ptr, 0, 0);
}

void	mlx_gestion(t_cub *cub)
{
	cub->camera.posX = 22;
	cub->camera.posY = 12;
	cub->camera.planeX = 0.0;
	cub->camera.planeY = 0.66;
	cub->camera.dirX = -1.0;
	cub->camera.dirY = 0;
	cub->mlx.mlx = mlx_init();
	cub->mlx.window = mlx_new_window(cub->mlx.mlx, cub->mlx.screenWidth, cub->mlx.screenWidth, "Cub3D");
	cub->image.img_ptr = mlx_new_image(cub->mlx.mlx, cub->mlx.screenWidth, cub->mlx.screenHeight);
	mlx_clear_img(cub->image.img_ptr, cub->mlx.screenWidth);
	texture(cub);
	raycast(cub);
	mlx_key_hook(cub->mlx.window, ft_key_hook, cub);
	mlx_loop(cub->mlx.mlx);
}
