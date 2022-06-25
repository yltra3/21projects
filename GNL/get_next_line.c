/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:17:08 by clornel           #+#    #+#             */
/*   Updated: 2021/11/10 19:17:10 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_returned(char *f)
{
	int	i;

	if (!f)
		return (0);
	i = -1;
	while (f[++i])
		if (f[i] == '\n')
			return (1);
	return (0);
}

char	*ft_new_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_cut_dst(char *dst)
{
	char	s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!dst)
		return (0):
	while (dst[i] && dst[i] != '\n')
		i++;
	if (!dst[i])
	{
		free(save);
		return (0);
	}
	s = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1);
	if (!s)
		return (0);
	i++;
	while (dst[i])
		s[j++] = dst[i++];
	s[j] = '\0';
	free(dst);
	return (s);
}

char	*get_next_line(int fd)
{
    char		*f;
	static char	*dst;
	int			r;

	r = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	f = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!f)
		return (NULL);
	while (!ft_returned(f) && r != 0)
	{
		r = read(fd, f, BUFFER_SIZE);
		if (r == -1)
		{
			free(f);
			return (NULL);
		}
		f[r] = 0;
		dst = ft_strjoin(dst, f);
	}
	free(f);
	f = ft_new_line(dst);
	dst = ft_cut_dst(dst);
	if (!r)
		return (NULL);
	return (f);
}
