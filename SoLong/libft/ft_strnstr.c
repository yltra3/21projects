/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:50:38 by clornel           #+#    #+#             */
/*   Updated: 2021/03/07 22:16:34 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	start;
	unsigned int	i;

	if (!*needle)
		return ((char *)haystack);
	start = 0;
	while (haystack[start] && (size_t)start < len)
	{
		if (haystack[start] == needle[0])
		{
			i = 1;
			while (needle[i] && haystack[start + i] == needle[i]
				&& (size_t)(start + i) < len)
				i++;
			if (!needle[i])
				return ((char *)&haystack[start]);
		}
		start++;
	}
	return (0);
}
