/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:06:44 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/21 14:18:54 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *str, char ch)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ch && (str[i + 1] == ch || !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_clean_mem(char **trash)
{
	int	i;

	i = 0;
	while (trash[i])
	{
		free(trash[i]);
		i++;
	}
	free(trash);
	return (0);
}

static char	*arr_making(char *dst, const char *src, int lenght, int indx)
{
	unsigned int	x;
	unsigned int	y;

	x = indx - lenght;
	y = 0;
	while (lenght--)
	{
		dst[y++] = src[x++];
	}
	dst[y] = '\0';
	return (dst);
}

static char	**split_helper(char **array, int elems, const char *src, char sep)
{
	int	index;
	int	i;
	int	len;

	index = 0;
	i = 0;
	len = 0;
	while (src[i] && index < elems)
	{
		while (src[i] && src[i] == sep)
			i++;
		while (src[i] && src[i] != sep)
		{
			len++;
			i++;
		}
		array[index] = (char *)malloc((len + 1) * sizeof(char));
		if (!array[index])
			ft_clean_mem(array);
		arr_making(array[index], src, len, i);
		len = 0;
		index++;
	}
	array[index] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		elem;

	if (!s)
		return (0);
	elem = word_count(s, c);
	arr = (char **)malloc((elem + 1) * sizeof(char *));
	if (!arr)
		return (0);
	split_helper(arr, elem, s, c);
	return (arr);
}
