/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:43:41 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/21 14:11:38 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*d;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	d = (char *)malloc((len + 1) * sizeof(char));
	if (!d)
		return (0);
	i = 0;
	while (i < len)
	{
		d[i] = f(i, s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
