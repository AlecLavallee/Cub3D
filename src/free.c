/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:01:35 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/24 04:51:50 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_cub *cub)
{
	while (cub->map.ysize--)
		free(cub->map.map[cub->map.ysize]);
	free(cub->map.map);
}

void	free_textures(t_cub *cub)
{
	free(cub->map.textures.no.image.img_ptr);
	free(cub->map.textures.no.image.img_data);
	free(cub->map.textures.so.image.img_ptr);
	free(cub->map.textures.so.image.img_data);
	free(cub->map.textures.we.image.img_ptr);
	free(cub->map.textures.we.image.img_data);
	free(cub->map.textures.ea.image.img_ptr);
	free(cub->map.textures.ea.image.img_data);
	free(cub->map.textures.sprite.image.img_ptr);
	free(cub->map.textures.sprite.image.img_data);
}

int		close_game(t_cub *cub)
{
	free_textures(cub);
	free_map(cub);
	if (cub->flags & IMG)
		mlx_destroy_image(cub->mlx.mlx, cub->image.img_ptr);
	free(cub->image.img_data);
	if (cub->mlx.window != NULL)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.window);
	exit(0);
}