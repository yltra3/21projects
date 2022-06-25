/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:21:41 by clornel           #+#    #+#             */
/*   Updated: 2022/04/16 18:21:43 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_m(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	if (!c)
	{
		while (str[i])
			i++;
	}
	else
	{
		while (str[i] && str[i] != (unsigned char)c)
			i++;
		if (!str[i])
			i = 0;
	}
	return (i);
}

static void	ft_join_helper(char const *s1, char const *s2, int c)
{
	if (s1 && (c == 1 || c == 3))
	{
		free ((char *)s1);
		s1 = NULL;
	}
	if (s2 && (c == 2 || c == 3))
	{
		free ((char *)s2);
		s2 = NULL;
	}
}

char	*ft_strjoin_m(char const *s1, char const *s2, int c)
{
	size_t	i;
	size_t	j;
	char	*rez;

	rez = malloc(sizeof(char) * (ft_strlen_m(s1, 0) + ft_strlen_m(s2, 0) + 1));
	if (!rez)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		rez[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		rez[i] = s2[j];
		i++;
		j++;
	}
	rez[i] = 0;
	ft_join_helper(s1, s2, c);
	return (rez);
}

void	ft_free_split(char **rez)
{
	int	i;

	if (!rez)
		return ;
	i = 0;
	while (rez[i])
	{
		if (rez[i])
		{
			free(rez[i]);
			rez[i] = NULL;
		}
		i++;
	}
	free(rez);
	rez = NULL;
}
