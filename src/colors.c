/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:33:19 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/07 12:56:36 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/* DANGER */
# include <fcntl.h>
# include <limits.h>

static void		set_color(unsigned char color[4], unsigned char r, unsigned char g, \
		unsigned char b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = 0;
}

void			parse_color(t_cub *cub, char *line)
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
		set_color(cub->map.colorCeiling, res[0], res[1], res[2]);
	else if (type == 'F')
		set_color(cub->map.colorFloor, res[0], res[1], res[2]);
}

char	*skip_spaces(const char *s)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && ft_isspace(*s))
		s++;
	return ((char*)s);
}

char	*skip_digits(const char *s)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && ft_isdigit(*s))
		s++;
	return ((char*)s);
}

char	*skip_char(const char *s, unsigned char c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && *s == c)
		s++;
	return ((char*)s);
}

char	*skip(char *line)
{
	line = skip_digits(line);
	line = skip_spaces(line);
	line = skip_char(line, ',');
	line = skip_spaces(line);
	return (line);
}
