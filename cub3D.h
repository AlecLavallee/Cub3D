/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/10 11:59:21 by alelaval         ###   ########.fr       */
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
	int			x_axis;
	int			y_axis;
	int			floor[3];
	int			ceiling[3];
	void		*no_texture;
	void		*so_texture;
	void		*we_texture;
	void		*ea_texture;
	void		*sprite;
}				t_cub;

typedef struct	s_path
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*sprite_path;
}				t_path;

t_cub	init_cub(t_cub *cub);
char	*ft_strdup_wspaces(const char *s);
void	parse_map(char ***map, int index, t_cub *cub);
void	parse_colors_f(char *color, t_cub *cub);
void	parse_colors_c(char *color, t_cub *cub);
void	parse_textures(char *texture, t_cub *cub);
void	parse_cub(char **map, t_cub *cub);
void	display_error(const char *error);
void	parsing(char* file, t_cub *cub);
void	parse_resolution();
void	parse_sprite();
void	save();

#endif