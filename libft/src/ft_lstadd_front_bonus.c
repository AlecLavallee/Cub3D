/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <alelaval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:30:43 by alelaval          #+#    #+#             */
/*   Updated: 2020/02/10 11:59:00 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_map **alst, t_map *new)
{
	if (new)
	{
		if (*alst == NULL)
		{
			*alst = new;
			new->next = NULL;
		}
		else
		{
			new->next = *alst;
			*alst = new;
		}
	}
}
