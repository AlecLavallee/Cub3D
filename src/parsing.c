/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2021/04/21 16:08:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void		parse_resolution(t_cub *cub, char *line)
{
	int	width;
	int height;

	check_flag(cub, R, 0);
	line++;
	width = ft_atoi(line);
	if (width <= 0)
		display_error(cub, "width is negative or zeroed!");
	cub->mlx.screenwidth = width;
	while (ft_isdigit(*line))
		line++;
	height = ft_atoi(line);
	if (height <= 0)
		display_error(cub, "height is negative or zeroed!");
	cub->mlx.screenheight = height;
	check_string_res(cub, line);
	check_flag(cub, R, 1);
}

void		parse_texture(t_cub *cub, char *line)
{
	char type[3];
	char *copy;

	copy = line;
	type[0] = line[0];
	type[1] = line[1];
	type[2] = line[2];
	if (ft_strncmp(copy, "NO", 2) == 0 || ft_strncmp(copy, "SO", 2) == 0 ||
	ft_strncmp(copy, "EA", 2) == 0 || ft_strncmp(copy, "WE", 2) == 0 ||
	(ft_strncmp(copy, "S .", 3) == 0 || ft_strncmp(copy, "S.", 2) == 0))
	{
		texture_loader(cub, (const char *)type, line);
	}
	else
		display_error(cub, "Invalid texture descriptor!");
	set_texture_flag(cub, (const char *)type);
}

int			parse_line_info(t_cub *cub, char *line)
{
	char type;

	type = *line;
	if (type == 'R')
	{
		parse_resolution(cub, line);
		check_screen_size(cub);
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
	if (type != '1' && type != '0' && type != ' ')
		display_error(cub, "invalid descriptor detected!");
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
	close(cub->file.fd);
	if (cub->file.mapping == 0)
		display_error(cub, "No valid map in config file!");
	if (cub->file.orientation == 0)
		display_error(cub, "No orientation for the player!");
}
