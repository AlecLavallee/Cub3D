/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvmt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 18:38:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	move_forward(t_cub *cub)
{
	if (cub->map.map
		[(int)(cub->camera.posx + cub->camera.dirx * cub->player.movespeed)]
		[(int)cub->camera.posy] == 0)
		cub->camera.posx += cub->camera.dirx * cub->player.movespeed;
	if (cub->map.map[(int)cub->camera.posx]
		[(int)(cub->camera.posy + cub->camera.diry
			* cub->player.movespeed)] == 0)
		cub->camera.posy += cub->camera.diry * cub->player.movespeed;
}

void	move_backward(t_cub *cub)
{
	if (cub->map.map
		[(int)(cub->camera.posx - cub->camera.dirx * cub->player.movespeed)]
		[(int)cub->camera.posy] == 0)
		cub->camera.posx -= cub->camera.dirx * cub->player.movespeed;
	if (cub->map.map[(int)cub->camera.posx]
		[(int)(cub->camera.posy - cub->camera.diry
			* cub->player.movespeed)] == 0)
		cub->camera.posy -= cub->camera.diry * cub->player.movespeed;
}

void	move_left(t_cub *cub)
{
	if (cub->map.map
		[(int)(cub->camera.posx - cub->camera.planex * cub->player.movespeed)]
		[(int)cub->camera.posy] == 0)
		cub->camera.posx -= cub->camera.planex * cub->player.movespeed;
	if (cub->map.map[(int)cub->camera.posx]
		[(int)(cub->camera.posy - cub->camera.planey \
		* cub->player.movespeed)] == 0)
		cub->camera.posy -= cub->camera.planey * cub->player.movespeed;
}

void	move_right(t_cub *cub)
{
	if (cub->map.map
		[(int)(cub->camera.posx + cub->camera.planex * cub->player.movespeed)]
		[(int)cub->camera.posy] == 0)
		cub->camera.posx += cub->camera.planex * cub->player.movespeed;
	if (cub->map.map[(int)cub->camera.posx]
		[(int)(cub->camera.posy + cub->camera.planey
			* cub->player.movespeed)] == 0)
		cub->camera.posy += cub->camera.planey * cub->player.movespeed;
}

void	player_move(t_cub *cub)
{
	if (cub->player.mvmtup)
		move_forward(cub);
	if (cub->player.mvmtdown)
		move_backward(cub);
	if (cub->player.mvmtleft)
		move_left(cub);
	if (cub->player.mvmtright)
		move_right(cub);
	if (cub->player.mvmtrotl)
		rot_left(cub);
	if (cub->player.mvmtrotr)
		rot_right(cub);
}
