/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_values_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:41:13 by clornel           #+#    #+#             */
/*   Updated: 2022/04/23 23:41:15 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	semaphore_init(t_args *args)
{
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_atecheck");
	args->forks = sem_open("/philo_forks", O_CREAT, S_IRWXU, args->philo_count);
	args->writing = sem_open("/philo_write", O_CREAT, S_IRWXU, 1);
	args->ate_check = sem_open("/philo_atecheck", O_CREAT, S_IRWXU, 1);
	if (args->forks <= 0 || args->writing <= 0 || args->ate_check <= 0)
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
	if (args->philo_count < 2 || args->time_death < 0 || args->time_eat < 0
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
	if (semaphore_init(args))
		return (2);
	philosophers_init(args);
	return (0);
}
