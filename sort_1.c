/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:29:11 by qmoreau           #+#    #+#             */
/*   Updated: 2022/08/28 18:51:51 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_big_4(t_list *head_a, t_list *head_b, t_list *temp, int min_cost)
{
	while (close_inf(head_a, temp->content) > ft_lstsize(head_a) / 2
		&& min_cost > ft_lstsize(head_b) / 2)
	{
		rrr(head_a, head_b, 1);
		temp = head_b->next;
		min_cost = cost(head_a, head_b);
		lst_to(temp, min_cost);
	}
}

void	sort_big_3(t_list *head_a, t_list *head_b)
{	
	t_list	*temp;
	int		min_cost;

	temp = head_b->next;
	min_cost = cost(head_a, head_b);
	lst_to(temp, min_cost);
	while (close_inf(head_a, temp->content) < ft_lstsize(head_a) / 2
		&& min_cost < ft_lstsize(head_b) / 2 && min_cost != 0
		&& close_inf(head_a, temp->content != 1))
	{
		rr(head_a, head_b, 1);
		temp = head_b->next;
		min_cost = cost(head_a, head_b);
		lst_to(temp, min_cost);
	}
	sort_big_4(head_a, head_b, temp, min_cost);
}

void	sort_big_2(t_list *head_a, t_list *head_b)
{	
	if (is_max(head_a, head_b->next->content))
	{
		while (close_inf(head_a, head_b->next->content)
			!= ft_lstsize(head_a) - 2)
		{
			if (close_inf(head_a, head_b->next->content)
				< ft_lstsize(head_a) / 2)
				ra(head_a, head_b, 1);
			else
				rra(head_a, head_b, 1);
		}
	}
	else
	{
		while (close_sup(head_a, head_b->next->content) != 0)
		{
			if (close_sup(head_a, head_b->next->content)
				< ft_lstsize(head_a) / 2)
				ra(head_a, head_b, 1);
			else
				rra(head_a, head_b, 1);
		}
	}
	pa(head_a, head_b, 1);
}

void	sort_big(t_list *head_a, t_list *head_b)
{
	int	min_cost;
	int	size;

	while (is_ordered(head_a) != 1)
		pb(head_a, head_b, 1);
	while (ft_lstsize(head_b) != 1)
	{
		sort_big_3(head_a, head_b);
		min_cost = cost(head_a, head_b);
		size = ft_lstsize(head_b);
		while (min_cost <= size / 2 && min_cost > 0)
		{
			rb(head_a, head_b, 1);
			min_cost--;
		}
		while (min_cost > size / 2 && min_cost < size)
		{
			rrb(head_a, head_b, 1);
			min_cost++;
		}
		sort_big_2(head_a, head_b);
	}
	sort_order(head_a);
}

void	sort_huge(t_list *head_a, t_list *head_b)
{
	int	len;
	int	med;

	while (is_ordered(head_a) != 1)
	{
		len = ft_lstsize(head_a);
		med = median(head_a);
		while (ft_lstsize(head_a) > len / 2 + 1)
		{
			if (head_a->next->content < med)
				pb(head_a, head_b, 1);
			else
				ra(head_a, head_b, 1);
		}
	}
	sort_big(head_a, head_b);
}
