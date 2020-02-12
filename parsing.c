/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/12 17:21:14 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
}

int		open_cub(char *file, t_cub *cub)
{
	int		fd;
	char	*dot;

	fd = -1;
	cub->file.name = file;
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

void	store_map(char **line, int nb_lines, t_cub *cub)
{
	nb_lines = 0;
	while (get_next_line(cub->file.fd, line))
	{
		while (ft_isspace(**line++))
			;
		if (**line == '0' && **line == '1')
			nb_lines++;
		else
			return (display_error("Invalid Map!"));
	}
	printf("%d\n", nb_lines);
}

void	parsing_switch(char **line, int *map, t_cub *cub)
{
	int	j;

	j = 0;
	while (ft_isspace(*line[j]))
		j++;
	if (*line[j] == 'R')
		parse_resolution(*line + j, cub);
	else if (*line[j] == 'S' && *line[j + 1] != 'O')
		parse_sprite(*line, cub);
	else if (!ft_strncmp(&*line[j], "NO", 2) ||
		!ft_strncmp(&*line[j], "SO", 2) ||
		!ft_strncmp(&*line[j], "WE", 2) ||
		!ft_strncmp(&*line[j], "EA ", 2))
		parse_textures(*line, cub);
	else if (*line[j] == 'F')
		parse_colors_f(*line, cub);
	else if (*line[j] == 'C')
		parse_colors_c(*line, cub);
	else if (*line[j] == '1' || *line[j] == '0' || *line[j] == '2')
		*map = 1;
	else if (*line[j] != '\0')
		return (display_error("Unknow symbol in .cub!"));
}

void	parse_cub(t_cub *cub)
{
	char	*line;
	int		nb_lines;
	int		map;

	map = 0;
	nb_lines = -1;
	while (get_next_line(cub->file.fd, &line))
	{
		if (!map)
		{
			parsing_switch(&line, &map, cub);
			nb_lines++;
		}
		else
		{
			store_map(&line, --nb_lines, cub);
			break ;
		}
	}
	if (!map)
		return (display_error("No map detected in .cub!"));
}

void	get_size_desc(t_cub *cub)
{
	char **line;

	line = NULL;
	while (get_next_line(cub->file.fd, line))
		cub->file.size++;
	cub->file.size++;
	free(line);
}

void	parsing(char *file, t_cub *cub)
{
	char	**file_cub;

	file_cub = NULL;
	init_cub(cub);
	cub->file.fd = open_cub(file, cub);
	if (cub->file.fd != -1)
	{
		get_size_desc(cub);
		parse_cub(cub);
	}
}
