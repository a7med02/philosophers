/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:19:39 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/20 19:40:45 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(char *msg, t_philo *philo, long long time)
{
	//? philo ???
	long now;
	now = get_time();
	pthread_mutex_lock(&philo->data->write);
	printf("%lld %d %s\n", now - time,  philo->id, msg);
	pthread_mutex_unlock(&philo->data->write);
}
void passe_time(t_philo *philo)
{
	long long start;
	start = get_time();
	// ft_usleep(start);
	ft_usleep(500 * 1000);
}
void eating(t_philo *philo, long long start)
{
	start = philo->data->start_time;  
	pthread_mutex_lock(&philo->data->lock);//?
	pthread_mutex_lock(philo->l_fork);
	message("has taken a fork\n", philo, start);
	pthread_mutex_lock(philo->r_fork);
	message("has taken a fork\n", philo, start);
	message("is eating\n", philo, start);
	pthread_mutex_unlock(&philo->data->lock);//?
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	ft_usleep(philo->data->sleep_time);
	message("is sleeping\n", philo, start);
	message("is thinking\n", philo, start);
	passe_time(philo);
	
}

void	*routine(void *arg)
{
	long long start;
	t_philo *philo;

	start = get_time();
	philo = arg;
	if(philo->id % 2 == 0)
		ft_usleep(200);
	while(!philo->data->die)
		eating(philo, start);
	return(NULL);
}
