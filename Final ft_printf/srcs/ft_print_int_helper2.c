/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_helper2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 22:49:02 by clornel           #+#    #+#             */
/*   Updated: 2021/11/07 22:49:03 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int_notdash_over26_1(t_flags *init, char *f)
{
	if (!init->plus)
		f[0] = '-';
	else
		f[0] = '+';
}

void	ft_work_with_space(t_flags *init, long a, int alength)
{
	if (a <= 0)
		return ;
	if (init->width > alength + init->sign)
	{
		init->length += write(1, " ", 1);
		init->width--;
	}
	else if (!init->width)
		init->length += write(1, " ", 1);
}

void	ft_work_with_zero(t_flags *init)
{
	if (init->space)
		init->length += write(1, " ", 1);
	if (init->plus)
		init->length += write(1, "+", 1);
	init->length += write(1, "0", 1);
	init->is_printed = 1;
}
