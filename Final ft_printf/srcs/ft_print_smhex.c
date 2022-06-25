/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_smhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 20:00:33 by clornel           #+#    #+#             */
/*   Updated: 2021/10/30 20:00:34 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_with_flags_printfsmhex(t_flags *init, char *f, unsigned int a,
									int alength)
{
	if (init->dash)
		ft_parse_dash_printfsmhex(init, f, a, alength);
	else
		ft_parse_notdash_printfsmhex(init, f, a);
	return (init->length += pr_putstr(f));
}

void	ft_parse_dash_printfsmhex(t_flags *init, char *f, unsigned int a,
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
		f[--c] = init->smhex[a % 16];
		a /= 16;
	}
	if (init->is_zero && init->dot && !init->presision)
		f[0] = ' ';
	if (init->reshetka)
	{
		f[1] = 'x';
		f[0] = '0';
	}
}

void	ft_parse_notdash_printfsmhex(t_flags *init, char *f, unsigned int a)
{
	int	c;

	c = -1;
	if (init->is_zero)
		f[pr_strlen(f) - 1] = 48;
	c = pr_strlen(f);
	while (a)
	{
		f[--c] = init->smhex[a % 16];
		a /= 16;
	}
	if (init->is_zero && init->dot && !init->presision)
		f[pr_strlen(f) - 1] = ' ';
	if (init->reshetka && !init->zero)
	{
		f[--c] = 'x';
		f[--c] = 48;
	}
	else if (init->reshetka && init->zero)
	{
		f[0] = 48;
		f[1] = 'x';
	}
}

void	ft_print_smhex(t_flags *init)
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
	ft_print_with_flags_printfsmhex(init, f, a, alength);
	free(f);
}
