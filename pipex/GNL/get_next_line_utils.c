/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:17:43 by clornel           #+#    #+#             */
/*   Updated: 2021/11/10 19:17:45 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_returned(const char *s)
{
	char	ch;

	if (!s)
		return (NULL);
	ch = '\n';
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*gnl_join(char *s1, char *s2)
{
	char	*nstr;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	nstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!nstr)
		return (0);
	while (s1[i] != '\0')
		nstr[y++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		nstr[y++] = s2[i++];
	nstr[y] = '\0';
	free(s1);
	return (nstr);
}
