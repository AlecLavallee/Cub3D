/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:07:25 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/10 15:47:39 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_map **alst, t_map *new)
{
	t_map	*head;

	if (new)
	{
		if (!*alst)
		{
			*alst = new;
			new->next = NULL;
			new->prev = NULL;
		}
		else
		{
			head = ft_lstlast(*alst);
			head->next = new;
			head->prev = NULL;
		}
	}
}
