/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:41:54 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/17 17:49:28 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_list **pile_a)
{
	if ((*pile_a)->content == get_max(*pile_a))
		sa(pile_a);
}

void	sort_three(t_list **pile_a)
{
	if (is_sorted(*pile_a))
		return ;
	if (ft_lstlast(*pile_a)->content == get_max(*pile_a))
		sa(pile_a);
	else if ((*pile_a)->content > (*pile_a)->next->content
		&& ft_lstlast(*pile_a)->content == get_min(*pile_a))
	{
		sa(pile_a);
		rra(pile_a);
	}
	else if ((*pile_a)->content == get_max(*pile_a)
		&& ft_lstlast(*pile_a)->content > (*pile_a)->next->content)
		ra(pile_a);
	else if ((*pile_a)->content == get_min(*pile_a)
		&& (*pile_a)->next->content == get_max(*pile_a))
	{
		sa(pile_a);
		ra(pile_a);
	}
	else
		rra(pile_a);
}

void	sort_five(t_list **pile_a, t_list **pile_b)
{
	int	i;

	i = 0;
	while (i++ < 2)
	{
		if (min_shorter_path(*pile_a, get_min(*pile_a)) == DO_R)
		{
			while ((*pile_a)->content != get_min(*pile_a))
				ra(pile_a);
		}
		else
		{
			while ((*pile_a)->content != get_min(*pile_a))
				rra(pile_a);
		}
		pb(pile_a, pile_b);
	}
	sort_three(pile_a);
	pa(pile_a, pile_b);
	pa(pile_a, pile_b);
}
