/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:32:44 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/27 13:00:12 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_Node *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return (1);
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	return (0);
}

void	sa(t_Node **a)
{
	if (swap(*a) == 1)
		return ;
	write(1, "sa\n", 3);
}

void	sb(t_Node **b)
{
	if (swap(*b) == 1)
		return ;
	write(1, "sb\n", 3);
}

void	ss(t_Node **a, t_Node **b)
{
	if (swap(*a) == 1 && swap(*b) == 1)
		return ;
	write(1, "ss\n", 3);
}
