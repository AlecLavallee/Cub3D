/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:37:52 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/10 19:31:39 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub	init_cub(t_cub *cub)
{
	cub->map = NULL;
	cub->x_axis = 0;
	cub->y_axis = 0;
	cub->map = NULL;
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
	char	*tmp;

	if (!s)
		return (NULL);
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(s))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (ft_isalnum(*s))
			tmp[i++] = *s;
		s++;
	}
	return (tmp);
}
