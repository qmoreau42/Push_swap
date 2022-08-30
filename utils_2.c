/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:17:39 by qmoreau           #+#    #+#             */
/*   Updated: 2022/06/22 16:33:36 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	init_min(t_list *head_a, int nb, int *exists)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = head_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->content < nb)
		{
			*exists = i;
			return (temp->content);
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_list *head_a)
{
	t_list	*temp;

	temp = head_a->next;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	pos_of_small(t_list *head_a)
{
	t_list	*temp;
	int		pos;
	int		i;
	int		val;

	temp = head_a->next;
	val = temp->content;
	i = 1;
	pos = i;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		if (temp->content < val)
		{
			pos = i;
			val = temp->content;
		}
	}
	return (pos);
}

int	is_ordered_2(t_list *temp, int cap)
{	
	if (is_sorted(temp) == 0)
		return (0);
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (cap < temp->content)
			return (0);
	}
	return (1);
}

int	is_ordered(t_list *head)
{
	int		i;
	int		small;
	int		cap;
	t_list	*temp;

	i = 1;
	temp = head->next;
	small = pos_of_small(head);
	cap = temp->content;
	if (is_sorted(head))
		return (1);
	while (i < small - 1)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
		i++;
	}
	if (is_ordered_2(temp, cap) == 0)
		return (0);
	return (1);
}
