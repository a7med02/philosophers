/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:40:05 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/21 08:03:12 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return ((tv.tv_sec * (long long)1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(useconds_t time)
{
	long long	now;

	now = get_time();
	while (get_time() - now < time)
		usleep(time / 10);
}

void	ft_exit(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->philo_num)
	{
		pthread_mutex_destroy(&philo->data->forks[i]);
	}
	pthread_mutex_destroy(&philo->data->write);
}

int	ft_to_int(char *str)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
		r = r *10 + (str[i++] - 48);
	return (r);
}
