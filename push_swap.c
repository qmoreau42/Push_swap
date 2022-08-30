/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:51:48 by qmoreau           #+#    #+#             */
/*   Updated: 2022/08/28 19:29:02 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	clear(t_list *head, int nb)
{
	int		i;
	t_list	*temp;

	i = 0;
	while (i < nb)
	{
		temp = head->next;
		free(head);
		head = temp;
		i++;
	}
}

int	fill(t_list **head_a, char **argv)
{
	int		i;
	t_list	*temp;
	t_list	*empt;

	i = 1;
	temp = *head_a;
	while (argv[i] != NULL)
	{
		empt = ft_lstnew(ft_atoi(argv[i]));
		if (!empt)
			return (0);
		ft_lstadd_back(head_a, empt);
		i++;
	}
	return (1);
}

void	disp(t_list *head_a, t_list *head_b)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = head_a->next;
	temp2 = head_b->next;
	ft_printf("A\tB\n====\t====\n");
	while (temp1 || temp2)
	{
		if (temp1)
		{
			ft_printf("%d", temp1->content);
			temp1 = temp1->next;
		}
		else
			ft_printf("_");
		if (temp2)
		{
			ft_printf("\t%d", temp2->content);
			temp2 = temp2->next;
		}
		else
			ft_printf("\t_");
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	sort_order(t_list *head_a)
{
	while (is_sorted(head_a) != 1)
	{
		if (pos_of_small(head_a) < ft_lstsize(head_a) / 2)
			ra(head_a, head_a, 1);
		else
			rra(head_a, head_a, 1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*head_a;
	t_list	*head_b;

	if (err(argv, argc))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (argc == 1)
		return (0);
	head_a = ft_lstnew(0);
	head_b = ft_lstnew(0);
	if (!fill(&head_a, argv))
		return (0);
	if (is_ordered(head_a) || is_sorted(head_a))
		sort_order(head_a);
	else
		sort(head_a, head_b, argc);
	clear(head_a, argc);
	clear(head_b, 1);
	return (0);
}
