/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/03 11:49:23 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "Libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

/* DANGER DANGER DANGER */
# include <stdio.h> //danger

typedef struct	s_cub
{
	char		**map;
	char		*sprite;
	int			x_axis;
	int			y_axis;
	int			floor[3];
	int			ceiling[3];
}				t_cub;

void	display_error(const char *error);
void	parsing(char* file, t_cub *cub);
void	save();
void	parse_resolution();
void	parse_sprite();

#endif