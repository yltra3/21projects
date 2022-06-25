/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:28:49 by clornel           #+#    #+#             */
/*   Updated: 2021/10/30 19:28:51 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_flags *init)
{
	char	a;
	char	c;

	c = ' ';
	a = va_arg(init->args, int);
	if (init->width && !init->dash)
	{
		while (init->width-- - 1)
			init->length += write(1, &c, 1);
		init->length += write(1, &a, 1);
	}
	else if (init->width && init->dash)
	{
		init->length += write(1, &a, 1);
		while (init->width-- - 1)
			init->length += write(1, &c, 1);
	}
	else
		init->length += write(1, &a, 1);
}
