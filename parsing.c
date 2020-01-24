/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:57 by alelaval          #+#    #+#             */
/*   Updated: 2020/01/24 16:36:44 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_fd(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

void	parsing(char *file)
{
	int		fd;
	char	*line;

	line = NULL;
	if ((fd = get_fd(file)) < 0)
	{
		ft_putstr(".cub file is not found or cannot be accessed :(\n");
		return ;
	}
	while (get_next_line(fd, &line) != 0)
		ft_putstr(line);
}

void	save()
{
	;
}