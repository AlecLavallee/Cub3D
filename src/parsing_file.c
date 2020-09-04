/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/04 18:40:19 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	parse_sprite(char *sprite, t_cub *cub)
{
	size_t	i;

	i = 0;
	while (ft_isalpha(sprite[i]))
		i++;
	while (ft_isspace(sprite[i]))
		i++;
	load_tex(cub, &sprite[i], 4);
}

void	parse_textures(t_cub *cub, const char *texture, int index)
{
	size_t	i;

	i = 0;
	while (ft_isalpha(texture[i]))
		i++;
	while (ft_isspace(texture[i]))
		i++;
	printf("tex : %s\n", &texture[i]);
	load_tex(cub, &texture[i], index);
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
	cub->mlx.screenHeight = ft_atoi(res + i);
	while (ft_isspace(*(res + i)))
		i++;
	while (!ft_isspace(*(res + i)))
		i++;
	cub->mlx.screenWidth = ft_atoi(res + i);
}
