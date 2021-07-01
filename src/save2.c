/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:41 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 17:55:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_metadata(t_cub *cub, int fd, t_bmp file)
{
	write_file(cub, fd, file.file_header);
	write_info(cub, fd, file.info_header);
}

void	save(t_cub *cub, char const *filename)
{
	int		fd;
	int		size;
	t_bmp	file;

	size = cub->mlx.screenheight * cub->mlx.screenwidth;
	(void)size;
	fd = \
	open(filename, \
		O_WRONLY | O_CREAT, S_IRWXU | S_IROTH | S_IRGRP);
	if (fd < 0)
		display_error(cub, "invalid file descriptor");
	file = get_metadata(cub);
	write_metadata(cub, fd, file);
	if (file.data == NULL)
		display_error(cub, "failed to load data");
	if (write(fd, file.data, (cub->mlx.screenheight * cub->mlx.screenwidth \
		* file.info_header.bit_per_pix / 8)) == -1)
		display_error(cub, "error while saving game");
	close_game(cub);
}
