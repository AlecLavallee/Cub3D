/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/22 00:01:13 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void		parse_resolution(t_cub *cub, char *line)
{
	int	width;
	int height;

	line += 2;
	height = ft_atoi(line);
	if (height > 2560)
		cub->mlx.screenHeight = 2560;
	else
		cub->mlx.screenHeight = height;
	while (ft_isdigit(*line))
		line++;
	width = ft_atoi(line);
	if (width > 1440)
		cub->mlx.screenWidth = 1440;
	else
		cub->mlx.screenWidth = width;
}

void		parse_texture(t_cub *cub, char *line)
{
	char type[2];

	type[0] = line[0];
	type[1] = line[1];
	while (ft_isalpha(*line))
		line++;
	line++;
	if (type[0] == 'N')
		cub->map.textures.no = load_tex(cub, line);
	if (type[0] == 'E')
		cub->map.textures.ea = load_tex(cub, line);
	if (type[0] == 'W')
		cub->map.textures.we = load_tex(cub, line);
	if (type[0] == 'S' && type[1] == 'O')
		cub->map.textures.so = load_tex(cub, line);
	if (type[0] == 'S' && type[1] == ' ')
		cub->map.textures.sprite = load_tex(cub, line);
}

int		parse_line_info(t_cub *cub, char *line)
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

int		is_valid_map(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			if (cub->file.orientation == 1)
				display_error(cub, "More than one orientation in map!");
			cub->file.orientation = 1;
			i++;
		}
		else if (line[i] == '0' || line[i] == '1' || line[i] == '2'
				|| line[i] == ' ')
			i++;
		else
			return (1);
	return (0);
}

void	parse_line(t_cub *cub, char *line)
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
		cub->file.index++;
	}
}

void	read_file(t_cub *cub, char *path)
{
	char	*line;

	cub->file.index = 0;
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
}
