/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:33:46 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/19 17:56:40 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setup(t_Node **a, t_Node **b)
{
	int		a_size;

	ranking(a);
	a_size = ft_lstsize(a);
	while (ft_lstsize(a) >= a_size / 2 + 1)
	{
		if ((*a)->rank <= a_size / 2)
			pb(a, b);
		else
			ra(a);
	}
	while (ft_lstsize(a) != 3)
		pb(a, b);
	sort3(a);
}

void	get_target_value(t_Node **a, t_Node **b)
{
	t_Node	*numbers;
	t_Node	*tmp;
	int		pos;

	tmp = *a;
	numbers = *b;
	while (numbers)
	{
		tmp = *a;
		pos = getmax(a)->value;
		while (tmp)
		{
			if ((numbers->value > tmp->value)
				&& (tmp->value > pos || pos > numbers->value))
				pos = tmp->value;
			tmp = tmp->next;
		}
		numbers->t_value = pos;
		numbers = numbers->next;
	}
}

void	get_cost(t_Node **a, t_Node **b)
{
	t_Node	*ta;
	t_Node	*tb;
	int		i;
	int		j;

	ta = *a;
	i = 0;
	tb = *b;
	while (tb)
	{
		ta = *a;
		tb->i = i;
		j = get_tcost(ta, tb);
		tb->t_i = j;
		if (i > ft_lstsize(b) / 2 && j > ft_lstsize(a) / 2)
			tb->cost = ft_lstsize(b) - tb->i + ft_lstsize(a) - 1 - tb->t_i;
		else if (i > ft_lstsize(b) / 2)
			tb->cost = ft_lstsize(b) - tb->i + (tb->t_i + 1);
		else if (j > ft_lstsize(a) / 2)
			tb->cost = (ft_lstsize(a) - 1) - tb->t_i + tb->i;
		else
			tb->cost = tb->i + tb->t_i + 1;
		i++;
		tb = tb->next;
	}
}

void	best_move(t_Node **a, t_Node **b)
{
	t_Node	*tmp;
	t_Node	*best;
	int		lowest;

	tmp = *b;
	best = tmp;
	lowest = tmp->cost;
	while (tmp)
	{
		if (tmp->cost < lowest)
		{
			best = tmp;
			lowest = tmp->cost;
		}
		tmp = tmp->next;
	}
	do_best(a, b, best);
}

void	solve(t_Node **a, t_Node **b)
{
	setup(a, b);
	while (*b)
	{
		get_target_value(a, b);
		get_cost(a, b);
		best_move(a, b);
		pa(a, b);
	}
	while (check(a) == 0)
		ra(a);
}
