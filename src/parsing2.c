/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 17:52:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_flag(t_cub *cub, int flag, int set)
{
	if (cub->flags & flag)
		display_error(cub, "Duplicate descriptors in config file!");
	if (set == 1)
		cub->flags |= flag;
	return (0);
}

int	check_flags(t_cub *cub)
{
	int	flags;

	flags = cub->flags;
	if (flags != 255)
		return (1);
	return (0);
}

void	set_texture_flag(t_cub *cub, const char *type)
{
	if (ft_strncmp(type, "NO ", 3) == 0)
		check_flag(cub, NO, 1);
	if (ft_strncmp(type, "EA ", 3) == 0)
		check_flag(cub, EA, 1);
	if (ft_strncmp(type, "WE ", 3) == 0)
		check_flag(cub, WE, 1);
	if (ft_strncmp(type, "SO ", 3) == 0)
		check_flag(cub, SO, 1);
	if (type[0] == 'S' && type[1] == ' ')
		check_flag(cub, S, 1);
}

int	is_valid_map(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
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
	}
	return (0);
}

void	parsing(char *file, t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	init_cub(cub);
	read_file(cub, file);
	create_map(cub, &cub->file.lstmap);
	if (check_flags(cub))
		display_error(cub, "Descriptors are lacking before map declaration!");
	mlx_gestion(cub);
}
