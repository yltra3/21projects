/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bghex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:00:45 by clornel           #+#    #+#             */
/*   Updated: 2021/10/30 20:00:46 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_with_flags_printfbghex(t_flags *init, char *f, unsigned int a,
									int alength)
{
	if (init->dash)
		ft_parse_dash_printfbghex(init, f, a, alength);
	else
		ft_parse_notdash_printfbghex(init, f, a);
	return (init->length += pr_putstr(f));
}

void	ft_parse_dash_printfbghex(t_flags *init, char *f, unsigned int a,
									int alength)
{
	int		c;

	c = -1;
	if (init->is_zero)
		f[0] = 48;
	if (alength >= init->presision)
		c = alength + init->sign;
	else
		c = init->presision + init->sign;
	while (a)
	{
		f[--c] = init->bghex[a % 16];
		a /= 16;
	}
	if (init->is_zero && init->dot && !init->presision)
		f[0] = ' ';
	if (init->reshetka)
	{
		f[1] = 'X';
		f[0] = '0';
	}
}

void	ft_parse_notdash_printfbghex(t_flags *init, char *f, unsigned int a)
{
	int	c;

	c = -1;
	if (init->is_zero)
		f[pr_strlen(f) - 1] = 48;
	c = pr_strlen(f);
	while (a)
	{
		f[--c] = init->bghex[a % 16];
		a /= 16;
	}
	if (init->is_zero && init->dot && !init->presision)
		f[pr_strlen(f) - 1] = ' ';
	if (init->reshetka && !init->zero)
	{
		f[--c] = 'X';
		f[--c] = 48;
	}
	else if (init->reshetka && init->zero)
	{
		f[0] = 48;
		f[1] = 'X';
	}
}

void	ft_print_bghex(t_flags *init)
{
	unsigned int	a;
	int				alength;
	char			*f;
	int				i;

	a = va_arg(init->args, unsigned int);
	alength = ft_check_dich_hex(init, a);
	if (a == 0)
		init->is_zero = 1;
	if (init->dot)
		init->zero = 0;
	if (init->is_zero && !init->presision && !init->width && init->dot)
		return ;
	if (init->is_zero && !init->dot && !init->width)
	{
		init->length += write(1, "0", 1);
		return ;
	}
	i = -1;
	f = ft_allocate_fhex(init, alength);
	if (!f)
		return ;
	ft_parse_string_printfhex(init, f);
	ft_print_with_flags_printfbghex(init, f, a, alength);
	free(f);
}
