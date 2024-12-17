/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:32:20 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/17 19:51:39 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct Node
{
	int value;
	int	index;
	struct Node	*next;
}	Node;

Node	*ft_lstnew(int value, int index);
void	indexing(Node **a);
int	ft_atoi(const char *str);
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

#endif