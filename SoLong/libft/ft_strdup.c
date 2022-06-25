/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:50:38 by clornel           #+#    #+#             */
/*   Updated: 2021/03/11 23:22:59 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*c;

	i = 0;
	while (src[i] != '\0')
		i++;
	c = (char *)malloc(i + 1);
	if (!c)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		c[i] = src[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
