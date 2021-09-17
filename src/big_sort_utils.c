/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:30:46 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/17 17:47:54 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_chunk(t_list *pile, int size)
{
	int		i;
	int		min;
	int		new_min;
	t_list	*start;

	i = 1;
	min = get_min(pile);
	new_min = get_max(pile);
	start = pile;
	while (i < size)
	{
		while (pile)
		{
			if (pile->content > min && pile->content < new_min)
				new_min = pile->content;
			pile = pile->next;
		}
		pile = start;
		min = new_min;
		i++;
		if (i != size)
			new_min = get_max(pile);
	}
	return (new_min);
}

int	get_position(t_list *pile, int chunk)
{
	int	j;
	int	position;

	j = 0;
	position = 0;
	while (pile)
	{
		if (pile->content <= chunk)
			position = j;
		j++;
		pile = pile->next;
	}
	return (position);
}

int	shorter_path(t_list *pile, int chunk)
{
	int		i;
	int		position;
	int		lst_size;
	t_list	*start;

	i = 0;
	lst_size = ft_lstsize(pile);
	start = pile;
	while (pile->content > chunk)
	{
		i++;
		pile = pile->next;
	}
	pile = start;
	position = get_position(pile, chunk);
	if (position > lst_size / 2)
		position = lst_size - position;
	if (position >= i)
		return (DO_R);
	else
		return (DO_RR);
}

void	number_to_top(t_list **pile_a, int chunk)
{
	if (shorter_path(*pile_a, chunk) == DO_RR)
	{
		while ((*pile_a)->content > chunk)
			rra(pile_a);
	}
	else if (shorter_path(*pile_a, chunk) == DO_R)
	{
		while ((*pile_a)->content > chunk)
			ra(pile_a);
	}
}
