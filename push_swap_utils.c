/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:54:17 by kbossio           #+#    #+#             */
/*   Updated: 2025/03/05 11:02:12 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check(t_Node **a)
{
	t_Node	*temp;

	temp = *a;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	check_doubles(t_Node **a)
{
	t_Node	*temp;
	t_Node	*temp2;

	temp = *a;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->value == temp2->value)
				return (0);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	check_input(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		return (-1);
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != ' '
				&& argv[i][j] != '-' && argv[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*pop_str(int argc, char *argv[], int i)
{
	int		*num;
	char	**str;

	num = (int *)malloc(sizeof(int) * words(argv[1], ' ') * argc - 1);
	if (!num)
		return (NULL);
	if (argc == 2 && words(argv[1], ' ') > 1)
		str = ft_split(argv[1], ' ');
	else
		str = argv + 1;
	while (str[i])
	{
		num[i] = ft_atoi(str[i]);
		if (ft_atoi(str[i++]) == IMAX + 2)
		{
			if (argc == 2 && words(argv[1], ' ') > 1)
				free_all(str, i + 2);
			return (free(num), NULL);
		}
	}
	if (argc == 2 && words(argv[1], ' ') > 1)
		free_all(str, i);
	return (num);
}

t_Node	*create_stack(int argc, char *argv[])
{
	t_Node	*a;
	t_Node	*tmp;
	int		*numbers;
	int		i;
	int		count;

	a = NULL;
	i = 0;
	numbers = pop_str(argc, argv, i);
	if (!numbers)
		return (NULL);
	count = (argc - 1) * words(argv[1], ' ');
	while (count-- > 0)
	{
		tmp = ft_lstnew(numbers[i]);
		if (!a)
			a = tmp;
		else
			ft_lstlast(&a)->next = tmp;
		i++;
	}
	free(numbers);
	return (a);
}
