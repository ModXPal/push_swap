/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:16:31 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/17 17:19:43 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	is_sorted_b(t_list *pile)
{
	if (pile->next == NULL)
		return (1);
	while (pile->content > pile->next->content && pile)
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

int		get_position(t_list *pile_a, int	nb)
{
	int	lst_size;
	int	i;

	i = 0;
	lst_size = ft_lstsize(pile_a);
	while (pile_a->content != nb)
	{
		pile_a = pile_a->next;
		i++;
	}
	return (i);
}

int		cut_in_fifth(t_list *pile, int size)
{
	int	i;
	int	min;
	int new_min;
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

int		shorter_path(t_list *pile, int five_least)
{
	int i;
	int	j;
	int	position;
	int	lst_size;
	t_list	*start;

	i = 0;
	j = 0;
	position = 0;
	lst_size = ft_lstsize(pile);
	start = pile;
	while (pile->content > five_least)
	{
		i++;
		pile = pile->next;
	}
	pile = start;
	while (pile)
	{
		if (pile->content <= five_least)
			position = j;
		j++;
		pile = pile->next;
	}
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

void	first_pass(t_list **pile_a, t_list **pile_b, int chunk, int i)
{
	int j;

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
			chunk = cut_in_fifth(*pile_a, i);
		}
	}
}

void	get_arguments(int ac, char **av)
{
	int i;
	char **tmp;

	i = 1;
	tmp = av;
	*av = "";
	while (i < ac)
	{
		tmp[i] = ft_strjoin(tmp[i], " ");
		*av = ft_strjoin(*av, tmp[i]);
		i++;
	}
	av = tmp;
}

int		get_chunk_size(int lst_size)
{
	if (lst_size <= 10)
		return (3);
	else if (lst_size <= 50)
		return (7);
	else if (lst_size <= 100)
		return (18);
	else if (lst_size <= 500)
		return (45);
	return 65;
}

void	second_pass(t_list **pile_a, t_list **pile_b)
{
	int max_b;

	max_b = get_max(*pile_b);
	while (pile_b)
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
		if (pile_b)
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
	chunk = cut_in_fifth(*pile_a, chunk_size);
	first_pass(pile_a, pile_b, chunk, chunk_size);
	second_pass(pile_a, pile_b);
}

void	push_swap(t_list **pile_a, t_list **pile_b)
{
	int	lst_size;

	lst_size = ft_lstsize(*pile_a);
	if (lst_size == 2)
		sort_two(pile_a);
	else if (lst_size == 3)
		sort_three(pile_a);
	else if (lst_size == 5)
		sort_five(pile_a, pile_b);
	else
		big_sort(pile_a, pile_b);
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	get_arguments(argc, argv);
	if (check_input(&pile_a, argv, argc) == FAIL)
		return (0);
	push_swap(&pile_a, &pile_b);
}
