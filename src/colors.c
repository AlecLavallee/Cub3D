/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:33:19 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/03 01:43:27 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/* DANGER */
# include <fcntl.h>
# include <limits.h>
# define TRUE 1
# define FALSE 0

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

int		has_valid_ext(const char *path)
{
	const size_t len = ft_strlen(path);
	const size_t ext_len = ft_strlen(".cub");

	if (len < 5)
		return (FALSE);
	if (ft_strncmp(&path[len - ext_len], ".cub", ext_len) != 0)
		return (FALSE);
	return (TRUE);
}

/*static char	*skip(char *line)
{
	line = skip_digits(line);
	line = skip_spaces(line);
	line = skip_char(line, ',');
	line = skip_spaces(line);
	return (line);
}

static void	get_color_ptr(t_cub *cub, const char *id, unsigned int **color)
{
	if (ft_strncmp(id, "C", 1) == 0)
		*color = &cub->map.ceil_color;
	else
		*color = &cub->map.floor_color;
}

int			parse_color(t_cub *cub, const char *id, char *line)
{
	const size_t	id_len = ft_strlen(id);
	unsigned int	*color;
	int				colors[RGB_SIZE];
	int				index;

	index = 0;
	line = &line[id_len];
	get_color_ptr(cub, id, &color);
	ft_memset(colors, 0, sizeof(int) * RGB_SIZE);
	line = skip_spaces(line);
	while (*line != '\0' && ft_isdigit(*line) && index < RGB_SIZE)
	{
		colors[index] = ft_atoi(line);
		if (colors[index] > 255 || colors[index] < 0)
			return (CODE_ERR_COLOR_OUT_OF_RANGE);
		line = skip(line);
		index++;
	}
	if (*line != '\0')
		return (CODE_ERR_BAD_CHARS_IN_COLORS);
	if (index != RGB_SIZE)
		return (CODE_ERR_COLOR_MISSING);
	*color = ft_encode_rgb(colors[0], colors[1], colors[2]);
	return (RET_NO_ERROR);
}*/