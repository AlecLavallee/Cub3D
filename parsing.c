/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/01/28 10:34:42 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		open_cub(char *file)
{
	int		fd;
	char	*dot;

	fd = -1;
	dot = ft_strrchr(file, '.');
	if (!dot)
	{
		display_error("file does not have an extension at all!");
		return (-1);
	}
	if (dot && !ft_strcmp(dot, ".cub"))
	{
		if ((fd = open(file, O_RDONLY)) < 0)
		{
			display_error(".cub file is not found or cannot be accessed :(");
			return (-1);
		}
	}
	else
		display_error("file does not have .cub extension!");
	return (fd);
}

char	**read_cub(char **map, int fd)
{
	char	*line;

	map = NULL;
	while ((get_next_line(fd, &line) == 1))
	{
		free(line);
	}
	return (map);
}

void	parsing(char *file)
{
	int		fd;
	char	**map;

	map = NULL;
	fd = open_cub(file);
	if (fd != -1)
		map = read_cub(map, fd);
	else
		return ;
	return ;
}

void	save()
{
	;
}
