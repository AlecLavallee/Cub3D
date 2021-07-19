/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:25:15 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/19 14:20:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_H

# define SAVE_H
# include <stdint.h>

# define FILE_SIZE	14
# define INFO_SIZE	40

typedef struct s_bmp_file_header {
	unsigned int	file_type;
	unsigned int	file_size;
	unsigned int	reserved1;
	unsigned int	reserved2;
	unsigned int	offset;
}				t_bmp_file_header;

typedef struct s_bmp_info_header {
	unsigned int	header_size;
	int				img_width;
	int				img_height;
	unsigned int	planes;
	unsigned int	bit_per_pix;
	unsigned int	compression;
	unsigned int	img_size;
	int				x_pixels_per_meter;
	int				y_pixels_per_meter;
	unsigned int	colors_used;
	unsigned int	colors_important;
}				t_bmp_info_header;

typedef struct s_bmp {
	t_bmp_file_header	file_header;
	t_bmp_info_header	info_header;
	uint8_t				*data;
}				t_bmp;

t_bmp	get_metadata(t_cub *cub);
void	save_error(void);
void	save(t_cub *cub, const char *file);
void	write_metadata(t_cub *cub, int fd, t_bmp file);
void	write_data(t_cub *cub, int fd, t_bmp file);
void	write_file(t_cub *cub, int fd, t_bmp_file_header file);
void	write_info(t_cub *cub, int fd, t_bmp_info_header file);
#endif