/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 01:12:46 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/29 02:31:47 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H

enum	e_flags
{
	NO = 1,
	SO = 1 << 1,
	EA = 1 << 2,
	WE = 1 << 3,
	S = 1 << 4,
	CF = 1 << 5,
	CC = 1 << 6,
	R = 1 << 7,
	IMG = 1 << 8
};

t_texture	load_tex(t_cub *cub, char *path);
void		read_file(t_cub *cub, char *file);
void		parsing(char *file, t_cub *cub);
void		parse_map(char ***map, int index, t_cub *cub);
void		parse_textures(t_cub *cub, const char *texture, int index);
void		parse_resolution(t_cub *cub, char *line);
void		parse_color(t_cub *cub, char *line);
void		parse_cub(t_cub *cub);
void		check_map(t_cub *cub);
void		check_sprite(t_cub *cub, int i, int j);
void		check_tile(t_cub *cub, int i, int j);
void		create_map(t_cub *cub, t_map **map);
int			check_flag(t_cub *cub, int flag, int set);
void		check_flags(t_cub *cub);
void		set_texture_flag(t_cub *cub, const char *type);
int			get_index_map(t_map *ref);
int			get_max_len(t_map *ref);
int			is_valid_map(t_cub *cub, char *line);
int			*store_line_map(t_cub *cub, t_map *ref, int index);
int			**allocate_map(t_cub *cub, int index, int max);

#endif
