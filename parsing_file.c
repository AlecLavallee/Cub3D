/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:17 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/10 19:39:49 by alelaval         ###   ########.fr       */
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
	int		i;
	t_map	*lstmap;

	i = 0;
	lstmap = NULL;
	ft_putstr("Map!\n");
	if (!(lstmap = ft_lstnew("Oi joske")))
		return (display_error("Chained list attribution failed!"));
	ft_putstr(lstmap->map);
	ft_putchar('\n');
	lstmap->map = ft_strdup_wspaces(*(*map + index + i++));
	while (*(*map + index + i))
		ft_lstadd_back(&lstmap, ft_lstnew(ft_strdup_wspaces(*(*map + index + i++))));
	while (lstmap)
	{
		ft_putstr("kochi wo miro!\n");
		ft_putstr(lstmap->map);
		ft_putchar('\n');
		lstmap = lstmap->next;
	}
	(void)cub;
}
