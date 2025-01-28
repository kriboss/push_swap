/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:51:34 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/28 21:47:14 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line/get_next_line.h"

# define IMAX 2147483647L
# define IMIN 2147483648
# include <stdlib.h>
# include <unistd.h>

typedef struct s_Node
{
	int				rank;
	int				i;
	int				value;
	int				t_value;
	int				t_i;
	int				cost;
	struct s_Node	*next;
}	t_Node;

char	**ft_split(char const *s, char c);
int		words(const char *s, char c);
long	ft_atoi(const char *str);
t_Node	*create_stack(int argc, char *argv[]);

t_Node	*ft_lstnew(int value);
void	free_lst(t_Node **a);
t_Node	*ft_lstlast(t_Node **a);
t_Node	*getmax(t_Node **a);
int		ft_lstsize(t_Node **a);
void	ranking(t_Node **a);
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
int		get_tcost(t_Node *ta, t_Node *tb);
void	do_best(t_Node **a, t_Node **b, t_Node *best);

void	simple_sort(t_Node **a, t_Node **b);
void	sort3(t_Node **a);

char	*ft_itoa(int n);
int		check_input(int argc, char *argv[]);
int		check_doubles(t_Node **a);

#endif
