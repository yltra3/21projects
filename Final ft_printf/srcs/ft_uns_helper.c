/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:02:50 by clornel           #+#    #+#             */
/*   Updated: 2021/11/08 19:02:53 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_notdash_uns(t_flags *init, char *f, unsigned int a)
{
	int	c;

	c = -1;
	if (init->is_zero)
		f[pr_strlen(f) - 1] = 48;
	c = pr_strlen(f);
	while (a)
	{
		f[--c] = a % 10 + 48;
		a /= 10;
	}
	if (init->is_zero && init->dot && !init->presision)
		f[pr_strlen(f) - 1] = ' ';
}

char	*ft_allocate_uns(t_flags *init, int alength, int i)
{
	char	*f;

	if (init->width >= init->presision && init->width >= alength)
	{
		f = pr_calloc(init->width + 1, sizeof(char));
		if (!f)
			return (0);
		while (++i < init->width)
			f[i] = ' ';
	}
	else if (init->presision > init->width && init->presision >= alength)
	{
		f = pr_calloc(init->presision + 1, sizeof(char));
		if (!f)
			return (0);
		while (++i < init->presision)
			f[i] = ' ';
	}
	else
	{
		f = ft_allocate_uns_over26_1(alength);
		if (!f)
			return (0);
	}
	return (f);
}

char	*ft_allocate_uns_over26_1(int alength)
{
	char	*f;
	int		i;

	i = -1;
	f = pr_calloc(alength + 1, sizeof(char));
	if (!f)
		return (0);
	while (++i < alength)
		f[i] = ' ';
	return (f);
}

int	ft_some_uns_flags(t_flags *init, unsigned int a)
{
	int	alength;

	alength = 0;
	if (init->space)
		init->length += write(1, " ", 1);
	if (a == 0)
		init->is_zero = 1;
	if (init->is_zero && !init->dot && !init->width)
	{
		init->length += pr_putstr("0");
		init->is_printed = 1;
	}
	while (a)
	{
		a /= 10;
		alength++;
	}
	return (alength);
}
