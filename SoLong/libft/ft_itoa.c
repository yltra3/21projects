/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:43:11 by clornel           #+#    #+#             */
/*   Updated: 2021/10/14 15:43:15 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_minus(char *f, int n, int c)
{
	long	t;

	t = (long)n;
	f[0] = '-';
	f[c] = 0;
	c--;
	t = -t;
	while (t)
	{
		f[c] = t % 10 + 48;
		c--;
		t /= 10;
	}
	return (f);
}

static char	*ft_zeroplus(char *f, int n, int c)
{
	f[c] = 0;
	c--;
	if (n == 0)
		f[c] = '0';
	while (n)
	{
		f[c] = n % 10 + 48;
		n /= 10;
		c--;
	}
	return (f);
}

char	*ft_itoa(int n)
{
	int		i;
	int		c;
	char	*f;

	i = n;
	c = 0;
	if (i == 0)
		c++;
	while (i)
	{
		i /= 10;
		c++;
	}
	if (n < 0)
		c++;
	f = (char *)malloc(sizeof(char) * (c + 1));
	if (!f)
		return (0);
	if (n < 0)
		return (f = ft_minus(f, n, c));
	else
		return (f = ft_zeroplus(f, n, c));
}
