/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 16:46:08 by clornel           #+#    #+#             */
/*   Updated: 2021/10/30 16:46:11 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_init_init(t_flags *init)
{
	init->width = 0;
	init->zero = 0;
	init->dot = 0;
	init->dash = 0;
	init->plus = 0;
	init->is_printed = 0;
	init->persent = 0;
	init->space = 0;
	init->reshetka = 0;
	init->sign = 0;
	init->presision = 0;
	init->string = 0;
	init->is_zero = 0;
	init->bghex = "0123456789ABCDEF";
	init->smhex = "0123456789abcdef";
	return (init);
}

void	ft_print(t_flags *init, const char *s, int pos)
{
	if (s[pos] == 'c')
		ft_print_char(init);
	if (s[pos] == 'd' || s[pos] == 'i')
		ft_print_int(init);
	if (s[pos] == 's')
		ft_print_string_printfs(init);
	if (s[pos] == 'u')
		ft_print_uns(init);
	if (s[pos] == 'p')
		ft_print_pointer(init);
	if (s[pos] == 'x')
		ft_print_smhex(init);
	if (s[pos] == 'X')
		ft_print_bghex(init);
	if (s[pos] == '%')
		ft_print_percent(init);
}

int	ft_init_format(t_flags *init, const char *s, int pos)
{
	while (s[pos] != 'c' && s[pos] != 's' && s[pos] != 'p' && s[pos] != 'd'
		&& s[pos] != 'i' && s[pos] != 'u' && s[pos] != 'x' && s[pos] != 'X'
		&& s[pos] != '%')
	{
		if (s[pos] == '.')
			init->dot = 1;
		if (s[pos] == '-')
			init->dash = 1;
		if (s[pos] == '+')
			init->plus = 1;
		if (s[pos] == '0' && !init->width && !init->presision)
			init->zero = 1;
		if (s[pos] == ' ' && !init->width && !init->presision)
			init->space = 1;
		if (s[pos] == '#')
			init->reshetka = 1;
		if (pr_isdigit(s[pos]) && !init->dot)
			init->width = (init->width * 10 + (s[pos] - 48));
		if (pr_isdigit(s[pos]) && init->dot)
			init->presision = (init->presision * 10 + (s[pos] - 48));
		pos++;
	}
	ft_print(init, s, pos);
	return (pos);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	t_flags	*init;

	init = (t_flags *)malloc(sizeof(t_flags));
	if (!init)
		return (-1);
	ft_init_init(init);
	va_start(init->args, s);
	i = -1;
	init->length = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i = ft_init_format(init, s, i + 1);
			ft_init_init(init);
		}
		else
			init->length += write(1, &s[i], 1);
	}
	va_end(init->args);
	free(init);
	return (init->length);
}
