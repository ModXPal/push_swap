/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:34:19 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/22 01:06:13 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_arguments(char **argv)
{
	int	i;

	i = 0;
	while (argv[0][i + 1])
	{
		if (argv[0][i] == ' ')
			i++;
		if (argv[0][i] == '-')
			i++;
		if (!is_digit(argv[0][i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(t_list *pile)
{
	t_list	*ref;

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

int	check_empty_arg(char **argv, int argc)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == ' ')
		{
			return (1);
		}
	}
	return (0);
}

int	check_maxint(t_list *pile)
{
	while (pile)
	{
		if (pile->content > 2147483647)
			return (1);
		pile = pile->next;
	}
	return (0);
}

int	check_input(t_list **pile_a, char **argv, int argc)
{
	if (argc < 2)
	{
		printf("Error\n");
		return (0);
	}
	if (check_arguments(argv) == FAIL)
	{
		printf("Error\n");
		return (0);
	}
	if (check_empty_arg(argv, argc) == TRUE)
	{
		printf("Error\n");
		return (0);
	}
	create_pile_a(pile_a, argv);
	if (check_duplicate(*pile_a) == TRUE || check_maxint(*pile_a) == TRUE)
	{
		printf("Error\n");
		return (free_pile(pile_a) + free_path(argv));
	}
	if (is_sorted(*pile_a))
		return (free_pile(pile_a) + free_path(argv));
	return (1);
}
