/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:01:35 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/04 18:28:14 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_tex(t_cub *cub, const char *path, int index)
{
	void	*img_ptr;
	int		width;
	int		height;

	if (path != NULL)
	{
		img_ptr = mlx_xpm_file_to_image(cub->mlx.mlx, \
		(char*)path, &width, &height);
		if (img_ptr == NULL)
		{
			/*if (width != texWidth || height != texHeight)
				display_error("texture resolution invalid!");*/
			cub->map.textures[index].image.img_ptr = img_ptr;
			ft_strlcpy(cub->map.textures[index].path, path, sizeof(path));
			cub->map.textures[index].width = width;
			cub->map.textures[index].height = height;
		}
		else
			display_error("Trying to load texture from xpm failed!");
	}
	else
		display_error("invalid path for texture!");
}
