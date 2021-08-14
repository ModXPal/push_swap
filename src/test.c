/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:57:39 by rcollas           #+#    #+#             */
/*   Updated: 2021/08/12 17:46:00 by rcollas          ###   ########.fr       */
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
		printf("pile a = %d \n", (*pile_a)->content);
	}
}

int	main(int argc, char **argv)
{
	t_list	*pile_a;

	pile_a = NULL;
	create_pile_a(&pile_a, argc, argv);
	while (pile_a)
	{
		ft_putnbr_fd(pile_a->content, 1);
		pile_a = pile_a->next;
	}
}
