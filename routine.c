/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:19:39 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/22 22:07:11 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(char *msg, t_philo *philo)
{
	//? philo ???
	long long now;
	now = get_time();
	pthread_mutex_lock(&philo->data->write);//
	printf("%lld %d %s\n", now - philo->data->start_time,  philo->id, msg);
	//if(msg[1] != 'd')
		pthread_mutex_unlock(&philo->data->write);
}

void eating(t_philo *philo, long long start)
{
	
	// start = philo->data->start_time;
	pthread_mutex_lock(philo->m_last_time);
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	message("has taken a fork", philo);
	pthread_mutex_lock(&philo->data->forks[(philo->id ) % philo->data->philo_num]);
	message("has taken a fork", philo);
	message("is eating", philo);
	ft_usleep(philo->data->eat_time);
	philo->last_time = get_time();
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->forks[(philo->id ) % philo->data->philo_num]);
	message("is sleeping", philo);
	ft_usleep(philo->data->sleep_time);
	message("is thinking", philo);
}

void	*routine(void *arg)
{
	long long start;
	t_philo *philo;

	start = get_time();
	philo = arg;
	if(philo->id % 2 == 0)
		ft_usleep(200);
	
	while(1)
		eating(philo, start);
	return(NULL);
}
int check_if_death(t_philo *philo)
{
	int i;
	i = 0;
	while (1)
	{
		i = 0;
		while(i < philo->data->philo_num)
		{
			if ((get_time() - philo[i].last_time) > philo->data->death_time)
			{
					printf("%lld %d Die\n", get_time() - philo[i].last_time,
					philo[i].id );
					pthread_mutex_lock(&philo->data->write);
				return(1);
			}
			if(philo[i].eating >= philo->data->meals_nb && philo->data->meals_nb > 0)
			{
				return 1;
			}
			i++;
		}
	}
	return(0);
}

