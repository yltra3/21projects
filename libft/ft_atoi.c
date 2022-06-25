/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:12:25 by clornel           #+#    #+#             */
/*   Updated: 2021/10/18 16:49:34 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static int	ft_help(const char *str, int i)
{
	unsigned long	r;
	int				c;

	r = 0;
	c = 0;
	while (*str >= '0' && *str <= '9')
	{
		c++;
		r = r * 10 + *str - 48;
		str++;
		if (c >= 10 && i == 1 && r > 9223372036854775807)
			return (-1);
		if (c >= 10 && i == -1 && r > 9223372036854775807)
			return (0);
	}
	return (i * (int)r);
}

int	ft_atoi(const char *str)
{
	int		i;

	i = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			i *= -1;
			str++;
		}
		else
			str++;
		if (*str == '+' || *str == '-')
			return (0);
	}
	if (*str == '+')
		str++;
	return (ft_help(str, i));
}
