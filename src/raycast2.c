/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/08 15:43:50 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	cub->camera.texPos = (double)(cub->camera.drawStart - cub->mlx.screenHeight / 2 \
	+ cub->camera.lineHeight / 2) * cub->camera.step;
}

void	draw_scanline(t_cub *cub, int x, t_vec limit, int color)
{
	unsigned	*img_ptr;
	int			bpp;
	int			size_line;
	int			endian;

	img_ptr = (unsigned*)mlx_get_data_addr(cub->image.img_ptr, &bpp, &size_line, &endian);
	while (limit.x++ < limit.y)
		img_ptr[(limit.x * size_line / 4) + x] = color;
}

t_texture	*get_tex_ptr(t_cub *cub, int index)
{
	if (index == 0)
		return (&cub->map.textures.no);
	if (index == 1)
		return (&cub->map.textures.so);
	if  (index == 2)
		return (&cub->map.textures.we);
	if (index == 3)
		return (&cub->map.textures.ea);
	if (index == 4)
		return (&cub->map.textures.sprite);
	return (NULL);
}

void	draw_textured_row(t_cub *cub, int x, int y)
{
	t_texture	*tex_ptr;
	unsigned	*img_ptr;
	unsigned	*color_ptr;
	int			bpp;
	int			size_line;
	int			endian;
	unsigned	color;

	// doit definir side du mur
	tex_ptr = get_tex_ptr(cub, cub->camera.texNum);
	color_ptr = (unsigned*)mlx_get_data_addr(tex_ptr->image.img_ptr, &bpp, &size_line, &endian);
	color = \
	(unsigned)(color_ptr[texHeight * cub->camera.texY + cub->camera.texX]);
	if (cub->camera.side == 1)
		color = (unsigned)(color >> 1) & 8355711;
	img_ptr = (unsigned*)mlx_get_data_addr(cub->image.img_ptr, \
	&bpp, &size_line, &endian);
	img_ptr[(y * size_line / 4) + x] = color;
}

void	draw(t_cub *cub, int x)
{
	int		y;
	int		height;
	int		begin;
	int		end;

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
		draw_scanline(cub, x, (t_vec){end + 1, cub->mlx.screenHeight - 1}, \
		0x00FF00);
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
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.window, \
	cub->image.img_ptr, 0, 0);
}
