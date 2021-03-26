/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:08:12 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/10 11:58:46 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_map	*ft_lstmap(t_map *lst, void *(*f)(void*), void (*del)(void *))
{
	t_map	*list;
	t_map	*ref;

	list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	list = ft_lstnew(f(lst->map));
	ref = list;
	if (!ref)
		ft_lstclear(&ref, del);
	lst = lst->next;
	while (lst)
	{
		list = ft_lstnew(f(lst->map));
		if (!list)
		{
			ft_lstclear(&ref, del);
			return (NULL);
		}
		ft_lstadd_back(&ref, list);
		lst = lst->next;
	}
	return (ref);
}
