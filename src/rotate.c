/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:22:09 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/11 16:07:48 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_list **pile_a)
{
	if (!(*pile_a)->next)
		return ;
	t_list	*first;

	first = *pile_a;
	*pile_a = (*pile_a)->next;
	(ft_lstlast(*pile_a))->next = first;
	first->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **pile_b)
{
	if (!(*pile_b)->next)
		return ;
	t_list	*first;

	first = *pile_b;
	*pile_b = (*pile_b)->next;
	(ft_lstlast(*pile_b))->next = first;
	first->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **pile_a, t_list **pile_b)
{
	if (!(*pile_a)->next || !(*pile_b)->next)
		return ;
	t_list	*first_a;
	t_list	*first_b;

	first_a = *pile_a;
	first_b = *pile_b;
	*pile_a = (*pile_a)->next;
	(ft_lstlast(*pile_a))->next = first_a;
	first_a->next = NULL;
	*pile_b = (*pile_b)->next;
	(ft_lstlast(*pile_b))->next = first_b;
	first_b->next = NULL;
	ft_putstr_fd("rr\n", 1);
}
