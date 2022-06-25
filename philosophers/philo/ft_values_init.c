/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:11:04 by clornel           #+#    #+#             */
/*   Updated: 2022/04/22 19:11:05 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	mutex_init(t_args *args)
{
	int	i;

	i = args->philo_count;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(args->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(args->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(args->eating_mutex), NULL))
		return (1);
	return (0);
}

static int	philosophers_init(t_args *args)
{
	int	i;

	i = args->philo_count;
	while (--i >= 0)
	{
		args->philosophers[i].ph_id = i;
		args->philosophers[i].ate_times = 0;
		args->philosophers[i].t_last_ate = 0;
		args->philosophers[i].left_fork_id = i;
		args->philosophers[i].right_fork_id = (i + 1) % args->philo_count;
		args->philosophers[i].args = args;
	}
	return (0);
}

int	ft_values_init(t_args *args, char **av)
{
	args->philo_count = ft_atoi(av[1]);
	args->time_death = ft_atoi(av[2]);
	args->time_eat = ft_atoi(av[3]);
	args->time_sleep = ft_atoi(av[4]);
	args->evrybdy_ate = 0;
	args->died = 0;
	if (args->philo_count < 1 || args->time_death < 0 || args->time_eat < 0
		|| args->time_sleep < 0 || args->philo_count > 250)
		return (1);
	if (av[5])
	{
		args->eat_count = ft_atoi(av[5]);
		if (args->eat_count <= 0)
			return (1);
	}
	else
		args->eat_count = -1;
	if (mutex_init(args))
		return (2);
	philosophers_init(args);
	return (0);
}
