/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:33:19 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/24 06:06:30 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	set_color(unsigned char color[4], unsigned char r, unsigned char g,
		unsigned char b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = 0;
}

void	parse_color(t_cub *cub, char *line)
{
	char			type;
	unsigned char	res[3];

	type = *line;
	line += 2;
	res[0] = (unsigned char)ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line += (*line == ',');
	res[1] = (unsigned char)ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line += (*line == ',');
	res[2] = (unsigned char)ft_atoi(line);
	if (type == 'C')
	{
		set_color(cub->map.colorCeiling, res[0], res[1], res[2]);
		check_flag(cub, CC, 1);
	}
	else if (type == 'F')
	{
		set_color(cub->map.colorFloor, res[0], res[1], res[2]);
		check_flag(cub, CF, 1);
	}
}
