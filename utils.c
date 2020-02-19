/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:37:52 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/17 13:51:01 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub	init_cub(t_cub *cub)
{
	cub->map = NULL;
	cub->x_axis = -1;
	cub->y_axis = -1;
	cub->ceiling[0] = -1;
	cub->ceiling[1] = -1;
	cub->ceiling[2] = -1;
	cub->floor[0] = -1;
	cub->floor[1] = -1;
	cub->floor[2] = -1;
	return (*cub);
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
	while (get_next_line(cub->file.fd, &line))
		cub->file.size++;
	close(cub->file.fd);
	cub->file.size++;
	free(line);
}
