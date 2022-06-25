/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:37:48 by clornel           #+#    #+#             */
/*   Updated: 2021/11/07 20:37:50 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_dotpresision_str(t_flags *init)
{
	int		o;
	char	*h;

	o = -1;
	h = pr_calloc(init->presision + 1, sizeof(char));
	if (!h)
		return (0);
	while (++o < init->presision)
		h[o] = ' ';
	init->string = init->presision;
	return (h);
}

void	ft_print_string_over26_1(t_flags *init, char *a, char *f)
{
	int	o;

	o = -1;
	if (init->presision >= pr_strlen(a))
		while (++o < pr_strlen(a))
			f[--init->string] = a[pr_strlen(a) - o - 1];
	else
		while (++o < init->presision)
			f[--init->string] = a[init->width - o - 1];
	init->length += pr_putstr(f);
}

void	ft_print_string_over26_2(t_flags *init, char *a, char *f)
{
	int	o;

	o = -1;
	while (++o < (init->width - (init->width - pr_strlen(a))))
		f[--init->string] = a[pr_strlen(a) - o - 1];
	init->length += pr_putstr(f);
}

void	ft_print_string_over26_3(t_flags *init, char *a, char *f)
{
	ft_check_low_width_printfs(init, a, f);
	if (init->is_printed)
		return ;
	if (init->dot && !init->dash && init->width >= pr_strlen(a))
	{
		ft_print_string_over26_1(init, a, f);
		return ;
	}
	if (!init->dot && init->width >= pr_strlen(a))
		ft_print_string_over26_2(init, a, f);
	else
		init->length += pr_putstr(a);
}

char	*ft_print_string_over26_4(t_flags *init, char *a)
{
	init->length += pr_putstr(a);
	init->is_printed = 1;
	return (0);
}
