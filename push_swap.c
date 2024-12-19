/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:32:40 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/19 19:02:12 by kbossio          ###   ########.fr       */
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
	if (argc < 2)
	{
		free(numbers);
		return (NULL);
	}
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
		tmp = ft_lstnew(numbers[i], i);
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
	Node	*temp;
	int		i;
	int		j;

	if (argc == 1)
	{
		printf("Error\n");
		return (0);
	}
	while (argv[i] != NULL)
	{
		j = 0;
		while(argv[i][j])
		{
			if((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-' && argv[i][j] != '+')
			{
				printf("Error\n");
				return (0);
			}
		}
	}
	a = create_stack(argc, argv);
	b = NULL;
	printf("Initial lists:\n");
	printf("List a: ");
	temp = a;
	while (temp)
	{
		printf("%i index %i; ", temp->value, temp->index);
		temp = temp->next;
	}
	printf("\n");
	printf("List b: ");
	temp = b;
	while (temp)
	{
		printf("%i index %i; ", temp->value, temp->index);
		temp = temp->next;
	}
	printf("\n");
	radix(&a, &b);
	printf("Initial lists:\n");
	printf("List a: ");
	temp = a;
	while (temp)
	{
		printf("%i index %i; ", temp->value, temp->index);
		temp = temp->next;
	}
	printf("\n");
	printf("List b: ");
	temp = b;
	while (temp)
	{
		printf("%i index %i; ", temp->value, temp->index);
		temp = temp->next;
	}
	return (0);
}
