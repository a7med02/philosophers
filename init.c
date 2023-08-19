/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:18:59 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/19 17:58:43 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_philos(t_data *data)
{
    int i;
    i = 0;
    if(!(data->tid = malloc(sizeof(pthread_t) * data->philo_num)))
        return(1);
    if(!(data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num)))
        return(1);
    if(!(data->philos = malloc(sizeof(t_philo) * data->philo_num)))
        return(1);
    while(i < data->philo_num)
    {
        data->philos[i].id = i+ 1;
        data->philos[i].time_to_die = data->death_time;
        data->philos[i].eat_cont = 0;
        data->philos[i].eating = 0;
        pthread_mutex_init(&data->lock, NULL);
        pthread_mutex_init(&data->forks[i++], NULL);
    }
    i = 0;
    data->philos[0].l_fork = &data->forks[0];
    data->philos[0].r_fork = &data->forks[data->philo_num -1];
    i += 1;
    while(i < data->philo_num)
    {
        data->philos[i].l_fork = &data->forks[i];
        data->philos[i].r_fork = &data->forks[i-1];
        i++;
    }
    pthread_join(data->tid[i], NULL);
    return(0);
}
void start_philos(t_data *data)
{
    int i = -1;
    while(++i < data->philo_num)
        pthread_create(&data->tid[i], NULL, routine, &data->philos[i]);
    i = -1;
    while(++i < data->philo_num)
        pthread_join(data->tid[i], NULL);

}

int init_arg(int ac , char **av, t_data *data)
{
    if(ac == 6)
        data->meals_nb = atoi(av[5]);
    else
        data->meals_nb = -1;
    data->philo_num = atoi(av[1]);
    data->death_time = (int)atoi(av[2]);
    data->eat_time = (int)atoi(av[3]);
    data->sleep_time = (int)atoi(av[4]);
    if (data->philo_num <= 0 || data->philo_num > 200 || data->death_time < 0
		|| data->eat_time < 0 || data->sleep_time < 0)
		return (1);
    pthread_mutex_init(&data->lock, NULL);
    pthread_mutex_init(&data->write, NULL);
    return(0);
}

void ft_init(int ac, char **av, t_data *data)
{
    init_arg(ac , av, data);
    init_philos(data);
    start_philos(data);
}