/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:33:19 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/06 13:34:19 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		count_words(char *str)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 1;
	while (ft_isspace(str[i]) || str[i] == 'F' || str[i] == 'C')
		i++;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		while (ft_isdigit(str[i]) || str[i] == ',')
			i++;
		nb_words++;
	}
	return (nb_words);
}

void	parse_colors_f(char *color, t_cub *cub)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	if (count_words(color) != 2)
		return (display_error("Formatting in floor color invalid."));
	while (ft_isspace(color[i]))
		i++;
	if (color[i++] == 'F')
	{
		while (ft_isdigit(*(color + i)) || *(color + i) == '-')
			i++;
		cub->floor[index++] = ft_atoi(&color[++i]);
		while (ft_isdigit(*(color + i)) || *(color + i) == '-')
			i++;
		cub->floor[index++] = ft_atoi(&color[++i]);
		while (ft_isdigit(*(color + i)) || *(color + i) == '-')
			i++;
		cub->floor[index++] = ft_atoi(&color[++i]);
	}
	while (index-- > 0)
		if (cub->floor[index] < 0 || cub->floor[index] > 255)
			return (display_error("Color in floor invalid."));
}

void	parse_colors_c(char *color, t_cub *cub)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	if (count_words(color) != 2)
		return (display_error("Formatting in ceiling color invalid."));
	while (ft_isspace(color[i]))
		i++;
	if (color[i++] == 'C')
	{
		while (ft_isdigit(*(color + i)) || *(color + i) == '-')
			i++;
		cub->ceiling[index++] = ft_atoi(&color[++i]);
		while (ft_isdigit(*(color + i)) || *(color + i) == '-')
			i++;
		cub->ceiling[index++] = ft_atoi(&color[++i]);
		while (ft_isdigit(*(color + i)) || *(color + i) == '-')
			i++;
		cub->ceiling[index++] = ft_atoi(&color[++i]);
	}
	while (index-- > 0)
		if (cub->ceiling[index] < 0 || cub->ceiling[index] > 255)
			return (display_error("Color in ceiling invalid"));
}
