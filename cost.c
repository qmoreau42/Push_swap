/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:25:39 by qmoreau           #+#    #+#             */
/*   Updated: 2022/08/28 19:05:53 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	init(t_list *head_a, int nb, int *exists)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = head_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->content > nb)
		{
			*exists = i;
			return (temp->content);
		}
		i++;
	}
	return (0);
}

int	close_inf(t_list *head_a, int nb)
{
	int		i;
	int		pos;
	int		pos_init;
	int		closest_inf;
	t_list	*temp;

	temp = head_a;
	i = 0;
	closest_inf = init_min(head_a, nb, &pos_init);
	pos = pos_init;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->content > closest_inf && temp->content < nb)
		{
			closest_inf = temp->content;
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	close_sup(t_list *head_a, int nb)
{
	int		i;
	int		pos;
	int		pos_init;
	int		closest_sup;
	t_list	*temp;

	temp = head_a;
	i = 0;
	closest_sup = init(head_a, nb, &pos_init);
	pos = pos_init;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->content < closest_sup && temp->content > nb)
		{
			closest_sup = temp->content;
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	cost_1(t_list *head_a, t_list *head_b, t_list *temp, int i)
{
	int	cost;

	if (is_max(head_a, temp->content))
	{	
		if (close_inf(head_a, temp->content) > ft_lstsize(head_a) / 2)
			cost = ft_lstsize(head_a) - close_inf(head_a, temp->content) - 2;
		else
			cost = close_inf(head_a, temp->content) + 1;
	}
	else
	{
		if (close_sup(head_a, temp->content) > ft_lstsize(head_a) / 2)
			cost = ft_lstsize(head_a) - close_sup(head_a, temp->content) - 1;
		else
			cost = close_sup(head_a, temp->content);
	}
	if (i < ft_lstsize(head_b) / 2)
		return (cost + i);
	else
		return (cost + ft_lstsize(head_b) - i - 1);
}

int	cost(t_list *head_a, t_list *head_b)
{
	int		i;
	int		pos;
	int		cost;
	int		lowest;
	t_list	*temp;

	temp = head_b->next;
	i = 0;
	pos = i;
	lowest = cost_1(head_a, head_b, temp, i);
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		cost = cost_1(head_a, head_b, temp, i);
		if (lowest > cost)
		{
			lowest = cost;
			pos = i;
		}
	}
	return (pos);
}
