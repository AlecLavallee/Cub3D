/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:51:32 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/10 15:37:56 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_map	*ft_lstnew(void *map)
{
	t_map	*newelem;

	if (!(newelem = (t_map*)malloc(sizeof(t_map) * 1)))
		return (NULL);
	newelem->map = map;
	newelem->next = NULL;
	newelem->prev = NULL;
	return (newelem);
}
