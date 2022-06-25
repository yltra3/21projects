/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:20:11 by clornel           #+#    #+#             */
/*   Updated: 2021/10/14 18:20:14 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	c;
	unsigned int	start;

	if (!s || !f)
		return (0);
	c = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (c + 1));
	if (!str)
		return (0);
	start = 0;
	while (s[start])
	{
		str[start] = f(start, s[start]);
		start++;
	}
	str[start] = 0;
	return (str);
}
