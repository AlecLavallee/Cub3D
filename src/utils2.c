/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:37:52 by alelaval          #+#    #+#             */
/*   Updated: 2021/04/21 16:01:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_string_res(t_cub *cub, char *line)
{
	while (!ft_isdigit(*line))
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
	while (ft_isdigit(**line) || ft_isspace(**line))
		(*line)++;
	if (**line != ',')
		display_error(cub, "missing comma!");
	*line += (**line == ',');
	while (ft_isspace(**line))
		(*line)++;
	if (!ft_isdigit(**line))
		display_error(cub, "invalid color!");
}
