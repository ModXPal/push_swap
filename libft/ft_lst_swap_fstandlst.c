/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap_fstandlst.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 20:44:49 by rcollas           #+#    #+#             */
/*   Updated: 2021/08/16 14:12:18 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_swap_firstandlast(t_list **lst)
{
	t_list	*last_cell;
	t_list	*next_to_last;

	next_to_last = *lst;
	last_cell = ft_lstlast(*lst);
	while (next_to_last->next->next)
		next_to_last = next_to_last->next;
	next_to_last->next = *lst;
	last_cell->next = (*lst)->next;
	(*lst)->next = NULL;
	*lst = last_cell;
}
