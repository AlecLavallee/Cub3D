/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2021/02/07 18:11:24 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

typedef struct		s_vec
{
	int				x;
	int				y;
}					t_vec;

typedef struct		s_vec_d
{
	double			x;
	double			y;
}					t_vec_d;

typedef struct		s_s
{
	t_vec_d			pos;
	double			dist;
}					t_s;

typedef struct		s_sprite
{
	int				spritescreenx;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				numsprites;
	int				spriteheight;
	int				spritewidth;
	int				drawstarty;
	int				drawendy;
	int				drawstartx;
	int				drawendx;
}					t_sprite;

typedef struct		s_mlx
{
	void			*mlx;
	void			*window;
	int				screenheight;
	int				screenwidth;
}					t_mlx;

typedef struct		s_image
{
	void			*img_ptr;
	int				*img_data;
	int				bpp;
	int				linesize;
	int				endian;
	int				linecount;
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

typedef struct		s_player
{
	int				mvmtup;
	int				mvmtdown;
	int				mvmtleft;
	int				mvmtright;
	int				mvmtrotl;
	int				mvmtrotr;
	double			time;
	double			oldtime;
	double			frametime;
	double			movespeed;
	double			rotspeed;
}					t_player;

typedef struct		s_camera
{
	int				mapx;
	int				mapy;
	int				drawend;
	int				lineheight;
	int				drawstart;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				texnum;
	int				texx;
	int				texy;
	double			posx;
	double			posy;
	double			oldplanex;
	double			planex;
	double			planey;
	double			camerax;
	double			rotspeed;
	double			sidedistx;
	double			sidedisty;
	double			olddirx;
	double			dirx;
	double			diry;
	double			raydirx;
	double			raydiry;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			step;
	double			wallx;
	double			texpos;
	double			*zbuffer;
}					t_camera;

typedef struct		s_map_cub
{
	int				**map;
	t_vec			resolution;
	t_textures		textures;
	unsigned char	colorfloor[4];
	unsigned char	colorceiling[4];
	int				xsize;
	int				ysize;
	char			*line;
}					t_map_cub;

typedef struct		s_file
{
	int				fd;
	int				mapping;
	int				orientation;
	t_map			*lstmap;
}					t_file;

typedef struct	s_bmp_file_header {
	uint	file_type;
	uint	file_size;
	uint	reserved1;
	uint	reserved2;
	uint	offset;
}				t_bmp_file_header;

typedef struct	s_bmp_info_header {
	uint	header_size;
	int		img_width;
	int		img_height;
	uint	planes;
	uint	bit_per_pix;
	uint	compression;
	uint	img_size;
	int		x_pixels_per_meter;
	int		y_pixels_per_meter;
	uint	colors_used;
	uint	colors_important;
}				t_bmp_info_header;

typedef struct	s_bmp {
	t_bmp_file_header	file_header;
	t_bmp_info_header	info_header;
	uint				*data;
}				t_bmp;

typedef struct		s_cub
{
	int				flags;
	t_file			file;
	t_bmp			bmp;
	t_mlx			mlx;
	t_image			image;
	t_map_cub		map;
	t_camera		camera;
	t_player		player;
	t_sprite		sprite;
}					t_cub;

#endif
