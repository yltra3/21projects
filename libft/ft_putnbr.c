/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:12:25 by clornel           #+#    #+#             */
/*   Updated: 2021/03/08 21:10:16 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char	c;
	char	minus;
	int		i;

	i = 0;
	minus = '-';
	if (n == -2147483648)
		ft_put("-2147483648");
	else
	{
		if (n < 0)
		{
			write(1, &minus, 1);
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		c = (n % 10) + '0';
		write(1, &c, 1);
	}
}
