/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:44:04 by alelaval          #+#    #+#             */
/*   Updated: 2020/10/28 17:37:15 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H

# define SPRITES_H

void			draw_textured_sprite(t_cub *cub, int stripe);
void			draw_sprites(t_cub *cub, t_s *sprites);
void			combsort_sprites(t_s *sprites, int len);
int				count_sprites(t_cub *cub);
t_s				*get_sprites(t_cub *cub);

#endif
