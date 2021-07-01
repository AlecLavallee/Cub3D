/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:51:32 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 19:31:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_map	*ft_lstnew(void *map)
{
	t_map	*newelem;

	newelem = (t_map *)malloc(sizeof(t_map) * 1);
	if (newelem == NULL)
		return (NULL);
	newelem->map = map;
	newelem->next = NULL;
	newelem->prev = NULL;
	return (newelem);
}
