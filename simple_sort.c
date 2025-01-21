/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:57:19 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/21 18:01:29 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_Node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort3(t_Node **a)
{
	t_Node	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (i < tmp->value)
			i = tmp->value;
		tmp = tmp->next;
	}
	if (check(a) == 1)
		return ;
	if ((*a)->value == i)
		ra(a);
	else if ((*a)->next->value == i)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort4(t_Node **a, t_Node **b)
{
	ranking(a);
	while ((*a)->rank != 1)
	{
		ra(a);
	}
	pb(a, b);
	sort3(a);
	pa(a, b);
}

void	sort5(t_Node **a, t_Node **b)
{
	ranking(a);
	if (ft_lstlast(a)->rank == 1)
		rra(a);
	while ((*a)->rank != 1)
		ra(a);
	pb(a, b);
	if (ft_lstlast(a)->rank == 2)
		rra(a);
	while ((*a)->rank != 2)
		ra(a);
	pb(a, b);
	sort3(a);
	pa(a, b);
	pa(a, b);
}

void	simple_sort(t_Node **a, t_Node **b)
{
	if (check(a) == 0)
	{
		if (ft_lstsize(a) == 2)
			sort2(a);
		else if (ft_lstsize(a) == 3)
			sort3(a);
		else if (ft_lstsize(a) == 4)
			sort4(a, b);
		else if (ft_lstsize(a) == 5)
			sort5(a, b);
		else
			solve(a, b);
	}
}
