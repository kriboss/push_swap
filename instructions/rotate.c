/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:57:58 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/25 21:37:46 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(Node **a)
{
	Node	*tmp;
	Node	*last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = tmp;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(Node **b)
{
	Node	*tmp;
	Node	*last;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	last = tmp;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	do_rr(Node **ab)
{
	Node	*tmp;
	Node	*last;

	if (!*ab || !(*ab)->next)
		return ;
	tmp = *ab;
	*ab = (*ab)->next;
	last = tmp;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rr(Node **a, Node **b)
{
	do_rr(a);
	do_rr(b);
	write(1, "rr\n", 3);
}
