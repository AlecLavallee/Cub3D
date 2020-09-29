/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/29 06:14:13 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void		parse_resolution(t_cub *cub, char *line)
{
	int	width;
	int height;

	check_flag(cub, R, 0);
	line += 2;
	height = ft_atoi(line);
	if (height > 2560)
		cub->mlx.screenheight = 2560;
	else
		cub->mlx.screenheight = height;
	while (ft_isdigit(*line))
		line++;
	width = ft_atoi(line);
	if (width > 1440)
		cub->mlx.screenwidth = 1440;
	else
		cub->mlx.screenwidth = width;
	check_flag(cub, R, 1);
}

void		parse_texture(t_cub *cub, char *line)
{
	char type[2];

	type[0] = line[0];
	type[1] = line[1];
	while (ft_isalpha(*line))
		line++;
	line++;
	if (type[0] == 'N' && !check_flag(cub, NO, 0))
		cub->map.textures.no = load_tex(cub, line);
	if (type[0] == 'E' && !check_flag(cub, EA, 0))
		cub->map.textures.ea = load_tex(cub, line);
	if (type[0] == 'W' && !check_flag(cub, WE, 0))
		cub->map.textures.we = load_tex(cub, line);
	if (type[0] == 'S' && type[1] == 'O' && !check_flag(cub, SO, 0))
		cub->map.textures.so = load_tex(cub, line);
	if (type[0] == 'S' && type[1] == ' ' && !check_flag(cub, S, 0))
		cub->map.textures.sprite = load_tex(cub, line);
	set_texture_flag(cub, (const char *)type);
}

int			parse_line_info(t_cub *cub, char *line)
{
	char type;

	type = *line;
	if (type == 'R')
	{
		parse_resolution(cub, line);
		return (0);
	}
	if (type == 'N' || type == 'S' || type == 'W' || type == 'E')
	{
		parse_texture(cub, line);
		return (0);
	}
	if (type == 'C' || type == 'F')
	{
		parse_color(cub, line);
		return (0);
	}
	if (type == '\0')
		return (0);
	return (1);
}

void		parse_line(t_cub *cub, char *line)
{
	if ((parse_line_info(cub, line)) == 0 || *line == '\0')
	{
		if (cub->file.mapping == 1)
			display_error(cub, "Wrong info after map start!");
	}
	else
	{
		check_flags(cub);
		cub->file.mapping = 1;
		if (is_valid_map(cub, line))
			display_error(cub, "Map has invalid characters!");
		ft_lstadd_back(&(cub->file.lstmap), ft_lstnew(ft_strdup(line)));
		cub->map.ysize++;
	}
}

void		read_file(t_cub *cub, char *path)
{
	char	*line;

	cub->map.ysize = 0;
	cub->file.mapping = 0;
	cub->file.orientation = 0;
	cub->file.fd = open(path, O_RDONLY);
	if (cub->file.fd < 0)
		display_error(cub, "Wrong path or cannot open file!");
	while ((get_next_line(cub->file.fd, &line)) > 0)
	{
		parse_line(cub, line);
		free(line);
	}
	parse_line(cub, line);
	free(line);
	if (cub->file.mapping == 0)
		display_error(cub, "No valid map in config file!");
	if (cub->file.orientation == 0)
		display_error(cub, "No orientation for the player!");
}
