/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/16 15:18:57 by alelaval         ###   ########.fr       */
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
# include <libft.h>
# include "struct.h"
# include "mvmt.h"
# include "raycast.h"

/* DANGER DANGER DANGER */
# include <stdio.h> //danger

# define FALSE 1
# define TRUE 0

t_cub	*init_cub(t_cub *cub);
char	*ft_strdup_wspaces(const char *s);
int		get_map_size(t_cub *cub);
void	mlx_gestion(t_cub *cub);
void	floodmap(t_cub *cub);
void	floodfill(t_cub *cub, int v, int i, int j);
void	parse_map(char ***map, int index, t_cub *cub);
void	parse_textures(t_cub *cub, const char *texture, int index);
void	parse_resolution(t_cub *cub, char *line);
void	parse_cub(t_cub *cub);
void	get_size_desc(t_cub *cub);
void	display_error(t_cub *cub, const char *error);
void	read_file(t_cub *cub, char *file);
void	parsing(char* file, t_cub *cub);
void	save();

char	*skip(char *line);
#endif