/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:12:39 by clornel           #+#    #+#             */
/*   Updated: 2021/10/12 20:12:41 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*ft_leak(char **dst, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(dst[j]);
		j++;
	}
	free(dst);
	return (0);
}

static int	ft_words_len(char const *s, size_t start, char c)
{
	int	i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		i++;
		start++;
	}
	return (i);
}

static char	**ft_allo(char **dst, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	f;
	size_t	f1;
	size_t	j;

	i = -1;
	f1 = 0;
	while (++i < words)
	{
		while (s[f1] == c && s[f1])
			f1++;
		f = ft_words_len(s, f1, c);
		dst[i] = (char *)malloc(sizeof(char) * (f + 1));
		if (!dst[i])
			return (ft_leak(dst, i));
		j = 0;
		while (j < f)
			dst[i][j++] = s[f1++];
		dst[i][j] = 0;
	}
	dst[i] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	words;
	char	**dst;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			words++;
		i++;
	}
	dst = (char **)malloc(sizeof (char *) * (words + 1));
	if (!dst)
		return (0);
	dst = ft_allo(dst, s, c, words);
	return (dst);
}
