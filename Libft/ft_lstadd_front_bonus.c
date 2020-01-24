/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:30:43 by alelaval          #+#    #+#             */
/*   Updated: 2019/10/16 11:56:34 by alelaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
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
