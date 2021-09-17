/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:49:06 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/17 17:19:48 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FALSE 0
# define FAIL 0
# define TRUE 1
# define DO_RR 1
# define DO_R 0
#include "../libft/includes/libft.h"
#include <stdio.h>

void	sa(t_list **pile_a);
void	sb(t_list **pile_b);
void	ra(t_list **pile_b);
void	rb(t_list **pile_b);
void	rra(t_list **pile_b);
void	rrb(t_list **pile_b);
void	pb(t_list **pile_a, t_list **pile_b);
void	pa(t_list **pile_a, t_list **pile_b);
void	ss(t_list **pile_a, t_list **pile_b);
void	rr(t_list **pile_a, t_list **pile_b);
void	rrr(t_list **pile_a, t_list **pile_b);
void	sort_two(t_list **pile_a);
void	sort_three(t_list **pile_a);
void	sort_five(t_list **pile_a, t_list **pile_b);
void	create_pile_a(t_list **pile_a, int argc, char **argv);
int		get_min(t_list *pile);
int		get_max(t_list *pile);
int		is_digit(char c);
int		check_arguments(char **argv);
int		check_duplicate(t_list *pile);
int		is_sorted(t_list *pile);
int		min_shorter_path(t_list *pile, int min);
int		max_shorter_path(t_list *pile, int max);
int		check_input(t_list **pile_a, char **argv, int arg);

#endif
