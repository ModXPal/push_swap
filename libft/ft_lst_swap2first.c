/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap2first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:53:48 by rcollas           #+#    #+#             */
/*   Updated: 2021/08/16 14:12:03 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lst_swap2first(t_list **lst)
{
	t_list	*first_cell;
	t_list	*scnd_cell;
	t_list	*third_cell;

	first_cell = *lst;
	scnd_cell = (*lst)->next;
	third_cell = scnd_cell->next;
	if (ft_lstsize(*lst) < 2)
		return ;
	*lst = scnd_cell;
	(*lst)->next = first_cell;
	first_cell->next = third_cell;
}
