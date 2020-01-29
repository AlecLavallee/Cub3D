/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/01/29 16:32:43 by alelaval         ###   ########.fr       */
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

void	parse_map(char **map, t_cub *cub)
{
	ft_putstr("Map!\n");
	while (*map)
	{
		ft_putstr(*map++);
		ft_putchar('\n');
	}
	(void)cub;
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
	size_t	nb_lines;
	size_t	i;

	i = 0;
	nb_lines = 0;
	map = NULL;
	line = NULL;
	while (get_next_line(fd, &line))
		nb_lines++;
	close(fd);
	map = (char**)malloc(sizeof(char*) * ++nb_lines);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) && nb_lines--)
		map[i++] = line;
	while (ft_isspace(*line))
		line++;
	if (*line != '\0')
		map[i++] = line;
	map[i] = NULL;
	return (map);
}

void	parse_cub(char **map, t_cub *cub)
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
		else if (map[i][j] == 'S' && map[i][j + 1] != 'O')
			parse_sprite();
		else if (!ft_strncmp(&map[i][j], "NO", 2) ||
			!ft_strncmp(&map[i][j], "SO", 2) ||
			!ft_strncmp(&map[i][j], "WE", 2) ||
			!ft_strncmp(&map[i][j], "EA ", 2))
			parse_textures();
		else if (map[i][j] == 'F' || map[i][j] == 'C')
			parse_colors();
		else if (map[i][j] == '1' || map[i][j] == '0')
			return (parse_map(map, cub));
		i++;
	}
}

t_cub	init_cub(t_cub *cub)
{
	cub->map = NULL;
	return (*cub);
}

void	parsing(char *file, t_cub *cub)
{
	int		fd;
	char	**file_cub;

	file_cub = NULL;
	init_cub(cub);
	fd = open_cub(file);
	if (fd != -1)
	{
		if ((file_cub = store_cub(file_cub, file, fd)))
			parse_cub(file_cub, cub);
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
