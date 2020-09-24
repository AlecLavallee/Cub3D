/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 01:12:46 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/24 06:07:09 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PARSING_H

# define PARSING_H

# define NO 1
# define SO 1 << 1
# define EA 1 << 2
# define WE 1 << 3
# define S 1 << 4
# define CF 1 << 5
# define CC 1 << 6
# define R 1 << 7
# define IMG 1 << 8

t_texture	load_tex(t_cub *cub, char *path);
void		read_file(t_cub *cub, char *file);
void		parsing(char* file, t_cub *cub);
void		parse_map(char ***map, int index, t_cub *cub);
void		parse_textures(t_cub *cub, const char *texture, int index);
void		parse_resolution(t_cub *cub, char *line);
void		parse_color(t_cub *cub, char *line);
void		parse_cub(t_cub *cub);
void		create_map(t_cub *cub, t_map **map);
int			check_flag(t_cub *cub, int flag, int set);
int			get_index_map(t_map *ref);
int			get_max_len(t_map *ref);
int			*store_line_map(t_cub *cub, t_map *ref, int index);
int			**allocate_map(t_cub *cub, int index, int max);

#endif