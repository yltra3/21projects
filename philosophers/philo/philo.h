/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:35:35 by clornel           #+#    #+#             */
/*   Updated: 2022/04/22 17:35:37 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philosopher
{
	int				left_fork_id;
	int				right_fork_id;
	int				ph_id;
	int				ate_times;
	long long		t_last_ate;
	struct s_args	*args;
	pthread_t		thread_id;
}				t_philosopher;

typedef struct s_args
{
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					philo_count;
	int					eat_count;
	int					died;
	int					evrybdy_ate;
	long long			first_timestamp;
	pthread_mutex_t		eating_mutex;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		writing;
	t_philosopher		philosophers[250];
}						t_args;

long long	timestamp(void);
int			ft_atoi(const char *str);
int			ft_values_init(t_args *args, char **av);
long long	time_diff(long long past, long long pres);
void		event_skip_time(long long time, t_args *args);
void		ft_print_of_actions(t_args *args, int id, char *str);
int			ft_start(t_args *args);

#endif