/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:27:12 by qmoreau           #+#    #+#             */
/*   Updated: 2022/07/07 19:40:01 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ra(t_list *head_a, t_list *head_b, int p)
{
	t_list	*temp;

	if (head_a->next->next == NULL)
		return ;
	temp = head_a->next->next;
	ft_lstlast(head_a)->next = head_a->next;
	head_a->next->next = NULL;
	head_a->next = temp;
	if (p == 1)
		ft_printf("ra\n");
}

void	rb(t_list *head_a, t_list *head_b, int p)
{
	t_list	*temp;

	if (head_b->next->next == NULL)
		return ;
	temp = head_b->next->next;
	ft_lstlast(head_b)->next = head_b->next;
	head_b->next->next = NULL;
	head_b->next = temp;
	if (p == 1)
		ft_printf("rb\n");
}

void	rr(t_list *head_a, t_list *head_b, int p)
{
	t_list	*temp;

	if (head_a->next->next != NULL)
	{
		temp = head_a->next->next;
		ft_lstlast(head_a)->next = head_a->next;
		head_a->next->next = NULL;
		head_a->next = temp;
	}
	if (head_b->next->next != NULL)
	{
		temp = head_b->next->next;
		ft_lstlast(head_b)->next = head_b->next;
		head_b->next->next = NULL;
		head_b->next = temp;
	}
	if (p == 1)
		ft_printf("rr\n");
}

void	rra(t_list *head_a, t_list *head_b, int p)
{
	t_list	*temp;

	temp = head_a;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = head_a->next;
	head_a->next = temp->next;
	temp->next = NULL;
	if (p == 1)
		ft_printf("rra\n");
}

void	rrb(t_list *head_a, t_list *head_b, int p)
{
	t_list	*temp;

	temp = head_b;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = head_b->next;
	head_b->next = temp->next;
	temp->next = NULL;
	if (p == 1)
		ft_printf("rrb\n");
}
