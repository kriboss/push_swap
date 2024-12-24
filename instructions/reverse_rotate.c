/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:57:33 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/25 21:37:10 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(Node **a)
{
	Node	*tmp;
	Node	*last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

void	rrb(Node **b)
{
	Node	*tmp;
	Node	*last;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

void	do_rrr(Node **ab)
{
	Node	*tmp;
	Node	*last;

	if (!*ab || !(*ab)->next)
		return ;
	tmp = *ab;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *ab;
	*ab = last;
}

void	rrr(Node **a, Node **b)
{
	do_rrr(a);
	do_rrr(b);
	write(1, "rrr\n", 4);
}
