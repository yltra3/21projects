/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:05:31 by clornel           #+#    #+#             */
/*   Updated: 2022/04/18 20:05:33 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gnl_cheker(char *ost)
{
	int	i;

	if (!ost)
		return (1);
	i = 0;
	while (*(ost + i) && *(ost + i) != '\n')
		i++;
	if (*(ost + i) == '\n')
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		answ;

	line = NULL;
	answ = ft_gnl(fd, &line);
	if (answ == -1)
	{
		if (line)
			free(line);
		return (NULL);
	}
	if (line && answ)
		return (ft_strjoin(line, "\n"));
	if (line && line[0])
		return (line);
	if (line)
		free(line);
	return (NULL);
}
