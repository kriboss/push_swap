/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:32:44 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/09 16:47:59 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_Node *stack)
{
	int	tmp;

	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	sa(t_Node **a)
{
	swap(*a);
	write(1, "sa\n", 3);
}

void	sb(t_Node **b)
{
	swap(*b);
	write(1, "sb\n", 3);
}

void	ss(t_Node **a, t_Node **b)
{
	swap(*a);
	swap(*b);
	write(1, "ss\n", 3);
}
