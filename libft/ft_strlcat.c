/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:40:21 by clornel           #+#    #+#             */
/*   Updated: 2021/10/10 19:40:23 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	y;
	size_t	c;

	y = 0;
	i = ft_strlen(dst);
	c = i + 1;
	if (i > dstsize)
		return (dstsize + ft_strlen(src));
	if (i + 1 < dstsize)
	{
		while (y < (dstsize - c) && src[y])
		{
			dst[i] = src[y];
			i++;
			y++;
		}
		dst[i] = 0;
	}
	return (c - 1 + ft_strlen(src));
}
