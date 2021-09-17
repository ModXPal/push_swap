/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:38:10 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/17 17:46:32 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_min(t_list *pile)
{
	int	min;

	if (!pile)
		return (0);
	min = pile->content;
	while (pile)
	{
		if (pile->content < min)
			min = pile->content;
		pile = pile->next;
	}
	return (min);
}

int	get_max(t_list *pile)
{
	int	max;

	max = pile->content;
	while (pile)
	{
		if (pile->content > max)
			max = pile->content;
		pile = pile->next;
	}
	return (max);
}

int	is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ')
		return (1);
	return (0);
}

int	is_sorted(t_list *pile)
{
	if (pile->next == NULL)
		return (1);
	while (pile->content < pile->next->content && pile)
	{
		pile = pile->next;
		if (pile->next == NULL)
			return (1);
	}
	return (0);
}

int	get_chunk_size(int lst_size)
{
	if (lst_size <= 10)
		return (3);
	else if (lst_size <= 50)
		return (7);
	else if (lst_size <= 100)
		return (18);
	else if (lst_size <= 500)
		return (45);
	return (65);
}
