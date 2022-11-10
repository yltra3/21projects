/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:07:01 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/21 14:09:29 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	y;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	y = 0;
	if (dstsize <= dlen)
		return (dstsize + slen);
	while (dst[y])
		y++;
	while (dlen + i < dstsize - 1 && src[i])
	{
		dst[y] = src[i];
		i++;
		y++;
	}
	dst[y] = '\0';
	return (dlen + slen);
}
