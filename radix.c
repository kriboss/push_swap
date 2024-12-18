/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:56:26 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/18 18:35:55 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	<stdio.h>

int		get_max_bits(Node **a)
{

	Node	*tmp;
	int		max;
	int		max_bits;

	tmp = *a;
	max = tmp->value;
	max_bits = 0;
	while (tmp)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}

	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix(Node **a, Node **b)
{
	
	Node	*tmp;
	int		max_bits;
	int		i;
	int		j;
	int		n;
	
	max_bits = get_max_bits(a);
	i = 0;
	j = 0;
	n = ft_lstsize(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < n)
		{
			tmp = *a;
			if ((tmp->value & (1 << i)) == 0)
			{
				pb(a, b);
			}
			else
			{
				ra(a);
			}
		}
		while (ft_lstsize(b) != 0)
		{
			pa(a, b);
		}
		i++;
	}
}