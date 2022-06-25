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

char	*ft_new_line(char *str)
{
	int		i;
	char	*nstr;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	nstr = (char *)malloc(sizeof(char) * (i + 2));
	if (!nstr)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		nstr[i] = str[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_cut_dst(char *dst)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!dst)
		return (NULL);
	while (dst[i] && dst[i] != '\n')
		i++;
	if (!dst[i])
	{
		free(dst);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * ((ft_strlen(dst) - i + 1)));
	if (!s)
		return (NULL);
	i++;
	while (dst[i] != '\0')
		s[j++] = dst[i++];
	s[j] = '\0';
	free(dst);
	return (s);
}

char	*ft_read_string(int fd, char *dst)
{
	char	*nstr;
	int		ring;

	ring = 1;
	nstr = (char *)malloc(sizeof(char) * (101));
	if (!nstr)
		return (NULL);
	while (!ft_returned(dst) && ring != 0)
	{
		ring = read(fd, nstr, 100);
		if (ring == -1)
		{
			free(nstr);
			return (NULL);
		}
		nstr[ring] = '\0';
		dst = gnl_join(dst, nstr);
	}
	free(nstr);
	return (dst);
}

char	*get_next_line(int fd)
{
	char		*fin;
	static char	*dst;
	int			buf;

	buf = 100;
	if (fd < 0 || buf <= 0)
		return (NULL);
	dst = ft_read_string(fd, dst);
	if (!dst)
		return (NULL);
	fin = ft_new_line(dst);
	dst = ft_cut_dst(dst);
	return (fin);
}
