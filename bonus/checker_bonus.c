/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:09:39 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/04 20:41:59 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	print_error(t_Node **a, t_Node **b)
{
	write(2, "Error\n", 6);
	free_lst(a);
	if (ft_lstsize(b) > 0)
		free_lst(b);
}

int	check_op(t_Node **a, t_Node **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a')
		return (sa(a), 0);
	else if (line[0] == 's' && line[1] == 'b')
		return (sb(b), 0);
	else if (line[0] == 's' && line[1] == 's')
		return (ss(a, b), 0);
	else if (line[0] == 'p' && line[1] == 'a')
		return (pa(a, b), 0);
	else if (line[0] == 'p' && line[1] == 'b')
		return (pb(a, b), 0);
	else if (line[0] == 'r' && line[1] == 'a')
		return (ra(a), 0);
	else if (line[0] == 'r' && line[1] == 'b')
		return (rb(b), 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		return (rra(a), 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		return (rrb(b), 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		return (rrr(a, b), 0);
	else if (line[0] == 'r' && line[1] == 'r')
		return (rr(a, b), 0);
	else
		return (print_error(a, b), 1);
}

int	checker(t_Node *a, t_Node *b)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * 4);
	if (!line)
		return (0);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (check_op(&a, &b, line) == 1)
			return (-1);
		i++;
		line = get_next_line(0);
	}
	if (check(&a) == 1 && ft_lstsize(&b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_lst(&a);
	free_lst(&b);
	free(line);
	return (i);
}

int	main(int argc, char *argv[])
{
	t_Node	*a;
	t_Node	*b;
	int		i;
	char	*count;

	i = 0;
	if (check_input(argc, argv) == 1)
		return (write(2, "Error\n", 6), 1);
	a = create_stack(argc, argv);
	if (!a || check_doubles(&a) == 0)
		return (free_lst(&a), write(2, "Error\n", 6), 1);
	b = NULL;
	count = ft_itoa(checker(a, b));
	if (count[0] == '-')
		return (1);
	write(1, "operations : ", 12);
	while (count[i])
		write(1, &count[i++], 1);
	write(1, "\n", 1);
	free(count);
	return (0);
}
