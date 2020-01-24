/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:06:13 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/17 10:31:42 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*tmp;

	tmp = NULL;
	if (*lst && del)
	{
		list = *lst;
		while (list)
		{
			del(list->content);
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
