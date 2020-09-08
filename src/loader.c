/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:01:35 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/08 19:11:51 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	load_tex(t_cub *cub, char *path)
{
	t_texture		tex;
	int			config[3];

	tex.image.img_ptr = mlx_xpm_file_to_image(cub->mlx.mlx, path,
			&tex.width, &tex.height);
	if (!tex.image.img_ptr)
		return (tex);
	config[0] = 32;
	config[1] = tex.width * 4;
	config[2] = 0;
	tex.image.img_data = (int *)mlx_get_data_addr(tex.image.img_ptr,
			&config[0], &config[1], &config[2]);
	return (tex);
}
