/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:38:50 by kbossio           #+#    #+#             */
/*   Updated: 2024/12/25 21:02:06 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Node	*ft_lstnew(int value)
{
	Node	*new;

	new = (Node *)malloc(sizeof(Node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	free_lst(Node **a)
{
	Node	*tmp;

	tmp = *a;
	while (tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
	*a = NULL;
}

Node	*ft_lstlast(Node **a)
{
	Node	*tmp;

	tmp = *a;
	if (!tmp)
		return (NULL);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

Node	*getmax(Node **a)
{
	Node	*tmp;
	Node	*max;

	tmp = *a;
	max = tmp;
	while (tmp)
	{
		if (max->value < tmp->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_lstsize(Node **a)
{
	Node	*tmp;
	int		n;

	tmp = *a;
	n = 0;
	while (tmp)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}
