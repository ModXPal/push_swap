/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:57:44 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/22 00:46:24 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	free_pile(t_list **pile)
{
	t_list	*tmp;

	while (*pile)
	{
		tmp = (*pile)->next;
		free(*pile);
		*pile = tmp;
	}
	return (0);
}

int	free_arg(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
	return (0);
}

int	free_path(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	return (0);
}
