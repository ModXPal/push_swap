/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:38:10 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/17 17:19:47 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		get_min(t_list *pile)
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

int		get_max(t_list *pile)
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

void	create_pile_a(t_list **pile_a, int argc, char **argv)
{
	int	i;
	t_list *tmp;

	i = 0;
	(void)argc;
	argv = ft_split(*argv, ' ');
	while (argv[i])
	{
		tmp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(pile_a, tmp);
		i++;
	}
}

