/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:06:13 by alelaval          #+#    #+#             */
/*   Updated: 2021/07/01 19:09:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_map **lst, void (*del)(void*))
{
	t_map	*list;
	t_map	*tmp;

	tmp = NULL;
	if (*lst && del)
	{
		list = *lst;
		while (list)
		{
			del(list->map);
			if (list->next)
				tmp = list->next;
			else
				tmp = NULL;
			free(list);
			list = tmp;
		}
		*lst = NULL;
	}
}
