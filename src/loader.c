/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:01:35 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/19 13:58:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	load_tex(t_cub *cub, char *path)
{
	t_texture	tex;
	int			config[3];
	int			test;

	while (ft_isspace(*path))
		path++;
	test = open(path, O_RDONLY);
	if (test == -1)
		display_error(cub, "Texture path invalid!");
	tex.image.img_ptr = mlx_xpm_file_to_image(cub->mlx.mlx, path,
			&tex.width, &tex.height);
	if (!tex.image.img_ptr)
		display_error(cub, "Invalid XPM file!");
	config[0] = 32;
	config[1] = tex.width * 4;
	config[2] = 0;
	tex.image.img_data = (int *)mlx_get_data_addr(tex.image.img_ptr,
			&config[0], &config[1], &config[2]);
	return (tex);
}

void	texture_loader(t_cub *cub, const char *type, char *line)
{
	if (ft_strncmp(type, "NO", 2) == 0 && !check_flag(cub, NO, 0))
		cub->map.textures.no = load_tex(cub, line + 3);
	if (ft_strncmp(type, "EA", 2) == 0 && !check_flag(cub, EA, 0))
		cub->map.textures.ea = load_tex(cub, line + 3);
	if (ft_strncmp(type, "WE", 2) == 0 && !check_flag(cub, WE, 0))
		cub->map.textures.we = load_tex(cub, line + 3);
	if (ft_strncmp(type, "SO", 2) == 0 && !check_flag(cub, SO, 0))
		cub->map.textures.so = load_tex(cub, line + 3);
	if ((ft_strncmp(type, "S.", 2) == 0 || ft_strncmp(type, "S .", 3) == 0)
		&& !check_flag(cub, S, 0))
		cub->map.textures.sprite = load_tex(cub, line + 2);
}
