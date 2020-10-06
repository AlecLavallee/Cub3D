/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 12:44:04 by alelaval          #+#    #+#             */
/*   Updated: 2020/10/06 17:55:20 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPRITES_H

# define SPRITES_H

typedef struct	s_s
{
				t_vec_d	pos;
				double	dist;
}				t_s;

typedef struct	s_sprite
{
	double		spritescreenx;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spriteheight;
	int			spritewidth;
	int			drawstarty;
	int			drawendy;
	int			drawstartx;
	int			drawendx;
}				t_sprite;

void			draw_sprites(t_cub *cub);
void			combsort_sprites(t_s *sprites, int len);
int				count_sprites(t_cub *cub);
t_s				*get_sprites(t_cub *cub);
#endif