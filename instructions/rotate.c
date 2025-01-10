/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:57:58 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/09 16:47:56 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_Node **a)
{
	t_Node	*tmp;
	t_Node	*last;

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

void	rb(t_Node **b)
{
	t_Node	*tmp;
	t_Node	*last;

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

void	do_rr(t_Node **ab)
{
	t_Node	*tmp;
	t_Node	*last;

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

void	rr(t_Node **a, t_Node **b)
{
	do_rr(a);
	do_rr(b);
	write(1, "rr\n", 3);
}
