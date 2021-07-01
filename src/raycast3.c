/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 01:39:22 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 18:39:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_tex_ptr(t_cub *cub, int index)
{
	if (index == 0)
		return (&cub->map.textures.no);
	if (index == 1)
		return (&cub->map.textures.so);
	if (index == 2)
		return (&cub->map.textures.we);
	if (index == 3)
		return (&cub->map.textures.ea);
	if (index == 4)
		return (&cub->map.textures.sprite);
	return (NULL);
}

void	sprite_manager(t_cub *cub)
{
	t_s		*sprites;

	sprites = get_sprites(cub);
	combsort_sprites(sprites, count_sprites(cub));
	draw_sprites(cub, sprites);
	free(cub->camera.zbuffer);
	free(sprites);
}

void	raycast_core(t_cub *cub, int *i)
{
	cub->camera.camerax = (2 * (*i) / (double)cub->mlx.screenwidth - 1);
	ray_init(cub);
	raycast_init(cub);
	dda(cub);
	perp_wall_dist(cub);
	draw_calc(cub);
	text_calc(cub);
	get_tex_num(cub);
	draw(cub, *i);
	cub->camera.zbuffer[(*i)++] = cub->camera.perpwalldist;
}

int	raycast(t_cub *cub)
{
	int		i;

	i = 0;
	mlx_clear_img(cub->image.img_ptr, cub->mlx.screenheight);
	player_move(cub);
	if (!(cub->camera.zbuffer
		= (double *)malloc(sizeof(double) * cub->mlx.screenwidth)))
		display_error(cub, "Zbuffer allocation failed!");
	while (i < cub->mlx.screenwidth)
		raycast_core(cub, &i);
	sprite_manager(cub);
	if (cub->save == 1)
		save(cub, "save");
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.window, \
	cub->image.img_ptr, 0, 0);
	return (0);
}
