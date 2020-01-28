/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:38:23 by alelaval          #+#    #+#             */
/*   Updated: 2020/01/28 14:36:26 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H
# include "Libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

void	display_error(const char *error);
void	parsing(char* file);
void	save();
void	parse_resolution();
void	parse_sprite();

#endif