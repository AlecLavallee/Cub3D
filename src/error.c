/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:19:46 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 17:30:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	display_error(t_cub *cub, const char *error)
{
	ft_putstr("Error\n");
	ft_putstr((char *)error);
	ft_putchar('\n');
	close_game(cub);
}

void	save_error(void)
{
	ft_putstr("Error\n");
	ft_putstr("Argument for save is invalid!");
	ft_putchar('\n');
	exit(0);
}
