/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/20 15:51:12 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		open_cub(char *file, t_cub *cub)
{
	int		fd;
	char	*dot;

	fd = -1;
	cub->file.name = file;
	dot = ft_strrchr(file, '.');
	if (!dot)
		return (display_error("file does not have an extension at all!"));
	if (dot && !ft_strcmp(dot, ".cub"))
	{
		if ((cub->file.fd = open(file, O_RDONLY)) < 0)
			return (display_error(".cub file not found/cannot be accessed!"));
	}
	else
		return (display_error("file does not have .cub extension!"));
}

int		verify_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->file.map[i])
	{
		j = 0;
		while (cub->file.map[i][j])
		{
			if (cub->file.map[i][j] == 'N' || cub->file.map[i][j] == 'S'
				|| cub->file.map[i][j] == 'E' || cub->file.map[i][j] == 'W'
				|| cub->file.map[i][j] == '0' || cub->file.map[i][j] == '1'
				|| cub->file.map[i][j] == '2')
			{
				j++;
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}

void	store_map(char *line, int nb_lines, t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	nb_lines = 0;
	cub->file.map = (char**)malloc(sizeof(char*) * cub->file.size - nb_lines);
	cub->file.map[i++] = ft_strdup_wspaces(line);
	while (get_next_line(cub->file.fd, &line))
		cub->file.map[i++] = ft_strdup_wspaces(line);
	while (ft_isspace(line[j++]))
		;
	if (line[j] == '\0')
		return (display_error("Empty line at end of map declaration!"));
	cub->file.map[i++] = ft_strdup_wspaces(line);
	cub->file.map[i] = NULL;
}

void	parsing_switch(char **line, int *map, t_cub *cub)
{
	int	j;

	j = 0;
	while (ft_isspace(*line[j]))
		j++;
	if (*line[j] == 'R')
		parse_resolution(*line + j, cub);
	else if (*line[j] == 'S' && *line[j + 1] != 'O')
		parse_sprite(*line, cub);
	else if (!ft_strncmp(&*line[j], "NO", 2) ||
		!ft_strncmp(&*line[j], "SO", 2) ||
		!ft_strncmp(&*line[j], "WE", 2) ||
		!ft_strncmp(&*line[j], "EA ", 2))
		parse_textures(*line, cub);
	else if (*line[j] == 'F')
		parse_colors_f(*line, cub);
	else if (*line[j] == 'C')
		parse_colors_c(*line, cub);
	else if (*line[j] == '0' || *line[j] == '1' || *line[j] == '2')
		*map = 1;
	else if (*line[j] != '\0')
		return (display_error("Unknow symbol in .cub!"));
}

void	parse_cub(t_cub *cub)
{
	char	*line;
	int		nb_lines;
	int		map;

	map = 0;
	line = NULL;
	nb_lines = -1;
	close(cub->file.fd);
	open_cub(cub->file.name, cub);
	while (get_next_line(cub->file.fd, &line))
	{
		parsing_switch(&line, &map, cub);
		nb_lines++;
		if (map == 1)
		{
			store_map(line, nb_lines, cub);
			break ;
		}
	}
	if (map == 0)
		return (display_error("No map detected in .cub!"));
}

char	*ft_fill(const char *s, int max)
{
	int		i;
	char	*tmp;

	if (!s)
		return (NULL);
	if (!(tmp = (char*)malloc(sizeof(char) * max)))
		return (NULL);
	i = 0;
	while (*s)
		tmp[i++] = *s++;
	while (i < max)
		tmp[i++] = '0';
	tmp[i] = '\0';
	return (tmp);
}

void	fill_out(t_cub *cub)
{
	int	i;
	int	size;

	i = 0;
	size = get_map_size(cub);
	cub->map_x = size;
	while (cub->file.map[i])
	{
		cub->file.map[i] = ft_fill(cub->file.map[i], size);
		printf("%s\n", cub->file.map[i]);
		i++;
	}
	cub->map_y = i;
}

int	color_map_1(void *mlx, void *win,int w,int h)
{
  int	x;
  int	y;
  int	color;

  x = w;
  while (x--)
    {
      y = h;
      while (y--)
        {
          color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
	  mlx_pixel_put(mlx,win,x,y,color);
        }
    }
	return (0);
}

void	parsing(char *file, t_cub *cub)
{
	char	buff[32];
	void	*mlx = NULL;
	void	*window = NULL;
	void	*image = NULL;
	char	*img_data = NULL;

	init_cub(cub);
	open_cub(file, cub);
	if (read(cub->file.fd, buff, 0) == 0)
	{
		get_size_desc(cub);
		open_cub(cub->file.name, cub);
		parse_cub(cub);
		fill_out(cub);
		if (verify_map(cub))
			return (display_error("Error in map declaration!"));
		floodmap(cub);
		ft_putstr("Launching!\n");
		mlx = mlx_init();
		window = mlx_new_window(mlx, cub->x_axis, cub->y_axis, "Cub3D");
		image = mlx_new_image(mlx, cub->x_axis, cub->y_axis);
		//color_map_1(mlx, window, 1920, 1080);
		mlx_put_image_to_window(mlx, window, image, 240, 240);
		mlx_loop(mlx);
		(void)img_data;
	}
}
