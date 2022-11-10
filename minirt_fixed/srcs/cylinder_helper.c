/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	inseq_cyl(double *t, double *t0, double *t1)
{
	if (*t1 < *t0)
	{
		if (*t1 > 0)
			*t = *t1;
		else
			*t = *t0;
	}
	else
	{
		if (*t0 > 0)
			*t = *t0;
		else
			*t = *t1;
	}
}

void	ft_atod_helper(char *str, int *i, double *nbr)
{
	if (str[*i] == '.')
	{
		(*i)++;
		*nbr += dot_part(&str[*i], i);
	}
}

void	ft_split_helper(char const *s, size_t *i, char c)
{
	while (s[*i] == c && s[*i])
		(*i)++;
}

int	ft_gnl_hell(char **str)
{
	free(*str);
	*str = NULL;
	return (0);
}
