/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:36:44 by alelaval          #+#    #+#             */
/*   Updated: 2021/02/17 14:08:03 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	write_metadata(t_cub *cub, int fd, t_bmp file)
{
	write_file(cub, fd, file.file_header);
	write_info(cub, fd, file.info_header);
	//write(fd, &cub->image.img_ptr, file.info_header.img_size);
}

void	save(t_cub *cub, char const *filename)
{
	int		fd;
	t_bmp	file;

	file = cub->bmp;
	fd = open(filename, O_WRONLY | O_CREAT , S_IRWXU | S_IROTH | S_IRGRP); 
	if (fd < 0)
		display_error(cub, "invalid file descriptor");
	write_metadata(cub, fd, file);
	cub->bmp.data = (unsigned int *)cub->image.img_ptr;
	if (cub->bmp.data == NULL)
		display_error(cub, "failed to load data");
	/*if (write(fd, cub->bmp.data, 50 + (cub->mlx.screenwidth * cub->mlx.screenheight) \
	* (file.info_header.bit_per_pix / 8)) == -1)
		display_error(cub, "error while saving game");*/
	close_game(cub);
}
