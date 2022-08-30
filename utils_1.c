/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:55:02 by qmoreau           #+#    #+#             */
/*   Updated: 2022/07/07 17:51:47 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	is_min(t_list *head_a, int nb)
{
	t_list	*temp;

	temp = head_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->content < nb)
			return (0);
	}
	return (1);
}

int	is_max(t_list *head_a, int nb)
{
	t_list	*temp;

	temp = head_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->content > nb)
			return (0);
	}
	return (1);
}

int	is_in_twice(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = 1;
		while (i + j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[i + j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	isint(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	err(char **argv, int argc)
{
	int			i;
	long int	nb;

	i = 1;
	while (argv[i])
	{
		if (!isint(argv[i]))
			return (1);
		nb = ft_atoi(argv[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (1);
		if (is_in_twice(argv, argc))
			return (1);
		i++;
	}
	return (0);
}
