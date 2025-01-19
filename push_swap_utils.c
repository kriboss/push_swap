/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:54:17 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/19 18:16:56 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				num;
	int				segno;
	int				cont;

	num = 0;
	segno = 1;
	i = 0;
	cont = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (++cont > 1)
			return (0);
		if (str[i] == '-')
			segno = -segno;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * segno);
}

int	check_index(t_Node **a, t_Node **b, t_Node *best)
{
	int	index;
	int	t_index;

	index = best->i;
	t_index = best->t_i;
	if (index > ft_lstsize(b) / 2 && t_index > ft_lstsize(a) / 2)
		return (3);
	if (index > ft_lstsize(b) / 2)
		return (1);
	if (t_index > ft_lstsize(a) / 2)
		return (0);
	return (2);
}

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

t_Node	*create_stack(int argc, char *argv[])
{
	t_Node	*a;
	t_Node	*tmp;
	int		*numbers;
	int		i;

	a = NULL;
	numbers = (int *)malloc(sizeof(int) * (argc - 1));
	if (!numbers)
		return (NULL);
	i = 0;
	while (argc-- > 1)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		if (numbers[i] == 0 && argv[i + 1][0] != '0')
		{
			free(numbers);
			return (NULL);
		}
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
