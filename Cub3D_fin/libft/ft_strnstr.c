/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 09:20:46 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/20 14:17:10 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	y;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		y = 0;
		while (needle[y])
		{
			if (i + y >= len || needle[y] != haystack[i + y])
				break ;
			y++;
		}
		if (needle[y] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
