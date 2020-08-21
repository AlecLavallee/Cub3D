/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:43:19 by alelaval          #+#    #+#             */
/*   Updated: 2019/11/22 11:42:12 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_secure(char **stock, char **line, int i)
{
	if (i == 1)
	{
		if (!stock || !line)
		{
			if (*stock)
			{
				free(*stock);
				*stock = NULL;
			}
			if (*line)
			{
				free(*line);
				*line = NULL;
			}
		}
		return (1);
	}
	if (*stock && i == 2)
	{
		free(*stock);
		*stock = NULL;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				i;
	static char		*stock = NULL;
	char			tmp[BUFFER_SIZE + 1];

	if (!stock)
	{
		if ((read(fd, tmp, 0) == -1) || !line ||
			!(stock = malloc(sizeof(char))))
			return (-1);
		stock[0] = '\0';
	}
	while ((ft_strclen(stock, '\n') == -1) &&
		(i = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[i] = '\0';
		stock = ft_strcat(stock, tmp);
	}
	if (ft_strclen(stock, '\n') != -1)
	{
		*line = ft_strncpy(*line, stock, ft_strclen(stock, '\n'));
		stock = ft_strtrim_left(stock, ft_strclen(stock, '\n') + 1);
		return (ft_secure(&stock, line, 1));
	}
	*line = ft_strncpy(*line, stock, ft_strclen(stock, '\0'));
	return (ft_secure(&stock, line, 2));
}
