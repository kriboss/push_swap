/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:32:44 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/21 14:52:45 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(Node *stack)
{
	int	tmp;

	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	sa(Node **a)
{
	swap(*a);
	write(1, "sa\n", 3);
}

void	sb(Node **b)
{
	swap(*b);
	write(1, "sb\n", 3);
}

void	ss(Node **a, Node **b)
{
	swap(*a);
	swap(*b);
	write(1, "ss\n", 3);
}
