/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:44:04 by alelaval          #+#    #+#             */
/*   Updated: 2020/10/07 17:33:38 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPRITES_H

# define SPRITES_H

void			draw_sprites(t_cub *cub, t_s *sprites, int x);
void			combsort_sprites(t_s *sprites, int len);
int				count_sprites(t_cub *cub);
t_s				*get_sprites(t_cub *cub);
#endif