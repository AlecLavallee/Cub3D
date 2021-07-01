/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:36:44 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 17:18:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bmp_file_header	init_file(t_cub *cub)
{
	t_bmp_file_header	new;

	ft_memcpy(&new.file_type, "\x42\x4d", 2);
	new.file_size = 54 + \
		(cub->mlx.screenheight * cub->mlx.screenwidth * cub->image.bpp / 8);
	new.reserved1 = 0;
	new.reserved2 = 0;
	new.offset = 14 + 40;
	return (new);
}

t_bmp_info_header	init_header(t_cub *cub)
{
	t_bmp_info_header	new;

	new.header_size = 40;
	new.img_width = cub->mlx.screenwidth;
	new.img_height = -cub->mlx.screenheight;
	new.planes = 1;
	new.bit_per_pix = 32;
	new.compression = 0;
	new.img_size = 0;
	new.x_pixels_per_meter = 0;
	new.y_pixels_per_meter = 0;
	new.colors_used = 0;
	new.colors_important = 0;
	return (new);
}

void	write_file(t_cub *cub, int fd, t_bmp_file_header file)
{
	int		ret;

	ret = 0;
	ret = write(fd, &file.file_type, 2);
	ret = write(fd, &file.file_size, 4);
	ret = write(fd, &file.reserved1, 2);
	ret = write(fd, &file.reserved2, 2);
	ret = write(fd, &file.offset, 4);
	if (ret < 0)
	{
		display_error(cub, "BMP Header invalid");
		close_game(cub);
	}
}

void	write_info(t_cub *cub, int fd, t_bmp_info_header file)
{
	int		ret;

	ret = 0;
	ret = write(fd, &file.header_size, 4);
	ret = write(fd, &file.img_width, 4);
	ret = write(fd, &file.img_height, 4);
	ret = write(fd, &file.planes, 2);
	ret = write(fd, &file.bit_per_pix, 2);
	ret = write(fd, &file.compression, 4);
	ret = write(fd, &file.img_size, 4);
	ret = write(fd, &file.x_pixels_per_meter, 4);
	ret = write(fd, &file.y_pixels_per_meter, 4);
	ret = write(fd, &file.colors_used, 4);
	ret = write(fd, &file.colors_important, 4);
	if (ret < 0)
	{
		display_error(cub, "BMP info header invalid");
		close_game(cub);
	}
}

t_bmp	get_metadata(t_cub *cub)
{
	t_bmp	new;

	new.file_header = init_file(cub);
	new.info_header = init_header(cub);
	new.data = (uint8_t *)mlx_get_data_addr(cub->image.img_ptr, \
		&cub->image.bpp, &cub->image.linesize, &cub->image.endian);
	return (new);
}
