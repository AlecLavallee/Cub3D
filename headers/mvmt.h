/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvmt.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/16 12:40:37 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MVMT_H

# define MVMT_H

# define KEY_ESC 65307
# define KEY_UP 119
# define KEY_ROT_LEFT 97
# define KEY_DOWN 115
# define KEY_ROT_RIGHT 100

void    player_move(t_cub *cub);
int		ft_key_hook(int keycode, void *param);
int     ft_key_release(int keycode, void *param);
int 	close_game(t_cub *cub);
# endif
