/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:09:39 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/27 00:24:24 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(int argc, char *argv[])
{
	char	*line;
	Node	*a;
	Node	*b;

	line = malloc(sizeof(char) * 4);
	a = create_stack(argc, argv);
	b = NULL;
	while ((line = get_next_line(0)) != NULL)
	{
		if (line[0] == 's' && line[1] == 'a')
			sa(&a);
		else if (line[0] == 's' && line[1] == 'b')
			sb(&b);
		else if (line[0] == 's' && line[1] == 's')
			ss(&a, &b);
		else if (line[0] == 'p' && line[1] == 'a')
			pa(&a, &b);
		else if (line[0] == 'p' && line[1] == 'b')
			pb(&a, &b);
		else if (line[0] == 'r' && line[1] == 'a')
			ra(&a);
		else if (line[0] == 'r' && line[1] == 'b')
			rb(&b);
		else if (line[0] == 'r' && line[1] == 'r')
			rr(&a, &b);
		else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
			rra(&a);
		else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
			rrb(&b);
		else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
			rrr(&a, &b);
		else
		{
			write(1, "Error\n", 6);
			free_lst(&a);
			return ;
		}
	}
	if (check(&a) == 1 && ft_lstsize(&b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_lst(&a);
	free_lst(&b);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
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
	checker(argc, argv);
	return (0);
}