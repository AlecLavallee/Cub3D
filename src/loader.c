/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:01:35 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/03 17:30:39 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_tex(t_cub *cub, t_texture *tex_ptr)
{
	int		width;
	int		height;

	width = 0;
	height = 0;
	tex_ptr = mlx_xpm_file_to_image(cub->mlx.mlx, \
	"textures/bluestone.xpm", &width, &height);
	tex_ptr->width = width;
	tex_ptr->height = height;
}

void	load_textures(t_cub *cub)
{
	load_tex(cub, &cub->map.textures.no);
	load_tex(cub, &cub->map.textures.so);
	load_tex(cub, &cub->map.textures.we);
	load_tex(cub, &cub->map.textures.ea);
}