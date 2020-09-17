/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/17 14:50:28 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RAYCAST_H

# define RAYCAST_H

void	mlx_clear_img(void *img_ptr, int height_res);
void	ray_init(t_cub *cub);
void	raycast_init(t_cub *cub);
void	perp_wall_dist(t_cub *cub);
void	dda(t_cub *cub);
void	draw_calc(t_cub *cub);
void	text_calc(t_cub	*cub);
void	draw_scanline(t_cub *cub, int x, t_vec limit, int color);
void	draw_textured_row(t_cub *cub, int x, int y);
void	draw(t_cub *cub, int x);
int 	raycast(t_cub *cub);

#endif