/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:32:40 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/11 00:38:40 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ranking(t_Node **a)
{
	t_Node	*tmp;
	t_Node	*find_max;
	int		i;

	tmp = *a;
	while (tmp)
	{
		find_max = *a;
		i = 1;
		while (find_max)
		{
			if (tmp->value > find_max->value)
				i++;
			find_max = find_max->next;
		}
		tmp->rank = i;
		tmp = tmp->next;
	}
}

int	main(int argc, char *argv[])
{
	t_Node	*a;
	t_Node	*b;
	int		*numbers;
	int		i;

	i = 0;
	if (check_input(argc, argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	numbers = (int *)malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (1);
	a = create_stack(argc, argv);
	b = NULL;
	simple_sort(&a, &b);
	t_Node	*tmp = a;
	while (tmp)
	{
		printf("value: %d\n", tmp->value);
		tmp = tmp->next;
	}
	free_lst(&a);
	free_lst(&b);
	return (0);
}
