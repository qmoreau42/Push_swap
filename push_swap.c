/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:51:48 by qmoreau           #+#    #+#             */
/*   Updated: 2022/03/28 10:30:56 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Libft/libft.h"
#include"Libft/ft_printf.h"

t_list	*fill(t_list **a, char **argv)
{
	int	i;
	t_list	*head;

	i = 2;
	head = ft_lstnew(argv[2]);
	//ft_lstadd_front(a, head);
	/*
	while (argv[i])
	{
		ft_lstadd_front(a, ft_lstnew(argv[i]));
		i++;
	}
	*/
	return (head);
}

void disp(t_list *lst)
{
	int		size;
	t_list	*temp;

	temp = lst;
	while (temp != NULL)
	{
		printf("%d", temp->content);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	int	*a;
	int	i;
	int	size;
	t_list	*head;
	t_list	**lst;

	head = fill(lst, argv);
	a = malloc(sizeof(*a) * 3);
	i = 0;
	a[0] = 123;
	a[1] = 4651;
	while (i < 2)
	{
		ft_printf("%d-", a[i]);
		i++;
	}
	printf("%d", head->content);
	//disp(*lst);
	free(head);
	return (0);
}
