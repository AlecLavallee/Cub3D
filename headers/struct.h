/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/24 02:20:48 by alelaval         ###   ########.fr       */
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
	int		mvmtUP;
	int		mvmtDOWN;
	int		mvmtLEFT;
	int		mvmtRIGHT;
	int		mvmtROTL;
	int		mvmtROTR;
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
	double	oldPlaneX;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rotSpeed;
	double	sideDistX;
	double	sideDistY;
	double	oldDirX;
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
}					t_map_cub;

typedef struct	s_file
{
	int		fd;
	int		mapping;
	int		orientation;
	t_map	*lstmap;
}				t_file;

typedef struct	s_cub
{
	int			flags;
	t_file		file;
	t_mlx		mlx;
	t_image		image;
	t_map_cub	map;
	t_camera	camera;
	t_player	player;
}					t_cub;

# endif