/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	handle_error(char *errormsg)
{
	write(2, "Error\n", 6);
	write(2, errormsg, ft_strlen(errormsg));
	write(2, "\n", 1);
	exit(-1);
}

int	open_file(char *path)
{
	int			fd;
	extern int	errno;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_error(strerror(errno));
	return (fd);
}

int	line_fields(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		i++;
	return (i);
}
