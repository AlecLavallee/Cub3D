/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:22:39 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/04 18:22:49 by alelaval         ###   ########.fr       */
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
	cub->mlx.mlx = mlx_init();
	cub->mlx.window = \
	mlx_new_window(cub->mlx.mlx, cub->mlx.screenWidth, cub->mlx.screenWidth, \
	"Cub3D");
	cub->image.img_ptr = \
	mlx_new_image(cub->mlx.mlx, cub->mlx.screenWidth, cub->mlx.screenHeight);
	mlx_clear_img(cub->image.img_ptr, cub->mlx.screenWidth);
	raycast(cub);
	mlx_key_hook(cub->mlx.window, ft_key_hook, cub);
	mlx_loop(cub->mlx.mlx);
}
