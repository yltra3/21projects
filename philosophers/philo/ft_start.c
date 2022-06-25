/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:50:00 by clornel           #+#    #+#             */
/*   Updated: 2022/04/23 17:50:02 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_exit(t_args *args, t_philosopher *ph)
{
	int	i;

	i = -1;
	while (++i < args->philo_count)
		pthread_join(ph[i].thread_id, NULL);
	i = -1;
	while (++i < args->philo_count)
		pthread_mutex_destroy(&(args->forks[i]));
	pthread_mutex_destroy(&(args->writing));
}

static void	ph_eating(t_philosopher *ph)
{
	t_args	*args;

	args = ph->args;
	pthread_mutex_lock(&(args->forks[ph->left_fork_id]));
	ft_print_of_actions(args, ph->ph_id, "has taken a fork");
	pthread_mutex_lock(&(args->forks[ph->right_fork_id]));
	ft_print_of_actions(args, ph->ph_id, "has taken a fork");
	pthread_mutex_lock(&(args->eating_mutex));
	ft_print_of_actions(args, ph->ph_id, "is eating");
	ph->t_last_ate = timestamp();
	pthread_mutex_unlock(&(args->eating_mutex));
	event_skip_time(args->time_eat, args);
	(ph->ate_times)++;
	pthread_mutex_unlock(&(args->forks[ph->left_fork_id]));
	pthread_mutex_unlock(&(args->forks[ph->right_fork_id]));
}

static void	*ph_thread(void *philo_void)
{
	t_philosopher	*ph;
	t_args			*args;

	ph = (t_philosopher *)philo_void;
	args = ph->args;
	if (ph->ph_id % 2)
		usleep(250);
	while (!(args->died))
	{
		if (args->philo_count != 1)
			ph_eating(ph);
		if (args->evrybdy_ate)
			break ;
		ft_print_of_actions(args, ph->ph_id, "is sleeping");
		event_skip_time(args->time_sleep, args);
		ft_print_of_actions(args, ph->ph_id, "is thinking");
	}
	return (NULL);
}

static void	ft_death(t_args *args, t_philosopher *ph)
{
	int	i;

	while (!(args->evrybdy_ate))
	{
		i = -1;
		while (++i < args->philo_count && !(args->died))
		{
			pthread_mutex_lock(&(args->eating_mutex));
			if (time_diff(ph[i].t_last_ate, timestamp()) > args->time_death)
			{
				ft_print_of_actions(args, i, "died");
				args->died = 1;
			}
			pthread_mutex_unlock(&(args->eating_mutex));
			usleep(100);
		}
		if (args->died)
			break ;
		i = 0;
		while (args->eat_count != -1 && i < args->philo_count
			&& ph[i].ate_times >= args->eat_count)
			i++;
		if (i == args->philo_count)
			args->evrybdy_ate = 1;
	}
}

int	ft_start(t_args *args)
{
	int				i;
	t_philosopher	*ph;

	i = 0;
	ph = args->philosophers;
	args->first_timestamp = timestamp();
	while (i < args->philo_count)
	{
		if (pthread_create(&(ph[i].thread_id), NULL, ph_thread, &(ph[i])))
			return (1);
		ph[i].t_last_ate = timestamp();
		i++;
	}
	ft_death(args, args->philosophers);
	ft_exit(args, ph);
	return (0);
}
