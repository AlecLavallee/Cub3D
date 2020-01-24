/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:08:12 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/21 15:56:16 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*list;
	t_list	*ref;

	list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	list = ft_lstnew(f(lst->content));
	ref = list;
	if (!ref)
		ft_lstclear(&ref, del);
	lst = lst->next;
	while (lst)
	{
		list = ft_lstnew(f(lst->content));
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
