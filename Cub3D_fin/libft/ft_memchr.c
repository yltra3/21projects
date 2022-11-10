/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:33:02 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/19 19:44:34 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	while (n--)
	{
		if (((unsigned char *)s)[i] == ch)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}
