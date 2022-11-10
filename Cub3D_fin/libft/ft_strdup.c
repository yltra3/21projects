/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:33:51 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/18 20:18:43 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dupl;
	int		i;

	dupl = (char *)malloc((ft_strlen(s1) + 1) * sizeof(dupl));
	if (!dupl)
		return (0);
	i = 0;
	while (s1[i])
	{
		dupl[i] = s1[i];
		i++;
	}
	dupl[i] = '\0';
	return (dupl);
}
