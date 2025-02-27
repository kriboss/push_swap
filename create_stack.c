/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:20:23 by kbossio           #+#    #+#             */
/*   Updated: 2025/02/27 10:41:50 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	unsigned int	i;
	long			num;
	int				sgn;
	int				c;

	num = 0;
	sgn = 1;
	i = 0;
	c = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		c++;
		if (str[i] == '-')
			sgn = -sgn;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - 48);
		if (c > 1 || (num > IMAX && sgn == 1) || (num > IMIN && sgn == -1))
			return (IMAX + 2);
	}
	return (num * sgn);
}

int	words(const char *s, char c)
{
	size_t	n;
	int		in;

	n = 0;
	in = 0;
	while (*s)
	{
		if (*s != c && in == 0)
		{
			in = 1;
			n++;
		}
		else if (*s == c)
			in = 0;
		s++;
	}
	if (n == 0)
		return (1);
	return (n);
}

char	*duping(const char *s, char c)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len] && c != s[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	free_all(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**salva;

	i = 0;
	salva = (char **)malloc(sizeof(char *) * (words(s, c) + 1));
	if (!salva || !s)
		return (NULL);
	while (*s)
	{
		while (*s && c == *s)
			s++;
		if (*s)
		{
			salva[i] = duping(s, c);
			if (!salva[i])
				return (free_all(salva, i - 1), NULL);
			i++;
			while (*s && c != *s)
				s++;
		}
	}
	salva[i] = NULL;
	return (salva);
}
