/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:37:52 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/24 02:36:49 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	set_textures(t_cub *cub)
{
	cub->image.img_ptr = NULL;
	cub->image.img_data = NULL;
	cub->map.textures.no.image.img_ptr = NULL;
	cub->map.textures.no.image.img_data = NULL;
	cub->map.textures.so.image.img_ptr = NULL;
	cub->map.textures.so.image.img_data = NULL;
	cub->map.textures.we.image.img_ptr = NULL;
	cub->map.textures.we.image.img_data = NULL;
	cub->map.textures.ea.image.img_ptr = NULL;
	cub->map.textures.ea.image.img_data = NULL;
	cub->map.textures.sprite.image.img_ptr = NULL;
	cub->map.textures.sprite.image.img_data = NULL;
}

t_cub	*init_cub(t_cub *cub)
{
	cub->flags = 0;
	set_textures(cub);
	cub->map.map = NULL;
	cub->map.line = NULL;
	cub->mlx.window = NULL;
	cub->camera.dirX = -1.0;
	cub->camera.dirY = 0.0;
	cub->camera.planeX = 0.0;
	cub->camera.planeY = 0.66;
	cub->camera.hit = 0;
	cub->camera.rotSpeed = 0.15;
	cub->player.moveSpeed = 0.15;
	return (cub);
}
