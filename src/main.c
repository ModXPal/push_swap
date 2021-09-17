/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:16:31 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/17 15:21:49 by rcollas          ###   ########.fr       */
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

int	min_shorter_path(t_list *pile, int min)
{
	int i;
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
	int i;
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

int	is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ')
		return (1);
	return (0);
}

int	check_arguments(char **argv)
{
	int i;

	i = 0;
	while (argv[0][i])
	{
		if (argv[0][i] == '-')
			i++;
		if (!is_digit(argv[0][i]))
			return (0);
		i++;
	}
	return (1);
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

void	sort_three(t_list **pile_a)
{
	if (is_sorted(*pile_a))
			return ;
	if (ft_lstlast(*pile_a)->content == get_max(*pile_a))
		sa(pile_a);
	else if ((*pile_a)->content > (*pile_a)->next->content && ft_lstlast(*pile_a)->content == get_min(*pile_a))
	{
		sa(pile_a);
		rra(pile_a);
	}
	else if ((*pile_a)->content == get_max(*pile_a) && ft_lstlast(*pile_a)->content > (*pile_a)->next->content)
		ra(pile_a);
	else if ((*pile_a)->content == get_min(*pile_a) && (*pile_a)->next->content == get_max(*pile_a))
	{
		sa(pile_a);
		ra(pile_a);
	}
	else
		rra(pile_a);
}

void	sort_two(t_list **pile_a)
{
	if ((*pile_a)->content == get_max(*pile_a))
		sa(pile_a);
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

int		check_duplicate(t_list *pile)
{
	t_list *ref;
	t_list *start;

	start = pile;
	ref = pile;
	while (pile)
	{
		ref = pile->next;
		while (ref)
		{
			if (pile->content == ref->content)
				return (TRUE);
			ref = ref->next;
		}
		ref = pile->next;
		pile = pile->next;
	}
	return (FALSE);
}

//int		check_maxint(t_list **pile_a)
//{
//}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;
	int		lst_size;
	int		max_b;
	int		chunk;
	int		i;

	pile_a = NULL;
	pile_b = NULL;
	i = 5;
	get_arguments(argc, argv);
	if (!check_arguments(argv))
	{
		printf("Error\n");
		return (0);
	}
	create_pile_a(&pile_a, argc, argv);
	if (check_duplicate(pile_a) == TRUE)
	{
		printf("Error\n");
		return (0);
	}
	//print_pile(pile_a, pile_b);
	lst_size = ft_lstsize(pile_a);
	//print_pile(pile_a, pile_b);
	if (is_sorted(pile_a))
		return (0);
	if (lst_size <= 10)
		i = 3;
	else if (lst_size <= 50)
		i = 7;
	else if (lst_size <= 100)
		i = 18;
	else if (lst_size <= 500)
		i = 45;
	if (lst_size == 2)
	{
		sort_two(&pile_a);
		//print_pile(pile_a, pile_b);
		return (0);
	}
	if (lst_size == 3)
	{
		sort_three(&pile_a);
		//print_pile(pile_a, pile_b);
		return (0);
	}
	if (lst_size == 5)
	{
		sort_five(&pile_a, &pile_b);
		//print_pile(pile_a, pile_b);
		return (0);
	}
	chunk = cut_in_fifth(pile_a, i);
	first_pass(&pile_a, &pile_b, chunk, i);
	max_b = get_max(pile_b);
	while (pile_b)
	{
		if (max_shorter_path(pile_b, max_b) == DO_RR)
		{
			while (pile_b->content < max_b)
				rrb(&pile_b);
		}
		else if (max_shorter_path(pile_b, max_b) == DO_R)
		{
			while (pile_b->content < max_b)
				rb(&pile_b);
		}
		pa(&pile_a, &pile_b);
		if (pile_b)
			max_b = get_max(pile_b);
	}
	//print_pile(pile_a, pile_b);
}
