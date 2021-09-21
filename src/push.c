/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:21:32 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/22 01:25:02 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;
	//t_list	*to_free;

	if (*pile_a)
	{
		tmp = *pile_a;
	//	to_free = *pile_a;
		(*pile_a) = (*pile_a)->next;
		ft_lstpush(pile_b, tmp);
		ft_putstr_fd("pb\n", 1);
	}
	//if (ft_lstsize(*pile_b) == 1)
	//	free(to_free);
}

void	pa(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	if (*pile_b)
	{
		tmp = *pile_b;
		(*pile_b) = (*pile_b)->next;
		ft_lstpush(pile_a, tmp);
		ft_putstr_fd("pa\n", 1);
	}
}
