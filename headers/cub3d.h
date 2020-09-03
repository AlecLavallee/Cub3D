/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/03 17:09:38 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define texWidth 64
# define texHeight 64
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "struct.h"
# include "mvmt.h"

/* DANGER DANGER DANGER */
# include <stdio.h> //danger

# define FALSE 1
# define TRUE 0

t_cub	*init_cub(t_cub *cub);
char	*ft_strdup_wspaces(const char *s);
int		get_map_size(t_cub *cub);
void	raycast(t_cub *cub);
void	mlx_gestion(t_cub *cub);
void	floodmap(t_cub *cub);
void	floodfill(t_cub *cub, int v, int i, int j);
void	parse_map(char ***map, int index, t_cub *cub);
void	parse_colors_f(char *color, t_cub *cub);
void	parse_colors_c(char *color, t_cub *cub);
void	parse_textures(char *texture, t_cub *cub);
void	parse_resolution(char *res, t_cub *cub);
void	parse_cub(t_cub *cub);
void	get_size_desc(t_cub *cub);
void	display_error(const char *error);
void	parsing(char* file, t_cub *cub);
void	parse_resolution();
void	parse_sprite();
void	save();

#endif