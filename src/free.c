/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:01:35 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/16 12:17:48 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    free_map(t_cub *cub)
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
	free(cub->map.textures.sprite.image.img_data);
	free(cub->map.textures.sprite.image.img_data);
}

int    close_game(t_cub *cub)
{
    ft_putstr("Closing!\n");
    free(cub->mlx.mlx);
    free(cub->mlx.window);
    free(cub->image.img_ptr);
    free(cub->image.img_data);
	free_textures(cub);
    free_map(cub);
	free(cub->map.line);
    //ft_lstclear(&cub->file.lstmap, (void*)ft_lstdelone);
    free(cub->file.name);
    free(cub->file.path);
    exit(0);
}