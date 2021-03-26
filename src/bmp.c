/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:19:31 by alelaval          #+#    #+#             */
/*   Updated: 2021/02/01 22:40:43 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_bmp_file_header		get_file_header(uint file_size, uint offset)
{
	t_bmp_file_header	new;

	ft_memcpy(&new.file_type, "\x42\x4D", 2);
	new.file_size = file_size;
	new.reserved1 = 0;
	new.reserved2 = 0;
	new.offset = offset;
	return (new);
}

t_bmp_info_header		get_info_header(unsigned *res, int bit_per_pix)
{
	t_bmp_info_header	new;

	new.header_size = INFO_SIZE;
	new.img_width = res[0];
	new.img_height = -res[1];
	new.planes = 1;
	new.bit_per_pix = bit_per_pix;
	new.compression = 0;
	new.img_size = 0;
	new.x_pixels_per_meter = 0;
	new.y_pixels_per_meter = 0;
	new.colors_used = 0;
	new.colors_important = 0;
	return (new);
}

t_bmp					get_metadata(void *mlx_img, unsigned *res_img)
{
	t_bmp	new;
	int		bits_per_pix;
	int		size;
	int		endian;
	int		offset;

	new.data = (uint8_t *)mlx_get_data_addr(mlx_img, &bits_per_pix, \
	&size, &endian);
	offset = FILE_SIZE + INFO_SIZE;
	size = res_img[0] * res_img[1] * (bits_per_pix / 8) + offset;
	new.file_header = get_file_header(size, offset);
	new.info_header = get_info_header(res_img, bits_per_pix);
	return (new);
}
