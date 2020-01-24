/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:51:32 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/16 09:56:51 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newelem;

	if (!(newelem = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	newelem->content = content;
	newelem->next = NULL;
	return (newelem);
}
