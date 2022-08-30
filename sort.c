/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:10:28 by qmoreau           #+#    #+#             */
/*   Updated: 2022/08/29 17:04:04 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_small_2(t_list *head_a, t_list *head_b)
{
	if (head_a->next->content < head_a->next->next->next->content)
		sa(head_a, head_b, 1);
	else if (head_a->next->next->content
		> head_a->next->next->next->content)
	{
		sa(head_a, head_b, 1);
		rra(head_a, head_b, 1);
	}
	else
		ra(head_a, head_b, 1);
}

void	sort_small_1(t_list *head_a, t_list *head_b, int size)
{
	if (size == 2 && is_sorted(head_a) != 1)
		ra(head_a, head_b, 1);
	if (size == 3 && is_sorted(head_a) != 1)
	{
		if (head_a->next->content < head_a->next->next->content)
		{
			if (head_a->next->content > head_a->next->next->next->content)
				rra(head_a, head_b, 1);
			else
			{
				rra(head_a, head_b, 1);
				sa(head_a, head_b, 1);
			}
		}
		else
			sort_small_2(head_a, head_b);
	}
}

void	sort_med(t_list *head_a, t_list *head_b, int size)
{
	while (pos_of_small(head_a) != 1)
	{
		if (pos_of_small(head_a) <= size / 2)
			ra(head_a, head_b, 1);
		else
			rra(head_a, head_b, 1);
	}
	pb(head_a, head_b, 1);
}

int	sort_1(t_list *head_a, t_list *head_b, int argc)
{
	while (ft_lstsize(head_a) - 1 > 3 && is_sorted(head_a) == 0)
	{
		sort_med(head_a, head_b, ft_lstsize(head_a));
		if (is_ordered(head_a))
			sort_order(head_a);
	}
	if (ft_lstsize(head_a) - 1 <= 3)
		sort_small_1(head_a, head_b, ft_lstsize(head_a) - 1);
}

int	sort(t_list *head_a, t_list *head_b, int argc)
{
	int			size_b;

	if (argc < 60)
		sort_1(head_a, head_b, argc);
	else
	{
		if (argc < 300)
			sort_huge(head_a, head_b);
		else
			sort_huge(head_a, head_b);
	}
	size_b = ft_lstsize(head_b);
	while (size_b != 0)
	{
		pa(head_a, head_b, 1);
		size_b--;
	}
}
