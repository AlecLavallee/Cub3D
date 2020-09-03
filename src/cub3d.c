/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:41 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/03 01:29:11 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int		main(int ac, char **av)
{
	t_cub	cub;

	ft_memset(&cub, 0, sizeof(t_cub));
	if (ac == 1)
		display_error("There's no arguments!");
	if (ac == 2)
	{
		parsing(av[1], &cub);
	}
	if (ac == 3)
		save();
	if (ac > 3)
		display_error("Too many arguments!");
	return (0);
}
