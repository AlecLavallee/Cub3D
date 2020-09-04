/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:37:52 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/04 17:03:50 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

t_cub	*init_cub(t_cub *cub)
{
	cub->mlx.screenWidth = -1;
	cub->mlx.screenHeight = -1;
	cub->map.colorCeiling = -1;
	cub->map.colorFloor = -1;
	cub->camera.posX = 8;
	cub->camera.posY = 5;
	cub->camera.dirX = -1;
	cub->camera.dirY = 0;
	cub->camera.planeX = 0.0;
	cub->camera.planeY = 0.66;
	cub->camera.hit = 0;
	cub->camera.rotSpeed = 1.0;
	return (cub);
}

char	*ft_strdup_wspaces(const char *s)
{
	int		i;
	char	*copy;
	char	*tmp;

	if (!s)
		return (NULL);
	copy = ft_strdup(s);
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(copy))))
		return (NULL);
	i = 0;
	while (*copy)
	{
		if (!ft_isspace(*copy))
			tmp[i++] = *copy;
		copy++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int		get_map_size(t_cub *cub)
{
	int	i;
	int	j;
	int	max_size;

	i = 0;
	j = 0;
	max_size = 0;
	while (cub->file.map[i])
	{
		j = 0;
		while (cub->file.map[i][j])
			j++;
		if (j > max_size)
			max_size = j;
		i++;
	}
	return (max_size);
}

void	get_size_desc(t_cub *cub)
{
	char *line;

	line = NULL;
	cub->file.size = 0;
	while (get_next_line(cub->file.fd, &line))
		cub->file.size++;
	close(cub->file.fd);
	cub->file.size++;
	free(line);
}
