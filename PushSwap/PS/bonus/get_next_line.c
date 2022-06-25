/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:22:00 by clornel           #+#    #+#             */
/*   Updated: 2022/01/15 17:22:04 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_next_line(char **line)
{
	char	*buf;
	char	ch;
	int		i;

	i = 0;
	if (!line)
		return (-1);
	buf = malloc(4);
	if (!buf)
		return (-1);
	while ((read(0, &ch, 1)) > 0)
	{
		buf[i] = ch;
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			*line = buf;
			return (1);
		}
		i++;
	}
	buf[i] = '\0';
	*line = buf;
	free(buf);
	return (0);
}
