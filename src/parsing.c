/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/10 13:10:05 by macbook          ###   ########.fr       */
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

void	parse_line_info(t_cub *cub, char *line)
{
	char type;

	type = *line;
	if (type == 'R')
		parse_resolution(cub, line);
	if (type == 'N' || type == 'S' || type == 'W' || type == 'E')
		parse_texture(cub, line);
	if (type == 'C' || type == 'F')
		parse_color(cub, line);
}

void	parse_line(t_cub *cub, char *line)
{
	if (*line == '\0')
		return ;
	if (!ft_isdigit(*line) && cub->file.mapping)
		display_error(cub, "Line after map declaration!");
	if (ft_isdigit(*line))
	{
		cub->file.mapping = 1;
		ft_lstadd_back(&(cub->file.lstmap), ft_lstnew(ft_strdup(line)));
	}
	else
		parse_line_info(cub, line);
}

void	read_file(t_cub *cub, char *path)
{
	char	*line;
	
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

