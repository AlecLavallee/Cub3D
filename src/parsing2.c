/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/29 00:37:56 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_flag(t_cub *cub, int flag, int set)
{
	if (cub->flags & flag)
		display_error(cub, "Duplicate descriptors in config file!");
	if (set == 1)
		cub->flags |= flag;
	return (0);
}

void	check_flags(t_cub *cub)
{
	int	flags;

	flags = cub->flags;
	if (flags != 255)
		display_error(cub, "Descriptors are lacking before map declaration!");
}

void	set_texture_flag(t_cub *cub, const char *type)
{
	if (type[0] == 'N')
		check_flag(cub, NO, 1);
	if (type[0] == 'E')
		check_flag(cub, EA, 1);
	if (type[0] == 'W')
		check_flag(cub, WE, 1);
	if (type[0] == 'S' && type[1] == 'O')
		check_flag(cub, SO, 1);
	if (type[0] == 'S' && type[1] == ' ')
		check_flag(cub, S, 1);
}

int		is_valid_map(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
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
	return (0);
}

void	parsing(char *file, t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	init_cub(cub);
	read_file(cub, file);
	create_map(cub, &cub->file.lstmap);
	mlx_gestion(cub);
}
