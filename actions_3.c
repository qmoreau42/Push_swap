/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:54:55 by qmoreau           #+#    #+#             */
/*   Updated: 2022/08/28 18:49:27 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rrr(t_list *head_a, t_list *head_b, int p)
{	
	t_list	*temp;

	temp = head_a;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = head_a->next;
	head_a->next = temp->next;
	temp->next = NULL;
	temp = head_b;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = head_b->next;
	head_b->next = temp->next;
	temp->next = NULL;
	if (p == 1)
		ft_printf("rrr\n");
}

int	median(t_list *head_a)
{
	t_list	*tmp_1;
	t_list	*tmp_2;
	int		ret;
	int		cpt;

	tmp_1 = head_a->next;
	while (tmp_1)
	{
		cpt = 0;
		ret = tmp_1->content;
		tmp_2 = head_a->next;
		while (tmp_2)
		{
			if (tmp_2->content < ret)
				cpt++;
			tmp_2 = tmp_2->next;
		}
		if (ft_lstsize(head_a) / 2 == cpt
			|| (ft_lstsize(head_a) - 1) / 2 == cpt)
			return (ret);
		tmp_1 = tmp_1->next;
	}
	return (0);
}

t_list	*lst_to(t_list *temp, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}
