/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:53:44 by clornel           #+#    #+#             */
/*   Updated: 2021/10/30 19:53:46 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_notdash_pointer(t_flags *init, unsigned long a, char *f)
{
	int	c;

	c = -1;
	c = pr_strlen(f);
	while (a)
	{
		f[--c] = init->smhex[a % 16];
		a /= 16;
	}
	if (init->is_zero)
		f[--c] = '0';
	f[--c] = 'x';
	f[--c] = 48;
}

int	ft_print_with_flags_printfpointer(t_flags *init, char *f, unsigned long a,
									int alength)
{
	int		c;

	if (init->dash)
	{
		c = alength;
		while (a)
		{
			f[--c] = init->smhex[a % 16];
			a /= 16;
		}
		if (init->is_zero)
			f[2] = '0';
		f[1] = 'x';
		f[0] = '0';
	}
	else
		ft_notdash_pointer(init, a, f);
	return (init->length += pr_putstr(f));
}

int	ft_pointer_someflags(t_flags *init, unsigned long a)
{
	int	alength;

	alength = 0;
	if (a == 0 && !init->dot)
	{
		init->is_zero = 1;
		alength++;
	}
	if (init->is_zero && init->dot && !init->width)
	{
		init->length += write(1, "0x", 2);
		init->is_printed = 1;
		return (0);
	}
	while (a)
	{
		a /= 16;
		alength++;
	}
	return (alength);
}

char	*ft_allocate_pointer1(t_flags *init)
{
	int		i;
	char	*f;

	i = -1;
	f = pr_calloc(init->width + 1, sizeof(char));
	if (!f)
		return (0);
	while (++i < init->width)
		f[i] = ' ';
	return (f);
}

void	ft_print_pointer(t_flags *init)
{
	unsigned long	a;
	int				alength;
	char			*f;
	int				i;

	a = va_arg(init->args, unsigned long);
	alength = 0;
	alength += ft_pointer_someflags(init, a);
	if (init->is_printed)
		return ;
	i = -1;
	alength += 2;
	if (init->width >= alength)
		f = ft_allocate_pointer1(init);
	else
	{
		f = pr_calloc(alength + 1, sizeof(char));
		while (++i < alength)
			f[i] = ' ';
	}
	if (!f)
		return ;
	ft_print_with_flags_printfpointer(init, f, a, alength);
	free(f);
}
