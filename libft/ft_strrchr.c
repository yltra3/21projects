/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:55:03 by clornel           #+#    #+#             */
/*   Updated: 2021/10/11 14:55:04 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ss;

	ss = (char *)(s);
	i = ft_strlen(ss);
	while (i >= 0)
	{
		if (ss[i] == c)
			return (&ss[i]);
		i--;
	}
	return (0);
}
