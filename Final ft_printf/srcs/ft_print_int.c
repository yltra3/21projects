/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:38:58 by clornel           #+#    #+#             */
/*   Updated: 2021/10/30 19:39:00 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_string_printfid(t_flags *init, char *f)
{
	int	c;

	c = -1;
	if (init->zero && !init->presision)
		while (++c < pr_strlen(f))
			f[c] = '0';
	if (init->presision && init->dash)
	{
		c = -1;
		while (++c < init->presision)
			f[c] = '0';
	}
	else if (init->presision && !init->dash)
	{
		c = pr_strlen(f);
		while (--c > pr_strlen(f) - init->presision)
			f[c] = 48;
		f[pr_strlen(f) - init->presision] = 48;
	}
	return (f);
}

int	ft_print_with_flags_printfid(t_flags *init, char *f, long a, int alength)
{
	int	c;

	if (init->dash)
		ft_print_int_dash(init, f, a, alength);
	else
	{
		if (init->is_zero)
			f[pr_strlen(f) - 1] = 48;
		c = pr_strlen(f);
		while (a)
		{
			f[--c] = a % 10 + 48;
			a /= 10;
		}
		ft_print_int_notdash(init, f, alength);
		if (init->is_zero && init->dot && !init->presision)
			f[pr_strlen(f) - 1] = ' ';
	}
	return (init->length += pr_putstr(f));
}

void	ft_print_int(t_flags *init)
{
	long	a;
	int		alength;
	char	*f;

	a = va_arg(init->args, int);
	alength = ft_print_int_some_flags(init, a);
	if (init->dot)
		init->zero = 0;
	if (init->is_printed)
		return ;
	if (!alength && !init->presision && !init->width)
		return ;
	if (a < 0)
		a *= -1;
	f = ft_int_digit_memory(init, alength);
	if (!f)
		return ;
	ft_parse_string_printfid(init, f);
	ft_print_with_flags_printfid(init, f, a, alength);
	free(f);
}
