/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:01:35 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/03 15:52:44 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

/*void	floodfill(t_cub *cub, int v, int i, int j)
{
	if (ft_isalnum(cub->file.map[i][j]) && cub->file.map[i][j] != '1')
	{
		cub->file.map[i][j] = v;
		if (i < cub->camera.mapY - 1)
			floodfill(cub, v, i + 1, j);
		if (i > 1)
			floodfill(cub, v, i - 1, j);
		if (j > 1)
			floodfill(cub, v, i, j - 1);
		if (j < cub->camera.mapX - 1)
			floodfill(cub, v, i, j + 1);
	}
}

void	floodmap(t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cub->file.map[0][j])
		floodfill(cub, '#', i, j++);
	while (i < cub->camera.mapY - 1 && cub->file.map[i][0])
		floodfill(cub, '#', i++, 0);
	j = 0;
	while (j < cub->camera.mapX - 1 && cub->file.map[i][j])
		floodfill(cub, '#', i, j++);
	i = 0;
	while (i < cub->camera.mapY - 1 && cub->file.map[i][j])
		floodfill(cub, '#', i++, j);
	i = 0;
	ft_putchar('\n');
	while (cub->file.map[i])
		printf("%s\n", cub->file.map[i++]);
	ft_putchar('\n');
}*/
