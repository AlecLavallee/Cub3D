/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:01:35 by alelaval          #+#    #+#             */
/*   Updated: 2021/04/12 15:43:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_cub *cub)
{
	int i;

	i = 0;
	while (cub->map.map[i] != NULL)
		free(cub->map.map[i++]);
	free(cub->map.map);
}

void	free_textures(t_cub *cub)
{
	if (cub->map.textures.no.image.img_ptr)
		mlx_destroy_image(cub->mlx.mlx, cub->map.textures.no.image.img_ptr);
	if (cub->map.textures.so.image.img_ptr)
		mlx_destroy_image(cub->mlx.mlx, cub->map.textures.so.image.img_ptr);
	if (cub->map.textures.we.image.img_ptr)
		mlx_destroy_image(cub->mlx.mlx, cub->map.textures.we.image.img_ptr);
	if (cub->map.textures.ea.image.img_ptr)
		mlx_destroy_image(cub->mlx.mlx, cub->map.textures.ea.image.img_ptr);
	if (cub->map.textures.sprite.image.img_ptr)
		mlx_destroy_image(cub->mlx.mlx, cub->map.textures.sprite.image.img_ptr);
}

int		close_game(t_cub *cub)
{
	free_textures(cub);
	if (cub->map.map == NULL)
		;
	else
		free_map(cub);
	if (cub->image.img_ptr)
		mlx_destroy_image(cub->mlx.mlx, cub->image.img_ptr);
	if (cub->mlx.window)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.window);
	exit(0);
}
