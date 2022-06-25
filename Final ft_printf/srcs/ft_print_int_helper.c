/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 22:10:08 by clornel           #+#    #+#             */
/*   Updated: 2021/11/07 22:10:10 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int_dash(t_flags *init, char *f, long a, int alength)
{
	int	c;

	c = -1;
	if (init->is_zero)
		f[0] = 48;
	if (alength >= init->presision)
		c = alength + init->sign;
	else
		c = init->presision + init->sign;
	while (a)
	{
		f[--c] = a % 10 + 48;
		a /= 10;
	}
	if (init->sign && !init->plus)
		f[0] = '-';
	else if (init->sign && init->plus)
		f[0] = '+';
	if (init->is_zero && init->dot && !init->presision)
		f[0] = ' ';
}

void	ft_print_int_notdash(t_flags *init, char *f, int alength)
{
	if (init->sign && init->dot && init->presision >= alength)
	{
		if (!init->plus)
			f[pr_strlen(f) - init->presision - 1] = '-';
		else
			f[pr_strlen(f) - init->presision - 1] = '+';
	}
	else if (init->sign && init->dot)
	{
		if (!init->plus)
			f[pr_strlen(f) - alength - 1] = '-';
		else
			f[pr_strlen(f) - alength - 1] = '+';
	}
	else if (init->sign && init->zero)
		ft_print_int_notdash_over26_1(init, f);
	else if (init->sign && !init->zero && !init->dot)
	{
		if (!init->plus)
			f[pr_strlen(f) - alength - 1] = '-';
		else
			f[pr_strlen(f) - alength - 1] = '+';
	}
}

int	ft_print_int_some_flags(t_flags *init, long a)
{
	int		alength;
	long	c;

	c = a;
	alength = 0;
	if (c == 0)
		init->is_zero = 1;
	if (init->is_zero && !init->dot && !init->width)
		ft_work_with_zero(init);
	if (init->plus)
		init->sign = 1;
	if (c < 0)
	{
		c *= -1;
		init->sign = 1;
		init->plus = 0;
	}
	while (c)
	{
		c /= 10;
		alength++;
	}
	if (init->space)
		ft_work_with_space(init, a, alength);
	return (alength);
}

char	*ft_int_digit_memory(t_flags *init, int alength)
{
	int		c;
	char	*f;

	c = -1;
	if (init->width >= init->presision + init->sign
		&& init->width >= alength + init->sign)
	{
		f = pr_calloc(init->width + 1, sizeof(char));
		if (!f)
			return (0);
		while (++c < init->width)
			f[c] = ' ';
	}
	else if (init->presision + init->sign > init->width
		&& init->presision >= alength)
	{
		f = pr_calloc(init->presision + 1 + init->sign, sizeof(char));
		if (!f)
			return (0);
		while (++c < init->presision + init->sign)
			f[c] = ' ';
	}
	else
		f = ft_allocate_int_over26_1(init, alength);
	return (f);
}

char	*ft_allocate_int_over26_1(t_flags *init, int alength)
{
	int		c;
	char	*f;

	c = -1;
	f = pr_calloc(alength + 1 + init->sign, sizeof(char));
	if (!f)
		return (0);
	while (++c < alength + init->sign)
		f[c] = ' ';
	return (f);
}
