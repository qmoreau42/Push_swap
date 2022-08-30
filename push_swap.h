/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:51:50 by qmoreau           #+#    #+#             */
/*   Updated: 2022/08/28 18:49:53 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"Libft/libft.h"
# include<stdio.h>

int		err(char **argv, int argc);
void	disp(t_list *head_a, t_list *head_b);
void	sa(t_list *head_a, t_list *head_b, int p);
void	sb(t_list *head_a, t_list *head_b, int p);
void	ss(t_list *head_a, t_list *head_b, int p);
void	pa(t_list *head_a, t_list *head_b, int p);
void	pb(t_list *head_a, t_list *head_b, int p);
void	ra(t_list *head_a, t_list *head_b, int p);
void	rra(t_list *head_a, t_list *head_b, int p);
void	rb(t_list *head_a, t_list *head_b, int p);
void	rrb(t_list *head_a, t_list *head_b, int p);
void	rr(t_list *head_a, t_list *head_b, int p);
void	rrr(t_list *head_a, t_list *head_b, int p);
int		is_sorted(t_list *head_a);
int		is_ordered(t_list *head);
int		sort(t_list *head_a, t_list *head_b, int argc);
int		pos_of_small(t_list *head_a);
void	sort_order(t_list *head_a);
int		cost(t_list *head_a, t_list *head_b);
void	sort_big(t_list *head_a, t_list *head_b);
int		close_sup(t_list *head_a, int nb);
int		close_inf(t_list *head_a, int nb);
int		is_max(t_list *head_a, int nb);
int		is_min(t_list *head_a, int nb);
int		init_min(t_list *head_a, int nb, int *exists);
void	sort_huge(t_list *head_a, t_list *head_b);
int		median(t_list *head_a);
void	append(int *ret, int c);
int		*process(int *ret);
void	prt(int *ret, int nb);
void	sort_big_3(t_list *head_a, t_list *head_b);
t_list	*lst_to(t_list *temp, int nb);

#endif
