/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:33:19 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 17:20:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	check_colors(t_cub *cub, int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
		display_error(cub, "one of the colors is above 255!");
	if (r < 0 || g < 0 || b < 0)
		display_error(cub, "one of the colors is below 255!");
}

void	set_color(unsigned char color[4], unsigned char r, unsigned char g,
		unsigned char b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = 0;
}

void	affect_colors(t_cub *cub, int res[3], char type)
{
	if (type == 'C')
	{
		set_color(cub->map.colorceiling, (unsigned char)res[0],
			(unsigned char)res[1], (unsigned char)res[2]);
		check_flag(cub, CC, 1);
	}
	else if (type == 'F')
	{
		set_color(cub->map.colorfloor, (unsigned char)res[0],
			(unsigned char)res[1], (unsigned char)res[2]);
		check_flag(cub, CF, 1);
	}
}

void	parse_color(t_cub *cub, char *line)
{
	char			type;
	int				res[3];

	type = *line;
	line++;
	res[0] = ft_atoi(line);
	check_spacing(cub, &line);
	res[1] = ft_atoi(line);
	check_spacing(cub, &line);
	res[2] = ft_atoi(line);
	check_ending(cub, &line);
	check_colors(cub, res[0], res[1], res[2]);
	affect_colors(cub, res, type);
}
