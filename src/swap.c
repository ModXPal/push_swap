/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:20:55 by rcollas           #+#    #+#             */
/*   Updated: 2021/08/31 18:07:20 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_list **pile_a)
{
	ft_lst_swap2first(pile_a);
	ft_putstr_fd("sa \n", 1);
}

void	sb(t_list **pile_b)
{
	ft_lst_swap2first(pile_b);
	ft_putstr_fd("sb \n", 1);
}

void	ss(t_list **pile_a, t_list **pile_b)
{
	ft_lst_swap2first(pile_a);
	ft_lst_swap2first(pile_b);
	ft_putstr_fd("ss \n", 1);
}
