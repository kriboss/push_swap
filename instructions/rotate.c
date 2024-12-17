#include "push_swap.h"

void	ra(Node **a)
{
	Node	*tmp;
	Node	*last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = tmp;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rb(Node **b)
{
	Node	*tmp;
	Node	*last;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	last = tmp;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	rr(Node **a, Node **b)
{
	ra(a);
	rb(b);
}