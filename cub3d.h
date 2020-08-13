/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/08/13 11:10:08 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define texWidth 64
# define texHeight 64
# include "Libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

/* DANGER DANGER DANGER */
# include <stdio.h> //danger

typedef struct	s_mlx
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*img_data;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_mlx;

typedef struct	s_player
{
	double	time;
	double	oldTime;
	double frameTime;
}				t_player;

typedef struct	s_ray
{
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		sideDistX;
	int		sideDistY;
	double	dirX;
	double	dirY;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
}				t_ray;

typedef struct	s_desc
{
	int			fd;
	int			size;
	char		*name;
	char		**map;
}				t_desc;

typedef struct	s_path
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*sprite_path;
	int			no_fd;
	int			so_fd;
	int			we_fd;
	int			ea_fd;
	int			sprite_fd;
}				t_path;

typedef struct	s_cub
{
	char		**map;
	int			test_map;
	int			map_x;
	int			map_y;
	int			x_axis;
	int			y_axis;
	int			floor[3];
	int			ceiling[3];
	void		*no_texture;
	void		*so_texture;
	void		*we_texture;
	void		*ea_texture;
	void		*sprite;

	void	*mlx;
	void	*window;
	void	*image;
	char	*img_data;
	int		bpp;
	int		sizeline;
	int		endian;

	int		mapX;
	int		mapY;
	double	posX;
	double	posY;
	double	planeX;
	double	planeY;
	double	cameraX;

	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	sideDistX;
	double	sideDistY;
	double	dirX;
	double	dirY;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;

	double	time;
	double	oldTime;
	double 	frameTime;
	double	moveSpeed;
	double	rotSpeed;
	//struct s_mlx	mlx;
	struct s_player player;
	struct s_ray	ray;
	struct s_desc	file;
	struct s_path	path;
}					t_cub;

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