/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/03 15:49:16 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_textures(char *texture, t_cub *cub)
{
	size_t	i;

	i = 0;
	ft_putstr("Textures!\n");
	while (ft_isspace(texture[i]))
		i++;
	(void)cub;
}

void	parse_colors(char *color, t_cub *cub)
{
	size_t	i;
	size_t	nb_words;

	i = 0;
	nb_words = 0;
	while (ft_isspace(*(color + i)))
		i++;
	if (*(color + i) == 'F')
	{
		while (*(color + i))
		{
			while (ft_isspace(*(color + i)))
				i++;
			while (ft_isdigit(*(color + i)))
				i++;
			nb_words++;
			if (*(color + i++) != ',' && nb_words > 3)
				return (display_error("Probleme de parsing!"));
			nb_words++;
		}
	}
	if (nb_words != 2)
		return (display_error("Color in .cub is invalid!"));
	i = 0;
	/*while (ft_isspace(color[i]))
		i++;
	if (color[i++] == 'F')
	{
		cub->floor[0] = ft_atoi(&color[i]);
	}
	else
		return (display_error("Color in .cub is invalid!"));
	*/printf("floor = %d, ceiling = %d\n", cub->floor[0], cub->ceiling[0]);
}

void	parse_resolution(char *res, t_cub *cub)
{
	size_t	i;
	size_t	nb_words;

	i = 0;
	nb_words = 0;
	while (*(res + i))
	{
		while (ft_isspace(*(res + i)))
			i++;
		while (*(res + i) && ft_isalnum(*(res + i)))
			i++;
		nb_words++;
	}
	if (nb_words != 3)
		return (display_error("Resolution in .cub is invalid!"));
	i = 0;
	while (!ft_isspace(*(res + i)) || (*(res + i) == 'R'))
		i++;
	cub->x_axis = ft_atoi(res + i);
	while (ft_isspace(*(res + i)))
		i++;
	while (!ft_isspace(*(res + i)))
		i++;
	cub->y_axis = ft_atoi(res + i);
	printf("x = %d, y = %d\n", cub->x_axis, cub->y_axis);
}

void	parse_sprite(char *sprite, t_cub *cub)
{
	ft_putstr("Sprite!\n");
	(void)sprite;
	(void)cub;
}

void	parse_map(char **map, t_cub *cub)
{
	ft_putstr("Map!\n");
	(void)map;
	/*while (*map)
	{
		ft_putstr(*map++);
		ft_putchar('\n');
	}*/
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
			parse_resolution(map[i] + j, cub);
		else if (map[i][j] == 'S' && map[i][j + 1] != 'O')
			parse_sprite(map[i], cub);
		else if (!ft_strncmp(&map[i][j], "NO", 2) ||
			!ft_strncmp(&map[i][j], "SO", 2) ||
			!ft_strncmp(&map[i][j], "WE", 2) ||
			!ft_strncmp(&map[i][j], "EA ", 2))
			parse_textures(map[i], cub);
		else if (map[i][j] == 'F' || map[i][j] == 'C')
			parse_colors(map[i], cub);
		else if (map[i][j] == '1' || map[i][j] == '0')
			return (parse_map(map, cub));
		else if (map[i][j] != '\0')
			return (display_error("Unknow symbol in .cub!"));
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
