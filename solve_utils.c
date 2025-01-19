/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:36:48 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/19 17:56:10 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_best(t_Node **a, t_Node **b, t_Node *best)
{
	while ((*b)->value != best->value || best->t_value != ft_lstlast(a)->value)
	{
		if ((*b)->value != best->value && best->i <= ft_lstsize(b) / 2
			&& best->t_value != ft_lstlast(a)->value
			&& best->t_i <= ft_lstsize(a) / 2)
			rr(a, b);
		else if ((*b)->value != best->value && best->i > ft_lstsize(b) / 2
			&& best->t_value != ft_lstlast(a)->value
			&& best->t_i > ft_lstsize(a) / 2)
			rrr(a, b);
		else if ((*b)->value != best->value)
		{
			if (best->i > ft_lstsize(b) / 2)
				rrb(b);
			else
				rb(b);
		}
		else
		{
			if (best->t_i > ft_lstsize(a) / 2)
				rra(a);
			else
				ra(a);
		}
	}
}

int	get_tcost(t_Node *ta, t_Node *tb)
{
	int	j;

	j = 0;
	while (ta && tb->t_value != ta->value)
	{
		j++;
		ta = ta->next;
	}
	return (j);
}
