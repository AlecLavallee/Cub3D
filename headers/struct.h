/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/03 02:05:00 by macbook          ###   ########.fr       */
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
	int			sno_fd;
	int			so_fd;
	int			we_fd;
	int			ea_fd;
	int			sprite_fd;
}				t_path;

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

typedef struct	s_cub
{
	char		**map;
	int			test_map;
	int			floor[3];
	int			ceiling[3];
	void	**texture;

	t_mlx	    mlx;
    t_image		image;
	t_desc		file;
	t_camera	camera;
	t_path		path;
}					t_cub;

# endif