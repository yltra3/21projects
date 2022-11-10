/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:35:25 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/21 14:19:36 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*dupl;
	unsigned char	ch;

	i = ft_strlen(s);
	dupl = (char *)s;
	ch = c;
	while (i >= 0)
	{
		if (dupl[i] == ch)
			return (&dupl[i]);
		i--;
	}
	return (0);
}
