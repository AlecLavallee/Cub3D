/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:44:04 by alelaval          #+#    #+#             */
/*   Updated: 2020/10/09 16:39:15 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPRITES_H

# define SPRITES_H

void			draw_sprites(t_cub *cub, t_s *sprites);
void			combsort_sprites(t_s *sprites, int len);
int				count_sprites(t_cub *cub);
t_s				*get_sprites(t_cub *cub);
#endif