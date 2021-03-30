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
	unsigned	file_type;
	unsigned	file_size;
	unsigned	reserved1;
	unsigned	reserved2;
	unsigned	offset;
}				t_bmp_file_header;

typedef struct	s_bmp_info_header {
	unsigned	header_size;
	int			img_width;
	int			img_height;
	unsigned	planes;
	unsigned	bit_per_pix;
	unsigned	compression;
	unsigned	img_size;
	int			x_pixels_per_meter;
	int			y_pixels_per_meter;
	unsigned	colors_used;
	unsigned	colors_important;
}				t_bmp_info_header;

typedef struct	s_bmp {
	t_bmp_file_header	file_header;
	t_bmp_info_header	info_header;
	uint8_t				*data;
}				t_bmp;

void	save_error(void);
void	save(t_cub *cub, const char *file);
void	write_metadata(t_cub *cub, int fd, t_bmp file);
void	write_data(t_cub *cub, int fd, t_bmp file);

#endif