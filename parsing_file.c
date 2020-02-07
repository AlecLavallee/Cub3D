/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/07 16:40:55 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_sprite(char *sprite, t_cub *cub)
{
	size_t	i;
	int		fd;

	i = 0;
	//ft_putstr("Sprite!\n");
	while (ft_isalpha(sprite[i]))
		i++;
	while (ft_isspace(sprite[i]))
		i++;
	if ((fd = open(&sprite[i], O_RDONLY)) == -1)
		return (display_error("Cannot open sprite file, check your paths!"));
	(void)cub;
}

void	parse_textures(char *texture, t_cub *cub)
{
	size_t	i;
	int		fd;

	i = 0;
	//ft_putstr("Textures!\n");
	while (ft_isalpha(texture[i]))
		i++;
	while (ft_isspace(texture[i]))
		i++;
	if ((fd = open(&texture[i], O_RDONLY)) == -1)
		return (display_error("Cannot open texture file, check your paths!"));
	(void)cub;
}

void	parse_map(char ***map, int index, t_cub *cub)
{
	int	i;

	i = 0;
	//ft_putstr("Map!\n");
	while (*(*map + index + i))
	{
		//ft_putstr("kochi wo miro!\n");
		ft_putstr(*(*map + index + i++));
		ft_putchar('\n');
	}
	index = -1;
	cub->map = (char**)malloc(sizeof(char*) * i + 1);
	while (cub->map[++index])
		cub->map[index] = ft_strdup_wspaces(*map[index]);
	(void)cub;
}
