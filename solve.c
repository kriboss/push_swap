/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:33:46 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/09 13:25:25 by kbossio          ###   ########.fr       */
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
	t_Node	*tmpa;
	t_Node	*tmpb;
	int		i;
	int		j;

	tmpa = *a;
	i = 0;
	tmpb = *b;
	while (tmpb)
	{
		tmpa = *a;
		tmpb->index = i;
		tmpb->cost = 0;
		j = 0;
		while (tmpa && tmpb->t_value != tmpa->value)
		{
			j++;
			tmpa = tmpa->next;
		}
		tmpb->t_index = j;
		if (i > ft_lstsize(b) / 2 && j > ft_lstsize(a) / 2)
			tmpb->cost = ft_lstsize(b) - tmpb->index + ft_lstsize(a) - 1 - tmpb->t_index;
		else if (i > ft_lstsize(b) / 2)
			tmpb->cost = ft_lstsize(b) - tmpb->index + (tmpb->t_index + 1);
		else if (j > ft_lstsize(a) / 2)
			tmpb->cost = (ft_lstsize(a) - 1) - tmpb->t_index + tmpb->index;
		else
			tmpb->cost = tmpb->index + tmpb->t_index + 1;
		i++;
		tmpb = tmpb->next;
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
	while ((*b)->value != best->value || best->t_value != ft_lstlast(a)->value)
	{
		if ((*b)->value != best->value && best->index <= ft_lstsize(b) / 2
			&& best->t_value != ft_lstlast(a)->value && best->t_index <= ft_lstsize(a) / 2)
			rr(a, b);
		else if ((*b)->value != best->value && best->index > ft_lstsize(b) / 2
			&& best->t_value != ft_lstlast(a)->value && best->t_index > ft_lstsize(a) / 2)
			rrr(a, b);
		else if ((*b)->value != best->value)
		{
			if (best->index > ft_lstsize(b) / 2)
				rrb(b);
			else
				rb(b);
		}
		else
		{
			if (best->t_index > ft_lstsize(a) / 2)
				rra(a);
			else
				ra(a);
		}
	}
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
