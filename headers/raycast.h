/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/19 14:15:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H

# define RAYCAST_H

void			get_tex_num(t_cub *cub);
void			check_screen_size(t_cub *cub);
void			mlx_clear_img(void *img_ptr, int height_res);
void			ray_init(t_cub *cub);
void			raycast_init(t_cub *cub);
void			perp_wall_dist(t_cub *cub);
void			dda(t_cub *cub);
void			draw_calc(t_cub *cub);
void			text_calc(t_cub	*cub);
void			draw_scanline(t_cub *cub, int x, t_vec limit, int color);
void			draw_textured_row(t_cub *cub, int x, int y);
void			draw(t_cub *cub, int x);
unsigned int	get_color_rgb(unsigned char *color);
t_texture		*get_tex_ptr(t_cub *cub, int index);
void			raycast_core(t_cub *cub, int *i);
int				raycast(t_cub *cub);

#endif
