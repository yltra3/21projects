/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:42:12 by clornel           #+#    #+#             */
/*   Updated: 2021/10/30 19:42:14 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_string_printfuns(t_flags *init, char *f)
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

int	ft_print_with_flags_printfuns(t_flags *init, char *f, unsigned int a,
								int alength)
{
	int	c;

	if (init->dash)
	{
		if (init->is_zero)
			f[0] = 48;
		if (alength >= init->presision)
			c = alength;
		else
			c = init->presision;
		while (a)
		{
			f[--c] = a % 10 + 48;
			a /= 10;
		}
		if (init->is_zero && init->dot && !init->presision)
			f[0] = ' ';
	}
	else
		ft_notdash_uns(init, f, a);
	return (init->length += pr_putstr(f));
}

void	ft_print_uns(t_flags *init)
{
	int				a;
	int				alength;
	char			*f;
	int				i;

	a = va_arg(init->args, unsigned int);
	alength = ft_some_uns_flags(init, a);
	if (init->dot)
		init->zero = 0;
	if (init->is_printed)
		return ;
	if (!alength && !init->presision && !init->width)
		return ;
	i = -1;
	f = ft_allocate_uns(init, alength, i);
	if (!f)
		return ;
	ft_parse_string_printfuns(init, f);
	ft_print_with_flags_printfuns(init, f, a, alength);
	free(f);
}
