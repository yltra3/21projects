/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:45:24 by clornel           #+#    #+#             */
/*   Updated: 2021/10/15 15:45:26 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd(((n % 10) + '0'), fd);
	}
}
