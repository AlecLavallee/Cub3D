/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:25:15 by alelaval          #+#    #+#             */
/*   Updated: 2021/02/01 22:45:47 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_H

#define SAVE_H

#include <stdint.h>

# define FILE_SIZE	14
# define INFO_SIZE	40

void	save_error(void);
void	save(t_cub *cub, const char *file);
void	write_metadata(t_cub *cub, int fd, t_bmp file);
void	write_data(t_cub *cub, int fd, t_bmp file);

#endif