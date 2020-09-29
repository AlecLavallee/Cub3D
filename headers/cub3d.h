/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/09/29 01:52:37 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <libft.h>
# include "struct.h"
# include "mvmt.h"
# include "raycast.h"
# include "parsing.h"

# define FALSE 1
# define TRUE 0

t_cub	*init_cub(t_cub *cub);
void	mlx_gestion(t_cub *cub);
void	display_error(t_cub *cub, const char *error);
void	save();

#endif
