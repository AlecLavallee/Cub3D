/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/08 14:39:52 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STRUCT_H

# define STRUCT_H

typedef struct	s_vec
{
	int	x;
	int y;
}				t_vec;

typedef struct	s_mlx
{
	void	*mlx;
	void	*window;
	int		screenHeight;
	int		screenWidth;
}				t_mlx;

typedef struct		s_image
{
	void			*img_ptr;
	int				*img_data;
	int				bpp;
	int				lineSize;
	int				endian;
	int				lineCount;
}					t_image;

typedef struct		s_texture
{
	t_image			image;
	char			path[255 + 1];
	int				width;
	int				height;
}					t_texture;

typedef struct		s_textures
{
	t_texture		no;
	t_texture		so;
	t_texture		we;
	t_texture		ea;
	t_texture		sprite;
}					t_textures;

typedef struct	s_player
{
	double	time;
	double	oldTime;
	double 	frameTime;
	double	moveSpeed;
	double	rotSpeed;
}				t_player;

typedef struct	s_camera
{
	int		mapX;
	int		mapY;
	int		drawEnd;
	int		lineHeight;
	int		drawStart;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		texNum;
	int		texX;
	int		texY;
	double	posX;
	double	posY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rotSpeed;
	double	sideDistX;
	double	sideDistY;
	double	dirX;
	double	dirY;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	double	step;
	double	wallX;
	double	texPos;
}				t_camera;

typedef struct		s_map_cub
{
	int				**map;
	t_vec			resolution;
	t_textures		textures;
	unsigned char	colorFloor[4];
	unsigned char	colorCeiling[4];
	int				xsize;
	int				ysize;
	char			*line;
	unsigned int	specs;
	unsigned int	square_size;
}					t_map_cub;

typedef struct	s_file
{
	int		fd;
	int		size;
	int		mapping;
	char	*name;
	char	*path;
	t_map	*lstmap;
}				t_file;

typedef struct	s_cub
{
	t_file		file;
	t_mlx		mlx;
	t_image		image;
	t_map_cub	map;
	t_camera	camera;
}					t_cub;

t_texture	load_tex(t_cub *cub, char *path);
void	parse_color(t_cub *cub, char *line);

# endif