/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:07:25 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/16 12:50:35 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*head;

	if (new)
	{
		if (!*alst)
		{
			*alst = new;
			new->next = NULL;
		}
		else
		{
			head = ft_lstlast(*alst);
			head->next = new;
		}
	}
}
