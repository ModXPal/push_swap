/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:57:39 by rcollas           #+#    #+#             */
/*   Updated: 2021/08/25 11:29:23 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_pile_a(t_list **pile_a, int argc, char **argv)
{
	int	i;
	t_list *tmp;

	i = 0;
	while (++i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(pile_a, tmp);
	}
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;
	t_list	*start;

	pile_a = NULL;
	pile_b = NULL;
	create_pile_a(&pile_a, argc, argv);
	sa(&pile_a);
	pb(&pile_a, &pile_b);
	pb(&pile_a, &pile_b);
	pb(&pile_a, &pile_b);
	ra(&pile_a);
	rb(&pile_b);
	rra(&pile_a);
	rrb(&pile_b);
	rrb(&pile_b);
	rrb(&pile_b);
	rrb(&pile_b);
	sa(&pile_a);
	pa(&pile_a, &pile_b);
	pa(&pile_a, &pile_b);
	pa(&pile_a, &pile_b);
	start = pile_a;
	while (start || pile_b)
	{
		if (start)
		{
			ft_putnbr_fd(start->content, 1);
			ft_putstr_fd(" ", 1);
			start = start->next;
		}
		else
			ft_putstr_fd("  ", 1);
		if (pile_b)
		{
			ft_putnbr_fd(pile_b->content, 1);
			pile_b = pile_b->next;
		}
		else
			ft_putstr_fd(" ", 1);
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("- -\n", 1);
	ft_putstr_fd("a b\n", 1);
}
