/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:41 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 17:20:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	ft_memset(&cub, 0, sizeof(t_cub));
	if (ac == 1)
		display_error(&cub, "There's no arguments!");
	if (ac == 2)
	{
		cub.save = 0;
		parsing(av[1], &cub);
	}
	if (ac == 3 && !ft_strcmp(av[2], "--save"))
	{
		cub.save = 1;
		parsing(av[1], &cub);
	}
	else
		save_error();
	if (ac > 3)
		display_error(&cub, "Too many arguments!");
	return (0);
}
