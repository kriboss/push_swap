/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:32:44 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/17 17:21:28 by kbossio          ###   ########.fr       */
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
}

void	sb(Node **b)
{
	swap(*b);
}

void	ss(Node **a, Node **b)
{
	swap(*a);
	swap(*b);
}