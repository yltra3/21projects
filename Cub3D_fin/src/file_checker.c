/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_open_file(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error_msg("Can't open map_file!");
	return (fd);
}

void	check_valid_arg(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		error_msg("Input must be: ./cub3d <map_name>.cub");
	len = ft_strlen(argv[1]);
	if (len < 4)
		error_msg("Invalid file name");
	else
	{
		if (argv[1][len - 4] != '.' || argv[1][len - 3] != 'c' ||
			argv[1][len - 2] != 'u' || argv[1][len - 1] != 'b')
			error_msg("Invalid file name");
	}
}
