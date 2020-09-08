/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/08 19:14:37 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(char *file, t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	init_cub(cub);
	read_file(cub, file);
	mlx_gestion(cub);
}