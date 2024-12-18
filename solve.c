/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:44:40 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/18 10:48:41 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	<stdio.h>

void	solve(Node **a, Node **b)
{
	Node	*temp;
	
	while(check(a) == 0)
	{
		if((*a)->value > (*a)->next->value)
		{
			sa(a);
			printf("sa\n");
		}
		
		if (check(a) == 0)
		{
			rra(a);
			printf("rra\n");
		}
		
		indexing(a);

		temp = *a;
		while (temp)
		{
			printf("%i index %i; ", temp->value, temp->index);
			temp = temp->next;
		}
		printf("\n");
	}
}