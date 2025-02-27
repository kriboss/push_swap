/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:32:40 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/27 12:55:01 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (check_input(argc, argv) == 1)
		return (write(2, "Error\n", 6), 1);
	else if (check_input(argc, argv) == -1)
		return (0);
	a = create_stack(argc, argv);
	if (!a || check_doubles(&a) == 0)
		return (free_lst(&a), write(2, "Error\n", 6), 1);
	if (ft_lstsize(&a) == 1)
		return (free_lst(&a), 0);
	b = NULL;
	simple_sort(&a, &b);
	free_lst(&a);
	free_lst(&b);
	return (0);
}
