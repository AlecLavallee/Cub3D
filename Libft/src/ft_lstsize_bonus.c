/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:33:19 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/10 11:58:38 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_map *lst)
{
	int		i;
	t_map	*head;

	i = 0;
	head = lst;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
