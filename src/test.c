/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:57:39 by rcollas           #+#    #+#             */
/*   Updated: 2021/08/24 22:04:58 by rcollas          ###   ########.fr       */
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

void	swap_a(t_list **pile_a)
{
	ft_lst_swap2first(pile_a);
	ft_putstr_fd("sa \n", 1);
}

void	swap_b(t_list **pile_b)
{
	ft_lst_swap2first(pile_b);
	ft_putstr_fd("sb \n", 1);
}

void	swap_a_and_b(t_list **pile_a, t_list **pile_b)
{
	ft_lst_swap2first(pile_a);
	ft_lst_swap2first(pile_b);
	ft_putstr_fd("ss \n", 1);
}

void	push_b(t_list **pile_a, t_list **pile_b)
{
	t_list *tmp;

	tmp = *pile_a;
	ft_lstpush(pile_b, tmp);
	printf("pile a in pushb = %d \n", (*pile_a)->content);
	printf("pile a next in pushb = %d \n", (*pile_a)->next->content);
	(*pile_a) = (*pile_a)->next;
	ft_putstr_fd("pb \n", 1);
}

void	push_a(t_list **pile_a, t_list **pile_b)
{
	ft_lstpush(pile_a, *pile_b);
	*pile_b = (*pile_b)->next;
	ft_putstr_fd("pa \n", 1);
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;
	t_list	*pile_b;
	t_list	*start;

	pile_a = NULL;
	pile_b = NULL;
	create_pile_a(&pile_a, argc, argv);
	//swap_a(&pile_a);
	push_b(&pile_a, &pile_b);
	printf("pile a content == %d\n", pile_a->content);
	push_b(&pile_a, &pile_b);
	printf("pile a content == %d\n", pile_a->content);
	//push_b(&pile_a, &pile_b);
	//swap_b(&pile_b);
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
