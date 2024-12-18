/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:32:40 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/18 14:07:51 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <fcntl.h>

void test_sa(Node **a)
{
	sa(a);
	printf("After sa:\n");
	Node *temp = *a;
	while (temp)
	{
		printf("%i ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void test_pb(Node **a, Node **b)
{
	pb(a, b);
	printf("After pb:\n");
	Node *temp = *a;
	printf("List a: ");
	while (temp)
	{
		printf("%i ", temp->value);
		temp = temp->next;
	}
	printf("\n");
	temp = *b;
	printf("List b: ");
	while (temp)
	{
		printf("%i ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void test_ra(Node **a)
{
	ra(a);
	printf("After ra:\n");
	Node *temp = *a;
	while (temp)
	{
		printf("%i ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

void test_rra(Node **a)
{
	rra(a);
	printf("After rra:\n");
	Node *temp = *a;
	while (temp)
	{
		printf("%i ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

Node	*create_stack(int argc, char *argv[])
{
	int	*numbers;
	int	i;
	Node *a;
	Node *tmp;
	
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

int main(int argc, char *argv[])
{
	Node	*a;
	Node	*b;
	int		fd;

	if(argc == 1)
	{
		printf("Error\n");
		return (0);
	}

	a = create_stack(argc, argv);
	b = NULL;
	printf("Initial lists:\n");
	printf("List a: ");
	Node *temp = a;
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