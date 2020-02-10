/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:34:56 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/10 11:58:48 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_map	*ft_lstlast(t_map *lst)
{
	t_map	*head;

	if (!lst)
		return (NULL);
	head = lst;
	while (head->next)
		head = head->next;
	return (head);
}
