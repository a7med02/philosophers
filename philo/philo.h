/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:38:14 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/25 22:59:25 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_nb;
	long long		death_time;
	long long		eat_time;
	long long		sleep_time;
	long long		start_time;
	int				philos_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	access;
}	t_data;

typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	int				eat_cont;
	int				eating;
	long long		last_time;
}	t_philo;

int			ft_init(int ac, char **av, t_data *data);
int			ft_isdigit(char c);
void		*routine(void *arg);
long long	get_time(void);
void		ft_usleep(useconds_t time);
int			ft_to_int(char *str);
int			check_if_death(t_philo *philo);
void		clean_up(t_philo *philo);
#endif
