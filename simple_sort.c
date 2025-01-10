/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:57:19 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/10 01:31:21 by kbossio          ###   ########.fr       */
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
	while (ft_lstsize(a) > 3)
		pb(a, b);
	sort3(a);
	if ((*b)->value < (*a)->value)
		pa(a, b);
	else
	{
		ra(a);
		pa(a, b);
		rra(a);
	}
}

void	sort5(t_Node **a, t_Node **b)
{
	while (ft_lstsize(a) > 3)
		pb(a, b);
	sort3(a);
	if ((*b)->value < (*a)->value)
		pa(a, b);
	else
	{
		ra(a);
		pa(a, b);
		rra(a);
	}
	if ((*b)->value < (*a)->value)
		pa(a, b);
	else
	{
		ra(a);
		pa(a, b);
		rra(a);
	}
}

void	simple_sort(t_Node **a, t_Node **b)
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
