/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:39:43 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/11 00:40:37 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

static size_t	count_digits(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	num;
	size_t			g;

	g = count_digits(n);
	num = n;
	result = (char *)malloc(sizeof(char) * (g + 1));
	if (!result)
		return (NULL);
	result[g--] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		num = -n;
	}
	if (n == 0)
		result[0] = '0';
	while (num > 0)
	{
		result[g--] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}
