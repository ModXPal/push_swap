/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:34:19 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/17 17:43:27 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_arguments(char **argv)
{
	int	i;

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

int	check_duplicate(t_list *pile)
{
	t_list	*ref;
	t_list	*start;

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

int	check_input(t_list **pile_a, char **argv, int argc)
{
	create_pile_a(pile_a, argc, argv);
	if (argc < 2)
	{
		printf("Error\n");
		return (0);
	}
	if (!check_arguments(argv))
	{
		printf("Error\n");
		return (0);
	}
	if (check_duplicate(*pile_a) == TRUE)
	{
		printf("Error\n");
		return (0);
	}
	if (is_sorted(*pile_a))
		return (0);
	return (1);
}
