/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:16:31 by rcollas           #+#    #+#             */
/*   Updated: 2021/08/28 17:47:20 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:57:39 by rcollas           #+#    #+#             */
/*   Updated: 2021/08/28 17:15:27 by rcollas          ###   ########.fr       */
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

void	sort_pile_a(t_list **pile)
{
	int	sorted;

	sorted = 1;
	while (sorted)
	{
		if ((*pile)->content > ft_lstlast(*pile)->content)
			ra(pile);
		else if ((*pile)->content > (*pile)->next->content)
			sa(pile);
		else
			sorted = 0;
	}
}

void	sort_pile_b(t_list **pile)
{
	int	sorted;

	sorted = 1;
	while (sorted)
	{
		if ((*pile)->content < ft_lstlast(*pile)->content)
			ra(pile);
		//else if ((*pile)->content > ft_lstlast(*pile)->content)
		//	rra(pile);
		else if ((*pile)->content < (*pile)->next->content)
			sa(pile);
		else
			sorted = 0;
	}
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

void	print_pile(t_list *pile_a, t_list *pile_b)
{
	while (pile_a || pile_b)
	{
		if (pile_a)
		{
			ft_putnbr_fd(pile_a->content, 1);
			ft_putstr_fd(" ", 1);
			pile_a = pile_a->next;
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

int		is_max(t_list *pile_a, t_list *pile_b)
{
	while (pile_b)
	{
		if (pile_a->content < pile_b->content)
			return (0);
		pile_b = pile_b->next;
	}
	return (1);
}

int		is_min(t_list *pile_a, t_list *pile_b)
{
	while (pile_b)
	{
		if (pile_a->content > pile_b->content)
			return (0);
		pile_b = pile_b->next;
	}
	return (1);
}

int		get_min(t_list *pile_a)
{
	int	min;

	min = pile_a->content;
	while (pile_a)
	{
		if (pile_a->content < min)
			min = pile_a->content;
		pile_a = pile_a->next;
	}
	return (min);
}

int		get_max(t_list *pile_a)
{
	int	max;

	max = pile_a->content;
	while (pile_a)
	{
		if (pile_a->content > max)
			max = pile_a->content;
		pile_a = pile_a->next;
	}
	return (max);
}

int		get_median(t_list *pile_a)
{
	int		min;
	int		i;
	int		median;
	t_list	*start;

	i = 0;
	start = pile_a;
	median = get_max(pile_a);
	min = get_min(pile_a);
	while (i < ft_lstsize(pile_a) / 2)
	{
		while (pile_a)
		{
			if (pile_a->content < median && pile_a->content > min)
				median = pile_a->content;
			pile_a = pile_a->next;
		}
		min = median;
		i++;
		if (i + 1 < ft_lstsize(start) / 2)
			median = get_max(start);
		pile_a = start;
	}
	return (median);
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;
	t_list	*tmp;
	int		i;
	int		lst_size;
	int		wait;
	int		min;
	int		median;
	int		max_b;

	pile_a = NULL;
	pile_b = NULL;
	i = 0;
	wait = 1;
	create_pile_a(&pile_a, argc, argv);
	median = get_median(pile_a);
	tmp = pile_a;
	lst_size = ft_lstsize(pile_a);
	while (ft_lstsize(pile_b) < lst_size / 2)
	{
		if (pile_a->content <= median)
			pb(&pile_a, &pile_b);
		else
			ra(&pile_a);
	}
	min = get_min(pile_a);
	while (pile_a && is_sorted(pile_a) == FALSE)
	{
		while (pile_a->content > min)
			ra(&pile_a);
		pb(&pile_a, &pile_b);
		if (pile_a)
			min = get_min(pile_a);
	}
	max_b = get_max(pile_b);
	while (pile_b /*&& is_sorted(pile_b) == FALSE*/)
	{
		while (pile_b->content < max_b)
			rb(&pile_b);
		pa(&pile_a, &pile_b);
		if (pile_b)
			max_b = get_max(pile_b);
	}
	while (pile_b)
		pa(&pile_a, &pile_b);
	print_pile(pile_a, pile_b);
}
