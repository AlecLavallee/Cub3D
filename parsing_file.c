/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/05 11:37:03 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_sprite(char *sprite, t_cub *cub)
{
	ft_putstr("Sprite!\n");
	(void)sprite;
	(void)cub;
}

void	parse_textures(char *texture, t_cub *cub)
{
	size_t	i;
	int		fd;

	i = 0;
	ft_putstr("Textures!\n");
	while (ft_isspace(texture[i]))
		i++;
	if ((fd = open(&texture[i], O_RDONLY)) > -1)
		return (display_error("Cannot open texture file, check your paths!"));
	(void)cub;
}

void	parse_map(char **map, t_cub *cub)
{
	ft_putstr("Map!\n");
	(void)map;
	/*while (*map)
	{
		ft_putstr(*map++);
		ft_putchar('\n');
	}*/
	(void)cub;
}