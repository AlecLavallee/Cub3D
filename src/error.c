/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:19:46 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/10 13:07:18 by macbook          ###   ########.fr       */
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
