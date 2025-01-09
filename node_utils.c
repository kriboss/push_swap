/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:38:50 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/09 13:12:06 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Node	*ft_lstnew(int value)
{
	t_Node	*new;

	new = (t_Node *)malloc(sizeof(t_Node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	free_lst(t_Node **a)
{
	t_Node	*tmp;

	tmp = *a;
	while (tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
	*a = NULL;
}

t_Node	*ft_lstlast(t_Node **a)
{
	t_Node	*tmp;

	tmp = *a;
	if (!tmp)
		return (NULL);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_Node	*getmax(t_Node **a)
{
	t_Node	*tmp;
	t_Node	*max;

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

int	ft_lstsize(t_Node **a)
{
	t_Node	*tmp;
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
