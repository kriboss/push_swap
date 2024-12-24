/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:51:34 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/27 00:21:22 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct Node
{
	int rank;
	int	index;
	int value;
	int	t_value;
	int	t_index;
	int	cost;
	struct Node	*next;
}	Node;

Node	*ft_lstnew(int value);
void	free_lst(Node **a);
Node	*ft_lstlast(Node **a);
Node	*getmax(Node **a);
int		ft_lstsize(Node **a);
void	ranking(Node **a);
int		check_index(Node **a, Node **b, Node *best);
int		ft_atoi(const char *str);
Node	*create_stack(int argc, char *argv[]);
void	sa(Node **a);
void	sb(Node **b);
void	ss(Node **a, Node **b);
void	pa(Node **a, Node **b);
void	pb(Node **a, Node **b);
void	ra(Node **a);
void	rb(Node **b);
void	rr(Node **a, Node **b);
void	rra(Node **a);
void	rrb(Node **b);
void	rrr(Node **a, Node **b);

int		check(Node **a);
void	solve(Node **a, Node **b);
void	simple_sort(Node **a, Node **b);
void	sort3(Node **a);

#endif