/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:18:59 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/23 11:29:43 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philos(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, routine, &philo[i]) == -1)
			return ;
		pthread_detach(data->tid[i]);
	}
	check_if_death(philo);
}

int	init_philos(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = -1;
	if (!(data->tid	= malloc(sizeof(pthread_t) * data->philo_num)))
		return (1);
	if (!(data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num)))
		return (1);
	if (!(philo = malloc(sizeof(t_philo) * data->philo_num)))
		return (1);
	while (++i < data->philo_num)
	{
		philo[i].id = i + 1;
		philo[i].last_time = get_time();
		philo[i].eat_cont = 0;
		philo[i].eating = 0;
		data->start_time = get_time();
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&philo[i].m_eat, NULL);
		pthread_mutex_init(&philo[i].m_last_time, NULL);
		philo[i].data = data;
	}
	pthread_mutex_init(&data->m_eating, NULL);
	pthread_mutex_init(&data->m_last, NULL);
	start_philos(data, philo);
	return (0);
}

int	init_arg(int ac, char **av, t_data *data)
{
	if (ac == 6)
		data->meals_nb = ft_to_int(av[5]);
	else
		data->meals_nb = -1;
	data->philo_num = ft_to_int(av[1]);
	data->death_time = (long long)ft_to_int(av[2]);
	data->eat_time = (long long)ft_to_int(av[3]);
	data->sleep_time = (long long)ft_to_int(av[4]);
	data->die = 0;
	if (data->philo_num <= 0 || data->philo_num > 200 || data->death_time < 0
		|| data->eat_time < 0 || data->sleep_time < 0)
		return (1);
	pthread_mutex_init(&data->write, NULL);
	init_philos(data);
	return (0);
}

void	ft_init(int ac, char **av, t_data *data)
{
	init_arg(ac, av, data);
}
