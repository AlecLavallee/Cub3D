/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:25:15 by alelaval          #+#    #+#             */
/*   Updated: 2021/02/01 22:45:47 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_H

#define SAVE_H

#include <stdint.h>

# define FILE_SIZE	14
# define INFO_SIZE	40

typedef struct	s_bmp_file_header {
	uint16_t	file_type;
	uint32_t	file_size;
	uint16_t	reserved1;
	uint16_t	reserved2;
	uint32_t	offset;
}				t_bmp_file_header;

typedef struct	s_bmp_info_header {
	uint32_t	header_size;
	int32_t		img_width;
	int32_t		img_height;
	uint16_t	planes;
	uint16_t	bit_per_pix;
	uint32_t	compression;
	uint32_t	img_size;
	int32_t		x_pixels_per_meter;
	int32_t		y_pixels_per_meter;
	uint32_t	colors_used;
	uint32_t	colors_important;
}				t_bmp_info_header;

typedef struct	s_bmp {
	t_bmp_file_header	file_header;
	t_bmp_info_header	info_header;
	uint8_t				*data;
}				t_bmp;

void	save(t_cub *cub, const char *file);
t_bmp   write_metadata(void *img_mlx, unsigned *res);

#endif