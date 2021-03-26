/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:19:46 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/17 14:49:48 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	display_error(t_cub *cub, const char *error)
{
	ft_putstr("Error\n");
	ft_putstr((char*)error);
	ft_putchar('\n');
	close_game(cub);
}

void	save_error()
{
	ft_putstr("Error\n");
	ft_putstr("Argument for save is invalid!");
	ft_putchar('\n');
	exit(0);
}
