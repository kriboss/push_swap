/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:44:40 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/17 19:49:46 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	<stdio.h>

void	solve(Node **a, Node **b)
{
	while(check(a) == 0)
	{
		if((*a)->value > (*a)->next->value)
		{
			sa(a);
			printf("sa\n");
		}
		else
		{
			ra(a);
			printf("ra\n");
		}
		indexing(a);
	}
}