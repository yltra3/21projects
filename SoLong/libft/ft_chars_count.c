/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:31:54 by clornel           #+#    #+#             */
/*   Updated: 2022/04/14 22:31:56 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chars_count(char *str, char c)
{
	int	i;
	int	rez;

	rez = 0;
	if (!str)
		return (rez);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			rez++;
		i++;
	}
	return (rez);
}

int	ft_check_symbols(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
