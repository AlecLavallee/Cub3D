/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/17 14:50:01 by alelaval         ###   ########.fr       */
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

void	mlx_gestion(t_cub *cub)
{
	cub->mlx.window = \
	mlx_new_window(cub->mlx.mlx, cub->mlx.screenWidth, cub->mlx.screenHeight, \
	"Cub3D");
	cub->image.img_ptr = \
	mlx_new_image(cub->mlx.mlx, cub->mlx.screenWidth, cub->mlx.screenHeight);
	mlx_hook(cub->mlx.window, 2, 1L << 0, ft_key_hook, cub);
	mlx_hook(cub->mlx.window, 3, 1L << 1, ft_key_release, cub);
	mlx_hook(cub->mlx.window, 17, 1L << 5, close_game, cub);
	mlx_loop_hook(cub->mlx.mlx, raycast, cub);
	mlx_loop(cub->mlx.mlx);
}
