/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:19:39 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/25 22:59:07 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(char *msg, t_philo *philo)
{
	long long	now;

	now = get_time();
	pthread_mutex_lock(&philo->data->write);
	printf("%lld %d %s\n", now - philo->data->start_time, philo->id, msg);
	if (msg[0] == 'd')
		return ;
	pthread_mutex_unlock(&philo->data->write);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	message("has taken a fork", philo);
	pthread_mutex_lock(&philo->data->forks[(philo->id)
		% philo->data->philo_num]);
	pthread_mutex_lock(&philo->data->access);
	philo->eating++;
	pthread_mutex_unlock(&philo->data->access);
	message("has taken a fork", philo);
	message("is eating", philo);
	pthread_mutex_lock(&philo->data->access);
	philo->last_time = get_time();
	pthread_mutex_unlock(&philo->data->access);
	ft_usleep(philo->data->eat_time);
	pthread_mutex_unlock(&philo->data->forks[(philo->id)
		% philo->data->philo_num]);
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	message("is sleeping", philo);
	ft_usleep(philo->data->sleep_time);
	message("is thinking", philo);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = arg;
	if (philo->id % 2 == 0)
		ft_usleep(50);
	while (1)
		eating(philo);
	return (NULL);
}

void	cheak_meals(t_philo *philo, int i)
{
	if (philo[i].eating > philo->data->meals_nb
		&& philo->data->meals_nb > 0)
	{
		philo->data->philos_eat++;
	}
}

int	check_if_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		pthread_mutex_lock(&philo->data->access);
		while (i < philo->data->philo_num)
		{
			if ((get_time() - philo[i].last_time) > philo->data->death_time)
			{
				message("died", philo);
				return (1);
			}
			cheak_meals(philo, i);
			if (philo->data->philos_eat >= philo->data->philo_num)
				return (1);
			i++;
		}
		pthread_mutex_unlock(&philo->data->access);
		usleep(1000);
	}
	return (0);
}
