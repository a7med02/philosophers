/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:18:59 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/25 11:38:29 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philos(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	if (0 != pthread_mutex_init(&data->m_eating, NULL))
		return (printf("mutex eating!\n"), 1);
	if (0 != pthread_mutex_init(&data->m_last, NULL))
		return (printf("mutex last eat!\n"), 1);
	while (++i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, routine, &philo[i]) != 0)
			return (printf("mutex creat!\n"), 1);
		if (pthread_detach(data->tid[i]) != 0)
			return (printf("mutex detach!\n"), 1);
	}
	check_if_death(philo);
	return (0);
}

int	init_philos(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = -1;
	data->tid = malloc(sizeof(pthread_t) * data->philo_num);
	if (!data->tid)
		return (printf("tid !\n"), 1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
		return (printf("forks !\n"), 1);
	philo = malloc(sizeof(t_philo) * data->philo_num);
	if (!philo)
		return (printf("philo !\n"), 1);
	while (++i < data->philo_num)
	{
		philo[i].id = i + 1;
		philo[i].last_time = get_time();
		philo[i].eating = 0;
		data->start_time = get_time();
		if (0 != pthread_mutex_init(&data->forks[i], NULL))
			return (printf("mutex fork!\n"), 1);
		philo[i].data = data;
	}
	start_philos(data, philo);
	return (0);
}

int	ft_init(int ac, char **av, t_data *data)
{
	if (ac == 6)
		data->meals_nb = ft_to_int(av[5]);
	else
		data->meals_nb = -1;
	data->philo_num = ft_to_int(av[1]);
	data->death_time = (long long)ft_to_int(av[2]);
	data->eat_time = (long long)ft_to_int(av[3]);
	data->sleep_time = (long long)ft_to_int(av[4]);
	if (0 != (pthread_mutex_init(&data->write, NULL)))
		return (printf("mutex !\n"), 1);
	init_philos(data);
	return (0);
}
