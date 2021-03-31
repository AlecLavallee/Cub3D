/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2021/03/31 15:28:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "struct.h"
# include "save.h"
# include "mvmt.h"
# include "raycast.h"
# include "parsing.h"
# include "sprites.h"

# define FALSE 1
# define TRUE 0

t_cub	*init_cub(t_cub *cub);
void	mlx_gestion(t_cub *cub);
void	display_error(t_cub *cub, const char *error);

#endif
