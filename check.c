/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:38:50 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/17 17:42:49 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	check(Node **a)
{
	while(*a)
	{
		if((*a)->value > (*a)->next->value)
		{
			return (0);
		}
	}
	return (1);
}