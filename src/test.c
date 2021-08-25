/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:57:39 by rcollas           #+#    #+#             */
/*   Updated: 2021/08/25 11:19:08 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdio.h>

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

void	sa(t_list **pile_a)
{
	ft_lst_swap2first(pile_a);
	ft_putstr_fd("sa \n", 1);
}

void	sb(t_list **pile_b)
{
	ft_lst_swap2first(pile_b);
	ft_putstr_fd("sb \n", 1);
}

void	ss(t_list **pile_a, t_list **pile_b)
{
	ft_lst_swap2first(pile_a);
	ft_lst_swap2first(pile_b);
	ft_putstr_fd("ss \n", 1);
}

void	pb(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	if (*pile_a)
	{
		tmp = *pile_a;
		(*pile_a) = (*pile_a)->next;
		ft_lstpush(pile_b, tmp);
		ft_putstr_fd("pb \n", 1);
	}
}


void	pa(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	if (*pile_b)
	{
		tmp = *pile_b;
		(*pile_b) = (*pile_b)->next;
		ft_lstpush(pile_a, tmp);
		ft_putstr_fd("pb \n", 1);
	}
}

void	ra(t_list **pile_a)
{
	t_list	*first;

	first = *pile_a;
	*pile_a = (*pile_a)->next;
	(ft_lstlast(*pile_a))->next = first;
	first->next = NULL;
	ft_putstr_fd("ra \n", 1);
}

void	rb(t_list **pile_b)
{
	t_list	*first;

	first = *pile_b;
	*pile_b = (*pile_b)->next;
	(ft_lstlast(*pile_b))->next = first;
	first->next = NULL;
	ft_putstr_fd("rb \n", 1);
}

void	rr(t_list **pile_a, t_list **pile_b)
{
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
	ft_putstr_fd("rr \n", 1);
}

void	rra(t_list **pile_a)
{
	t_list	*next_to_last;
	t_list	*last_a;

	next_to_last = ft_lstnext_to_last(*pile_a);
	last_a = ft_lstlast(*pile_a);
	last_a->next = *pile_a;
	next_to_last->next = NULL;
	*pile_a = last_a;
}

void	rrb(t_list **pile_b)
{
	t_list	*next_to_last;
	t_list	*last_b;

	next_to_last = ft_lstnext_to_last(*pile_b);
	last_b = ft_lstlast(*pile_b);
	last_b->next = *pile_b;
	next_to_last->next = NULL;
	*pile_b = last_b;
}

void	rrr(t_list **pile_a, t_list **pile_b)
{
	t_list	*next_to_last_a;
	t_list	*next_to_last_b;
	t_list	*last_a;
	t_list	*last_b;

	next_to_last_a = ft_lstnext_to_last(*pile_a);
	next_to_last_b = ft_lstnext_to_last(*pile_b);
	last_a = ft_lstlast(*pile_a);
	last_b = ft_lstlast(*pile_b);
	last_a->next = *pile_a;
	last_b->next = *pile_b;
	next_to_last_a->next = NULL;
	next_to_last_b->next = NULL;
	*pile_a = last_a;
	*pile_b = last_b;
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
