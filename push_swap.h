/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:51:34 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/10 01:24:47 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line/get_next_line.h"

# include <stdlib.h>
# include <unistd.h>

typedef struct s_Node
{
	int				rank;
	int				index;
	int				value;
	int				t_value;
	int				t_index;
	int				cost;
	struct s_Node	*next;
}	t_Node;

t_Node	*ft_lstnew(int value);
void	free_lst(t_Node **a);
t_Node	*ft_lstlast(t_Node **a);
t_Node	*getmax(t_Node **a);
int		ft_lstsize(t_Node **a);
void	ranking(t_Node **a);
int		check_index(t_Node **a, t_Node **b, t_Node *best);
int		ft_atoi(const char *str);
t_Node	*create_stack(int argc, char *argv[]);
void	sa(t_Node **a);
void	sb(t_Node **b);
void	ss(t_Node **a, t_Node **b);
void	pa(t_Node **a, t_Node **b);
void	pb(t_Node **a, t_Node **b);
void	ra(t_Node **a);
void	rb(t_Node **b);
void	rr(t_Node **a, t_Node **b);
void	rra(t_Node **a);
void	rrb(t_Node **b);
void	rrr(t_Node **a, t_Node **b);

int		check(t_Node **a);
void	solve(t_Node **a, t_Node **b);
void	simple_sort(t_Node **a, t_Node **b);
void	sort3(t_Node **a);

#endif
