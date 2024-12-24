/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:32:40 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/25 21:47:04 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

Node	*create_stack(int argc, char *argv[])
{
	int		*numbers;
	int		i;
	Node	*a;
	Node	*tmp;

	a = NULL;
	i = 0;
	numbers = (int *)malloc(sizeof(int) * (argc - 1));
	while (i < argc - 1)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		if (numbers[i] == 0 && argv[i + 1][0] != '0')
		{
			free(numbers);
			return (NULL);
		}
		i++;
	}
	while (--i >= 0)
	{
		tmp = ft_lstnew(numbers[i]);
		if (!a)
			a = tmp;
		else
		{
			tmp->next = a;
			a = tmp;
		}
	}
	free(numbers);
	return (a);
}

int	main(int argc, char *argv[])
{
	Node	*a;
	Node	*b;
	Node	*tmp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9')
				&& argv[i][j] != '-' && argv[i][j] != '+')
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	a = create_stack(argc, argv);
	b = NULL;
	tmp = a;
	i = 0;
	while (tmp)
	{
		printf("a value: %d index: %d ranking: %d\n", tmp->value, i, tmp->rank);
		tmp = tmp->next;
		i++;
	}
	simple_sort(&a, &b);
	tmp = a;
	i = 0;
	while (tmp)
	{
		printf("a value: %d index: %d ranking %d\n", tmp->value, i, tmp->rank);
		tmp = tmp->next;
		i++;
	}
	printf("\nsolved: %i\n", check(&a));
	free_lst(&a);
	free_lst(&b);
	return (0);
}
