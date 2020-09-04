/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/04 15:02:02 by macbook          ###   ########.fr       */
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
	char			*map[20000];
	t_vec			resolution;
	t_texture		textures[5];
	unsigned int	colorFloor;
	unsigned int	colorCeiling;
	int				xsize;
	int				ysize;
	char			*line;
	unsigned int	specs;
	unsigned int	square_size;
}					t_map_cub;

typedef struct	s_cub
{
	t_mlx		mlx;
	t_image		image;
	t_map_cub	map;
	t_camera	camera;
}					t_cub;

void	load_tex(t_cub *cub, const char *path, int index);
# endif