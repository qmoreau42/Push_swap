/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:15:31 by qmoreau           #+#    #+#             */
/*   Updated: 2022/03/09 15:29:08 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include"Libft/libft.h"

void	sa(int	*a)
{
	int	temp;

	if (!a[0] || !a[1])
		return ;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	sb(int	*a)
{
	int	temp;

	if (!a[0] || !a[1])
		return ;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	ss(int *a, int *b)
{
	sa(a);
	sb(b);
}

void	pa(int *a, int *b)
{
	int	temp;
	int	i;

	i = 0;
	while (a[i])
		i++;
}
