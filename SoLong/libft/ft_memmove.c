/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:14:35 by clornel           #+#    #+#             */
/*   Updated: 2021/10/10 18:14:41 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst2;
	const unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = 0;
	if (!dst || !src)
		return (0);
	if (src2 < dst2)
		while (++i <= n)
			dst2[n - i] = src2[n - i];
	else
		while (n-- > 0)
			*(dst2++) = *(src2++);
	return (dst);
}
