/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/17 13:32:19 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_sprite(char *sprite, t_cub *cub)
{
	size_t	i;

	i = 0;
	while (ft_isalpha(sprite[i]))
		i++;
	while (ft_isspace(sprite[i]))
		i++;
	if ((cub->path.sprite_fd = open(&sprite[i], O_RDONLY)) == -1)
		return (display_error("Cannot open sprite file, check your paths!"));
	(void)cub;
}

void	parse_textures(char *texture, t_cub *cub)
{
	size_t	i;
	int		fd;

	i = 0;
	while (ft_isalpha(texture[i]))
		i++;
	while (ft_isspace(texture[i]))
		i++;
	if ((fd = open(&texture[i], O_RDONLY)) == -1)
		return (display_error("Cannot open texture file, check your paths!"));
	(void)cub;
}

void	parse_resolution(char *res, t_cub *cub)
{
	size_t	i;
	size_t	nb_words;

	i = 0;
	nb_words = 0;
	while (*(res + i))
	{
		while (ft_isspace(*(res + i)))
			i++;
		while (*(res + i) && ft_isalnum(*(res + i)))
			i++;
		nb_words++;
	}
	if (nb_words != 3)
		return (display_error("Resolution in .cub is invalid!"));
	i = 0;
	while (!ft_isspace(*(res + i)) || (*(res + i) == 'R'))
		i++;
	cub->x_axis = ft_atoi(res + i);
	while (ft_isspace(*(res + i)))
		i++;
	while (!ft_isspace(*(res + i)))
		i++;
	cub->y_axis = ft_atoi(res + i);
}
