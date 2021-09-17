/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:16:31 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/17 17:38:17 by rcollas          ###   ########.fr       */
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
