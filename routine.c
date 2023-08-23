/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:19:39 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/23 21:22:52 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message(char *msg, t_philo *philo)
{
	long long	now;

	now = get_time();
	pthread_mutex_lock(&philo->data->write);
	printf("%lld %d %s\n", now - philo->data->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->write);
}

void	eating(t_philo *philo, long long start)
{
	pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	message("has taken a fork", philo);
	pthread_mutex_lock(&philo->data->forks[(philo->id)
		% philo->data->philo_num]);
	pthread_mutex_lock(&philo->data->m_eating);
	philo->eating++;
	pthread_mutex_unlock(&philo->data->m_eating);
	message("has taken a fork", philo);
	message("is eating", philo);
	pthread_mutex_lock(&philo->data->m_last);
	philo->last_time = get_time();
	pthread_mutex_unlock(&philo->data->m_last);
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
	long long	start;
	t_philo		*philo;

	start = get_time();
	philo = arg;
	if (philo->id % 2 == 0)
		ft_usleep(50);
	while (1)
		eating(philo, start);
	return (NULL);
}

int	cheak_meals(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->data->m_eating);
	if (philo[i].eating > philo->data->meals_nb
		&& philo->data->meals_nb > 0)
	{
		pthread_mutex_unlock(&philo->data->m_eating);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->m_eating);
	return (1);
}

int	check_if_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < philo->data->philo_num)
		{
			pthread_mutex_lock(&philo->data->m_last);
			if ((get_time() - philo[i].last_time) > philo->data->death_time)
			{
				printf("%lld %d Die\n", get_time() - philo[i].last_time,
					philo[i].id);
				pthread_mutex_unlock(&philo->data->m_last);
				pthread_mutex_lock(&philo->data->write);
				return (1);
			}
			pthread_mutex_unlock(&philo->data->m_last);
			if (!cheak_meals(philo, i))
				return (1);
			i++;
		}
	}
	return (0);
}
