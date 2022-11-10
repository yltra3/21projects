/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_msg(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	check_valid_arg(argc, argv);
	init_data(&data);
	data.fd = check_open_file(argv[1]);
	if (!data.fd)
		exit (0);
	if (check_valid_symbols(&data.flags, data.fd) == 0)
		exit (0);
	if (check_map(&data) == 0)
		exit(0);
	close(data.fd);
	if (parse_map(&data, argv[1]) == 0)
		exit (0);
	if (check_map_border(data) == 0)
		exit (0);
	if (give_me_graphics(&data) == 0)
		exit (0);
	exit (0);
}
