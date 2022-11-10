/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:42:05 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/21 14:22:56 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (0);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) <= start)
	{
		sub = (char *)malloc(sizeof(char) + 1);
		if (!sub)
			return (0);
		sub[0] = 0;
		return (sub);
	}
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
