/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvmt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/16 14:25:17 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	move_forward(t_cub *cub)
{
	int worldMap[24][24]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	if (worldMap[(int)(cub->camera.posX + cub->camera.dirX * cub->player.moveSpeed)][(int)cub->camera.posY] == 0)
		cub->camera.posX += cub->camera.dirX * cub->player.moveSpeed;
	if (worldMap[(int)cub->camera.posX][(int)(cub->camera.posY + cub->camera.dirY * cub->player.moveSpeed)] == 0)
		cub->camera.posY += cub->camera.dirY * cub->player.moveSpeed;
}

void	move_backward(t_cub *cub)
{
	int worldMap[24][24]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	if (worldMap[(int)(cub->camera.posX - cub->camera.dirX * cub->player.moveSpeed)][(int)cub->camera.posY] == 0)
		cub->camera.posX -= cub->camera.dirX * cub->player.moveSpeed;
	if (worldMap[(int)cub->camera.posX][(int)(cub->camera.posY - cub->camera.dirY * cub->player.moveSpeed)] == 0)
		cub->camera.posY -= cub->camera.dirY * cub->player.moveSpeed;
}

void	move_left(t_cub *cub)
{
	int worldMap[24][24]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	if (worldMap[(int)(cub->camera.posY - cub->camera.planeY * cub->player.moveSpeed)][(int)(cub->camera.posX)] == 0)
		cub->camera.posY -= cub->camera.planeY * cub->player.moveSpeed;
	if (worldMap[(int)(cub->camera.posY)][(int)(cub->camera.posX - cub->camera.planeX * cub->player.moveSpeed)] == 0)
		cub->camera.posX -= cub->camera.planeX * cub->player.moveSpeed;
}

void	move_right(t_cub *cub)
{
	int worldMap[24][24]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	if (worldMap[(int)(cub->camera.posY + cub->camera.planeY * cub->player.moveSpeed)][(int)(cub->camera.posX)] == 0)
		cub->camera.posY += cub->camera.planeY * cub->player.moveSpeed;
	if (worldMap[(int)(cub->camera.posY)][(int)(cub->camera.posX + cub->camera.planeX * cub->player.moveSpeed)] == 0)
		cub->camera.posX += cub->camera.planeX * cub->player.moveSpeed;
}

void	rot_left(t_cub *cub)
{
	cub->camera.oldDirX = cub->camera.dirX;
	cub->camera.dirX = cub->camera.dirX * cos(cub->camera.rotSpeed) - cub->camera.dirY * sin(cub->camera.rotSpeed);
	cub->camera.dirY = cub->camera.oldDirX * sin(cub->camera.rotSpeed) + cub->camera.dirY * cos(cub->camera.rotSpeed);
	cub->camera.oldPlaneX = cub->camera.planeX;
	cub->camera.planeX = cub->camera.planeX * cos(cub->camera.rotSpeed) - cub->camera.planeY * sin(cub->camera.rotSpeed);
	cub->camera.planeY = cub->camera.oldPlaneX * sin(cub->camera.rotSpeed) + cub->camera.planeY * cos(cub->camera.rotSpeed);
}

void	rot_right(t_cub *cub)
{
	cub->camera.oldDirX = cub->camera.dirX;
	cub->camera.dirX = cub->camera.dirX * cos(-cub->camera.rotSpeed) - cub->camera.dirY * sin(-cub->camera.rotSpeed);
	cub->camera.dirY = cub->camera.oldDirX * sin(-cub->camera.rotSpeed) + cub->camera.dirY * cos(-cub->camera.rotSpeed);
	cub->camera.oldPlaneX = cub->camera.planeX;
	cub->camera.planeX = cub->camera.planeX * cos(-cub->camera.rotSpeed) - cub->camera.planeY * sin(-cub->camera.rotSpeed);
	cub->camera.planeY = cub->camera.oldPlaneX * sin(-cub->camera.rotSpeed) + cub->camera.planeY * cos(-cub->camera.rotSpeed);
}

int		ft_key_release(int keycode, void *param)
{
	t_cub	*cub;
	cub = param;
	if (keycode == 13)
		cub->player.mvmtUP = 0;
	if (keycode == 1)
		cub->player.mvmtDOWN = 0;
	if (keycode == 0)
		cub->player.mvmtLEFT = 0;
	if (keycode == 2)
		cub->player.mvmtRIGHT = 0;
	if (keycode == 123)
		cub->player.mvmtROTL = 0;
	if (keycode == 124)
		cub->player.mvmtROTR = 0;
	return (0);
}

int		ft_key_hook(int keycode, void *param)
{
	t_cub	*cub;
	cub = param;
	if (keycode == 13)
		cub->player.mvmtUP = 1;
	if (keycode == 1)
		cub->player.mvmtDOWN = 1;
	if (keycode == 0)
		cub->player.mvmtLEFT = 1;
	if (keycode == 2)
		cub->player.mvmtRIGHT = 1;
	if (keycode == 123)
		cub->player.mvmtROTL = 1;
	if (keycode == 124)
		cub->player.mvmtROTR = 1;
	if (keycode == 53)
		close_game(cub);
	return (1);
}

void	player_move(t_cub *cub)
{
	if (cub->player.mvmtUP)
		move_forward(cub);
	if (cub->player.mvmtDOWN)
		move_backward(cub);
	if (cub->player.mvmtLEFT)
		move_left(cub);
	if (cub->player.mvmtRIGHT)
		move_right(cub);
	if (cub->player.mvmtROTL)
		rot_left(cub);
	if (cub->player.mvmtROTR)
		rot_right(cub);
}