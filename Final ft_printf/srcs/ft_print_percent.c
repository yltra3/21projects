/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:05:31 by clornel           #+#    #+#             */
/*   Updated: 2021/11/07 18:05:34 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_string_printfperc(t_flags *init, char *f)
{
	int	c;

	c = -1;
	if (init->zero && !init->dash)
		while (++c < pr_strlen(f))
			f[c] = '0';
	return (f);
}

int	ft_print_with_flags_printfperc(t_flags *init, char *f)
{
	if (init->dash)
		f[0] = '%';
	else
		f[pr_strlen(f) - 1] = '%';
	return (init->length += pr_putstr(f));
}

void	ft_print_percent(t_flags *init)
{
	int		c;
	char	*f;

	c = -1;
	if (init->width >= 1)
	{
		f = pr_calloc(init->width + 1, sizeof(char));
		while (++c < init->width)
			f[c] = ' ';
	}
	else
	{
		f = pr_calloc(2, sizeof(char));
		while (++c < 1)
			f[c] = ' ';
	}
	if (!f)
		return ;
	ft_parse_string_printfperc(init, f);
	ft_print_with_flags_printfperc(init, f);
	free(f);
}
