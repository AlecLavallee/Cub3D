/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:37:41 by alelaval          #+#    #+#             */
/*   Updated: 2020/01/24 12:00:54 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	main(int ac, char** av)
{
	if (ac == 2)
		parsing(av);
	else if (ac == 3 && !parsing(av))
		save();
	else
		ft_putstr("Too many arguments!\n");
	return (0);
}
