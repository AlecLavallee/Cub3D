/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/01/28 16:35:55 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	parse_textures(void)
{
	ft_putstr("Textures!\n");
}

void	parse_colors()
{
	ft_putstr("Colors!\n");
}

void	parse_resolution()
{
	ft_putstr("Resolution!\n");
}
void	parse_sprite()
{
	ft_putstr("Sprite!\n");
}

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

char	**store_cub(char **map, char *file, int fd)
{
	char	*line;
	size_t	i;

	i = 0;
	map = NULL;
	line = NULL;
	while ((get_next_line(fd, &line) == 1))
		i++;
	close(fd);
	map = (char**)malloc(sizeof(char*) * i + 1);
	i = 0;
	fd = open(file, O_RDONLY);
	while ((get_next_line(fd, &line) == 1))
		map[i++] = line;
	map[i] = NULL;
	return (map);
}

void	parse_cub(char **map)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			j++;
		if (map[i][j] == 'R')
			parse_resolution();
		else if (map[i][j] == 'S' && map[i][j] != 'O')
			parse_sprite();
		else if (ft_strncmp(&map[i][j], "NO", 2) == 0 || ft_strncmp(&map[i][j], "SO", 2) == 0 ||
			ft_strncmp(&map[i][j], "WE", 2) == 0 || ft_strncmp(&map[i][j], "EA", 2) == 0)
			parse_textures();
		else if (map[i][j] == 'F' || map[i][j] == 'C')
			parse_colors();
		i++;
	}
}

void	parsing(char *file)
{
	int		fd;
	char	**map;

	map = NULL;
	fd = open_cub(file);
	if (fd != -1)
	{
		if ((map = store_cub(map, file, fd)))
			parse_cub(map);
		else
			return ;
	}
	else
		return ;
	return ;
}

void	save()
{
	;
}
