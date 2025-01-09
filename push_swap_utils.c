/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:54:17 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/09 13:22:49 by kbossio          ###   ########.fr       */
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

int	check_index(t_Node **a, t_Node **b, t_Node *best)
{
	int	index;
	int	t_index;

	index = best->index;
	t_index = best->t_index;
	if (index > ft_lstsize(b) / 2 && t_index > ft_lstsize(a) / 2)
		return (3);
	if (index > ft_lstsize(b) / 2)
		return (1);
	if (t_index > ft_lstsize(a) / 2)
		return (0);
	return (2);
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
