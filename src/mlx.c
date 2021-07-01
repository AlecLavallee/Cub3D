/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 17:31:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

void	mlx_clear_img(void *img_ptr, int height_res)
{
	char	*img_ret;
	int		bit_per_pix;
	int		size_line;
	int		endian;

	img_ret = mlx_get_data_addr(img_ptr, &bit_per_pix, &size_line, &endian);
	ft_bzero(img_ret, size_line * height_res);
}

int	ft_key_release(int keycode, void *param)
{
	t_cub	*cub;

	cub = param;
	if (keycode == 119)
		cub->player.mvmtup = 0;
	if (keycode == 115)
		cub->player.mvmtdown = 0;
	if (keycode == 97)
		cub->player.mvmtleft = 0;
	if (keycode == 100)
		cub->player.mvmtright = 0;
	if (keycode == 65363)
		cub->player.mvmtrotl = 0;
	if (keycode == 65361)
		cub->player.mvmtrotr = 0;
	return (0);
}

int	ft_key_hook(int keycode, void *param)
{
	t_cub	*cub;

	cub = param;
	if (keycode == 119)
		cub->player.mvmtup = 1;
	if (keycode == 115)
		cub->player.mvmtdown = 1;
	if (keycode == 97)
		cub->player.mvmtleft = 1;
	if (keycode == 100)
		cub->player.mvmtright = 1;
	if (keycode == 65363)
		cub->player.mvmtrotl = 1;
	if (keycode == 65361)
		cub->player.mvmtrotr = 1;
	if (keycode == 65307)
		close_game(cub);
	return (1);
}

void	mlx_gestion(t_cub *cub)
{
	cub->mlx.window = \
	mlx_new_window(cub->mlx.mlx, cub->mlx.screenwidth, cub->mlx.screenheight, \
	"Cub3D");
	cub->image.img_ptr = \
	mlx_new_image(cub->mlx.mlx, cub->mlx.screenwidth, cub->mlx.screenheight);
	cub->flags |= IMG;
	mlx_hook(cub->mlx.window, 2, 1L << 0, ft_key_hook, cub);
	mlx_hook(cub->mlx.window, 3, 1L << 1, ft_key_release, cub);
	mlx_hook(cub->mlx.window, 33, 1L << 5, close_game, cub);
	mlx_loop_hook(cub->mlx.mlx, raycast, cub);
	mlx_loop(cub->mlx.mlx);
}
