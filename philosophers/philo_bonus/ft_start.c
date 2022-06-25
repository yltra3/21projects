/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:41:36 by clornel           #+#    #+#             */
/*   Updated: 2022/04/23 23:41:38 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_exit(t_args *args)
{
	int	i;
	int	rt;

	i = -1;
	while (++i < args->philo_count)
	{
		waitpid(-1, &rt, 0);
		if (rt != 0)
		{
			i = -1;
			while (++i < args->philo_count)
				kill(args->philosophers[i].proc_id, 15);
			break ;
		}
	}
	sem_close(args->forks);
	sem_close(args->writing);
	sem_close(args->ate_check);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_write");
	sem_unlink("/philo_atecheck");
}

static void	ph_eating(t_philosopher *ph)
{
	t_args	*args;

	args = ph->args;
	sem_wait(args->forks);
	ft_print_of_actions(args, ph->ph_id, "has taken a fork");
	sem_wait(args->forks);
	ft_print_of_actions(args, ph->ph_id, "has taken a fork");
	sem_wait(args->ate_check);
	ft_print_of_actions(args, ph->ph_id, "is eating");
	ph->t_last_ate = timestamp();
	sem_post(args->ate_check);
	event_skip_time(args->time_eat, args);
	(ph->ate_times)++;
	sem_post(args->forks);
	sem_post(args->forks);
}

static void	*ft_death(void *philo_void)
{
	t_philosopher	*ph;
	t_args			*args;

	ph = (t_philosopher *)philo_void;
	args = ph->args;
	while (1)
	{
		sem_wait(args->ate_check);
		if (time_diff(ph->t_last_ate, timestamp()) > args->time_death)
		{
			ft_print_of_actions(args, ph->ph_id, "died");
			args->died = 1;
			sem_wait(args->writing);
			exit(1);
		}
		sem_post(args->ate_check);
		if (args->died)
			break ;
		usleep(1000);
		if (ph->ate_times >= args->eat_count && args->eat_count != -1)
			break ;
	}
	return (NULL);
}

static void	ph_process(void *philo_void)
{
	t_philosopher	*ph;
	t_args			*args;

	ph = (t_philosopher *)philo_void;
	args = ph->args;
	ph->t_last_ate = args->first_timestamp;
	pthread_create(&(ph->death_thread), NULL, ft_death, philo_void);
	if (ph->ph_id % 2)
		usleep(250);
	while (!(args->died))
	{
		ph_eating(ph);
		if (ph->ate_times >= args->eat_count && args->eat_count != -1)
			break ;
		ft_print_of_actions(args, ph->ph_id, "is sleeping");
		event_skip_time(args->time_sleep, args);
		ft_print_of_actions(args, ph->ph_id, "is thinking");
	}
	pthread_join(ph->death_thread, NULL);
	if (args->died)
		exit(1);
	exit(0);
}

int	ft_start(t_args *args)
{
	int				i;
	t_philosopher	*ph;

	i = -1;
	ph = args->philosophers;
	args->first_timestamp = timestamp();
	while (++i < args->philo_count)
	{
		ph[i].proc_id = fork();
		if (ph[i].proc_id < 0)
			return (1);
		if (ph[i].proc_id == 0)
			ph_process(&(ph[i]));
		usleep(100);
	}
	ft_exit(args);
	return (0);
}
