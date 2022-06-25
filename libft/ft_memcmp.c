/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:53:31 by clornel           #+#    #+#             */
/*   Updated: 2021/10/11 16:54:03 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *)(s1);
	s4 = (unsigned char *)(s2);
	i = 0;
	while (n)
	{
		if (s3[i] < s4[i])
			return (s3[i] - s4[i]);
		if (s3[i] > s4[i])
			return (s3[i] - s4[i]);
		if (s3[i] == s4[i])
		{
			i++;
			n--;
		}
	}
	return (0);
}
