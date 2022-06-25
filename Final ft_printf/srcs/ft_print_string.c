/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:34:49 by clornel           #+#    #+#             */
/*   Updated: 2021/10/30 19:34:51 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_a_is_null_printfs(char *a)
{
	if (a == NULL)
		a = "(null)";
	return (a);
}

char	*ft_memory_printfs(t_flags *init, char *a)
{
	char	*f;
	int		o;

	o = -1;
	if (init->width && init->width >= pr_strlen(a))
	{
		f = pr_calloc(init->width + 1, sizeof(char));
		if (!f)
			return (0);
		while (++o < init->width)
			f[o] = ' ';
		init->string = init->width;
	}
	else if (init->dot && init->presision <= pr_strlen(a))
	{
		f = ft_dotpresision_str(init);
		if (!f)
			return (0);
	}
	else
		f = ft_print_string_over26_4(init, a);
	return (f);
}

void	ft_check_dot_dash_printfs(t_flags *init, char *a, char *f)
{
	int	o;

	o = -1;
	if (init->dot && init->dash)
	{
		while (++o < init->presision && a[o])
			f[o] = a[o];
		init->length += pr_putstr(f);
		init->is_printed = 1;
	}
	else if (!init->dot && init->dash)
	{
		while (++o < pr_strlen(a) && a[o])
			f[o] = a[o];
		init->length += pr_putstr(f);
		init->is_printed = 1;
	}
	else
		init->is_printed = 0;
}

int	ft_check_low_width_printfs(t_flags *init, char *a, char *f)
{
	int	i;

	i = -1;
	if (init->dot && init->presision < pr_strlen(a))
	{
		while (++i < pr_strlen(f) - (pr_strlen(f) - init->presision))
			f[pr_strlen(f) - i - 1] = a[init->presision - i - 1];
		init->length += pr_putstr(f);
		init->is_printed = 1;
		return (i);
	}
	else if (init->dot && init->presision >= pr_strlen(a))
	{
		while (++i < pr_strlen(f) && i < pr_strlen(a))
			f[pr_strlen(f) - i - 1] = a[pr_strlen(a) - i - 1];
		init->length += pr_putstr(f);
		init->is_printed = 1;
		return (i);
	}
	return (0);
}

void	ft_print_string_printfs(t_flags *init)
{
	char	*a;
	char	*f;

	a = va_arg(init->args, char *);
	a = ft_a_is_null_printfs(a);
	f = ft_memory_printfs(init, a);
	if (!f)
		return ;
	if (init->is_printed)
	{
		free(f);
		return ;
	}
	ft_check_dot_dash_printfs(init, a, f);
	if (init->is_printed)
	{
		free(f);
		return ;
	}
	ft_print_string_over26_3(init, a, f);
	free(f);
}
