/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvmt2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:59:47 by alelaval          #+#    #+#             */
/*   Updated: 2021/04/02 11:44:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rot_right(t_cub *cub)
{
	cub->camera.olddirx = cub->camera.dirx;
	cub->camera.dirx = cub->camera.dirx * cos(cub->camera.rotspeed)
		- cub->camera.diry * sin(cub->camera.rotspeed);
	cub->camera.diry = cub->camera.olddirx * sin(cub->camera.rotspeed)
		+ cub->camera.diry * cos(cub->camera.rotspeed);
	cub->camera.oldplanex = cub->camera.planex;
	cub->camera.planex = cub->camera.planex * cos(cub->camera.rotspeed)
		- cub->camera.planey * sin(cub->camera.rotspeed);
	cub->camera.planey = cub->camera.oldplanex * sin(cub->camera.rotspeed)
		+ cub->camera.planey * cos(cub->camera.rotspeed);
}

void	rot_left(t_cub *cub)
{
	cub->camera.olddirx = cub->camera.dirx;
	cub->camera.dirx = cub->camera.dirx * cos(-cub->camera.rotspeed)
		- cub->camera.diry * sin(-cub->camera.rotspeed);
	cub->camera.diry = cub->camera.olddirx * sin(-cub->camera.rotspeed)
		+ cub->camera.diry * cos(-cub->camera.rotspeed);
	cub->camera.oldplanex = cub->camera.planex;
	cub->camera.planex = cub->camera.planex * cos(-cub->camera.rotspeed)
		- cub->camera.planey * sin(-cub->camera.rotspeed);
	cub->camera.planey = cub->camera.oldplanex * sin(-cub->camera.rotspeed)
		+ cub->camera.planey
		* cos(-cub->camera.rotspeed);
}
