/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:48:14 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/20 10:30:13 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;

	i = n;
	if (!dst && !src)
		return (0);
	while (i--)
		*(char *)dst++ = *(char *)src++;
	return (dst - n);
}
