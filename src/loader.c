/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:01:35 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/03 16:52:49 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	load_texture(t_cub *cub, void *path)
{
	int		width;
	int		height;

	cub->map.textures.no.image.img_ptr = mlx_xpm_file_to_image(cub->mlx.mlx, \
	"textures/bluestone.xpm", &cub->map.textures.no.image.width, &cub->map.textures.no);

}