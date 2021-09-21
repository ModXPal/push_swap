/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:23:18 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/22 01:10:53 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	first_pass(t_list **pile_a, t_list **pile_b, int chunk, int i)
{
	int	j;

	j = 1;
	while (*pile_a)
	{
		number_to_top(pile_a, chunk);
		if ((*pile_a)->content < get_min(*pile_b))
		{
			pb(pile_a, pile_b);
			rb(pile_b);
		}
		else
			pb(pile_a, pile_b);
		if (j++ == i && *pile_a)
		{
			j = 1;
			chunk = get_chunk(*pile_a, i);
		}
	}
}

void	second_pass(t_list **pile_a, t_list **pile_b)
{
	int	max_b;

	max_b = get_max(*pile_b);
	while (*pile_b)
	{
		if (max_shorter_path(*pile_b, max_b) == DO_RR)
		{
			while ((*pile_b)->content < max_b)
				rrb(pile_b);
		}
		else if (max_shorter_path(*pile_b, max_b) == DO_R)
		{
			while ((*pile_b)->content < max_b)
				rb(pile_b);
		}
		pa(pile_a, pile_b);
		if (*pile_b)
			max_b = get_max(*pile_b);
	}
}

void	big_sort(t_list **pile_a, t_list **pile_b)
{
	int	lst_size;
	int	chunk_size;
	int	chunk;

	lst_size = ft_lstsize(*pile_a);
	chunk_size = get_chunk_size(lst_size);
	chunk = get_chunk(*pile_a, chunk_size);
	first_pass(pile_a, pile_b, chunk, chunk_size);
	second_pass(pile_a, pile_b);
}
