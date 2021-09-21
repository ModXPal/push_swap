/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:49:06 by rcollas           #+#    #+#             */
/*   Updated: 2021/09/17 17:50:08 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FALSE 0
# define FAIL 0
# define TRUE 1
# define DO_RR 1
# define DO_R 0
# include "../libft/includes/libft.h"
# include <stdio.h>

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
void	create_pile_a(t_list **pile_a, char **argv);
void	big_sort(t_list **pile_a, t_list **pile_b);
void	number_to_top(t_list **pile_a, int chunk);
int		get_min(t_list *pile);
int		get_max(t_list *pile);
int		is_digit(char c);
int		check_arguments(char **argv);
int		check_duplicate(t_list *pile);
int		is_sorted(t_list *pile);
int		min_shorter_path(t_list *pile, int min);
int		max_shorter_path(t_list *pile, int max);
int		check_input(t_list **pile_a, char **argv, int arg);
int		get_chunk_size(int lst_size);
int		get_chunk(t_list *pile, int size);
int		shorter_path(t_list *pile, int chunk);
int		free_pile(t_list **pile);
int		free_arg(char **argv);
int		free_path(char **path);

#endif
