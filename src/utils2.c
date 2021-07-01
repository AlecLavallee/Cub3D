/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:37:52 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 18:01:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_string_res(t_cub *cub, char *line)
{
	line++;
	while (ft_isdigit(*line))
		line++;
	if (!ft_isspace(*line))
		display_error(cub, "invalid separation in resolution!");
	while (ft_isspace(*line))
		line++;
	while (ft_isdigit(*line))
		line++;
	while (*line)
	{
		if (!ft_isspace(*line))
			display_error(cub, \
			"invalid character after one or more descriptors!");
		line++;
	}
}

void	check_ending(t_cub *cub, char **line)
{
	while (ft_isdigit(**line))
		(*line)++;
	while (ft_isspace(**line))
		(*line)++;
	while (**line)
	{
		if (!ft_isspace(**line))
			display_error(cub, \
			"invalid character after one or more descriptors!");
		(*line)++;
	}
}

void	check_spacing(t_cub *cub, char **line)
{
	while (ft_isspace(**line))
		(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	while (ft_isspace(**line))
		(*line)++;
	if (**line != ',')
		display_error(cub, "invalid color!");
	*line += (**line == ',');
	while (ft_isspace(**line))
		(*line)++;
	if (!ft_isdigit(**line))
		display_error(cub, "invalid color!");
}
