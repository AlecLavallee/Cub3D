/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:37:36 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/10 11:58:51 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_map *lst, void (*f)(void *))
{
	t_map	*head;

	if (lst && f)
	{
		head = lst;
		while (head)
		{
			f(head->map);
			head = head->next;
		}
	}
}
