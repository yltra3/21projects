/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:35:05 by clornel           #+#    #+#             */
/*   Updated: 2022/04/22 17:35:08 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_write_error_fd(char *msg)
{
	int	len;

	len = 0;
	while (msg[len])
		len++;
	write(2, "Error: ", 7);
	write(2, msg, len);
	write(2, "\n", 1);
	return (1);
}

static int	ft_err_exit_1_2(int code)
{
	if (code == 1)
		return (ft_write_error_fd("There is one or more wrong arguments"));
	if (code == 2)
		return (ft_write_error_fd("Mutex init error"));
	return (10);
}

int	main(int ac, char **av)
{
	t_args	args;
	int		rt;

	if (ac != 5 && ac != 6)
		return (ft_write_error_fd("Less or more args than needed"));
	rt = ft_values_init(&args, av);
	if (rt)
		return (ft_err_exit_1_2(rt));
	if (ft_start(&args))
		return (ft_write_error_fd("Threads creating error"));
	return (0);
}
