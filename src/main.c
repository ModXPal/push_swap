/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:16:31 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/07 15:28:58 by rcollas          ###   ########.fr       */
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
		printf("argv = %s \n", argv[i]);
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

int		cut_in_fifth(t_list *pile)
{
	int	i;
	int	min;
	int new_min;
	t_list	*start;

	i = 1;
	min = get_min(pile);
	new_min = get_max(pile);
	start = pile;
	while (i < 5)
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
		if (i != 5)
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
	//if (lst_size < 5)
	//	return (-1);
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
	//printf("position = %d \n", position);
	//printf("i = %d \n", i);
	if (position >= i)
		return (DO_R);
	else
		return (DO_RR);
}

int	b_shorter_path(t_list *pile, int	max)
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

void	first_pass(t_list **pile_a, t_list **pile_b, int chunk, int i)
{
	while (*pile_a)
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
		if ((*pile_a)->content < get_min(*pile_b))
		{
			pb(pile_a, pile_b);
			rb(pile_b);
		}
		else
			pb(pile_a, pile_b);
		if (i++ == 5 && *pile_a)
		{
			i = 1;
			chunk = cut_in_fifth(*pile_a);
		}
	}
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	check_argument(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i] && is_digit(av[i][j]))
		{
			if (av[i][j] == ' ')
				j++;
			if (is_digit(av[i][j]) == FALSE)
				return (0);
			j++;
		}
		i++;
		ac--;
	}
	return (1);
}

void	get_argument(int ac, char **av)
{
	int i;
	char **tmp;

	i = 0;
	tmp = av;
	*av = "";
	while (i++ < ac)
	{
		printf ("tmp = %s \n", tmp[i]);
		tmp[i] = ft_strjoin(tmp[i], " ");
		*av = ft_strjoin(*av, tmp[i]);
		i++;
	}
	av = tmp;
	printf ("av = %s \n", *av);
}

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
	i = 1;
	if (check_argument(argc, argv) == FALSE)
		return (0);
	get_argument(argc, argv);
	create_pile_a(&pile_a, argc, argv);
	print_pile(pile_a, pile_b);
	chunk = cut_in_fifth(pile_a);
	lst_size = ft_lstsize(pile_a);
	if (is_sorted(pile_a))
		return (0);
	first_pass(&pile_a, &pile_b, chunk, i);
	/*
	while (pile_b)
	{
		while (pile_b->content < max_b)
			rb(&pile_b);
		pa(&pile_a, &pile_b);
		if (pile_b)
			max_b = get_max(pile_b);
	}
	*/
	//print_pile(pile_a, pile_b);
	///*
	max_b = get_max(pile_b);
	while (pile_b)
	{
		if (b_shorter_path(pile_b, max_b) == DO_RR)
		{
			while (pile_b->content < max_b)
				rrb(&pile_b);
		}
		else if (b_shorter_path(pile_b, max_b) == DO_R)
		{
			while (pile_b->content < max_b)
				rb(&pile_b);
		}
		pa(&pile_a, &pile_b);
		if (pile_b)
			max_b = get_max(pile_b);
	}
	//print_pile(pile_a, pile_b);
	//*/










}
