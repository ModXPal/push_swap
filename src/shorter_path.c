/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shorter_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:46:53 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/17 17:45:17 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	min_shorter_path(t_list *pile, int min)
{
	int	i;
	int	lst_size;

	i = 0;
	lst_size = ft_lstsize(pile);
	while (pile->content > min && pile)
	{
		pile = pile->next;
		i++;
	}
	if (i > lst_size / 2)
		return (DO_RR);
	else
		return (DO_R);
}

int	max_shorter_path(t_list *pile, int max)
{
	int	i;
	int	lst_size;

	i = 0;
	lst_size = ft_lstsize(pile);
	while (pile->content < max && pile)
	{
		pile = pile->next;
		i++;
	}
	if (i > lst_size / 2)
		return (DO_RR);
	else
		return (DO_R);
}
