/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:51:20 by clornel           #+#    #+#             */
/*   Updated: 2021/11/07 19:51:23 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_allocate_fhex(t_flags *init, int alength)
{
	char	*f;
	int		i;

	i = -1;
	if (init->width >= init->presision && init->width >= alength)
	{
		f = pr_calloc(init->width + 1, sizeof(char));
		while (++i < init->width)
			f[i] = ' ';
	}
	else if (init->presision > init->width && init->presision >= alength)
	{
		f = pr_calloc(init->presision + 1 + (2 * init->reshetka), sizeof(char));
		while (++i < init->presision + (2 * init->reshetka))
			f[i] = ' ';
	}
	else
	{
		f = pr_calloc(alength + 1, sizeof(char));
		while (++i < alength)
			f[i] = ' ';
	}
	return (f);
}

int	ft_check_dich_hex(t_flags *init, unsigned int a)
{
	int	alength;

	alength = 0;
	if (init->space)
		init->length += write(1, " ", 1);
	while (a)
	{
		a /= 16;
		alength++;
	}
	if (init->reshetka)
		alength += 2;
	return (alength);
}

char	*ft_parse_string_printfhex(t_flags *init, char *f)
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
