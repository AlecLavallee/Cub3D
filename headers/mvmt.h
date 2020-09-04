/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvmt.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/04 17:29:37 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MVMT_H

# define MVMT_H

# define KEY_ESC 65307
# define KEY_UP 119
# define KEY_ROT_LEFT 97
# define KEY_DOWN 115
# define KEY_ROT_RIGHT 100

int		ft_key_hook(int keycode, t_cub *cub);
void	close_game(t_cub *cub);
# endif
