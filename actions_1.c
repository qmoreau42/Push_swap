/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:15:31 by qmoreau           #+#    #+#             */
/*   Updated: 2022/07/07 19:35:30 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sa(t_list *head_a, t_list *head_b, int p)
{
	t_list	*temp;

	temp = head_a->next->next->next;
	head_a->next->next->next = head_a->next;
	head_a->next = head_a->next->next;
	head_a->next->next->next = temp;
	if (p == 1)
		ft_printf("sa\n");
}

void	sb(t_list *head_a, t_list *head_b, int p)
{
	t_list	*temp;

	temp = head_b->next->next->next;
	head_b->next->next->next = head_b->next;
	head_b->next = head_b->next->next;
	head_b->next->next->next = temp;
	if (p == 1)
		ft_printf("sb\n");
}

void	ss(t_list *head_a, t_list *head_b, int p)
{
	t_list	*temp;

	temp = head_a->next->next->next;
	head_a->next->next->next = head_a->next;
	head_a->next = head_a->next->next;
	head_a->next->next->next = temp;
	temp = head_b->next->next->next;
	head_b->next->next->next = head_b->next;
	head_b->next = head_b->next->next;
	head_b->next->next->next = temp;
	if (p == 1)
		ft_printf("ss\n");
}

void	pa(t_list *head_a, t_list *head_b, int p)
{
	t_list	*temp;

	if (head_b->next == NULL)
		return ;
	temp = head_a->next;
	head_a->next = head_b->next;
	head_b->next = head_b->next->next;
	head_a->next->next = temp;
	if (p == 1)
		ft_printf("pa\n");
}

void	pb(t_list *head_a, t_list *head_b, int p)
{
	t_list	*temp;

	if (head_a->next == NULL)
		return ;
	temp = head_b->next;
	head_b->next = head_a->next;
	head_a->next = head_a->next->next;
	head_b->next->next = temp;
	if (p == 1)
		ft_printf("pb\n");
}
