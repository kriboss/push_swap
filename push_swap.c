/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:32:40 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/10 01:32:24 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_input(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9')
				&& argv[i][j] != '-' && argv[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_Node	*a;
	t_Node	*b;
	int		*numbers;
	int		i;

	i = 0;
	if (check_input(argc, argv))
		return (1);
	numbers = (int *)malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (1);
	a = create_stack(argc, argv);
	b = NULL;
	t_Node	*tmp = a;
	simple_sort(&a, &b);
	while (tmp)
	{
		printf("value: %d\n", tmp->value);
		tmp = tmp->next;
	}
	free_lst(&a);
	free_lst(&b);
	return (0);
}
