#include "push_swap.h"

void	rra(Node **a)
{
	Node	*tmp;
	Node	*last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(Node **b)
{
	Node	*tmp;
	Node	*last;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *b;
	*b = last;
}


void	rrr(Node **a, Node **b)
{
	rra(a);
	rrb(b);
}