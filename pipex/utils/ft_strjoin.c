/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:22:43 by clornel           #+#    #+#             */
/*   Updated: 2021/10/12 16:22:45 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"
#include "../bonus/pipex_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	f;
	char			*c;

	if (!s1 || !s2)
		return (0);
	c = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 1)) * sizeof(char));
	if (!c)
		return (0);
	f = 0;
	i = 0;
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[f])
	{
		c[i] = s2[f];
		i++;
		f++;
	}
	c[i] = 0;
	return (c);
}
