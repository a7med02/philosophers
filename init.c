/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:18:59 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/19 18:57:23 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void start_philos(t_data *data, t_philo *philo)
{
    int i = -1;
    while(++i < data->philo_num)
        pthread_create(&data->tid[i], NULL, routine, &philo[i]);
    i = -1;
    while(++i < data->philo_num)
        pthread_join(data->tid[i], NULL);

}
int init_philos(t_data *data, t_philo *philo)
{
    int i;
    i = 0;
    // philo = philo
    if(!(data->tid = malloc(sizeof(pthread_t) * data->philo_num)))
        return(1);
    if(!(data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num)))
        return(1);
    if(!(philo = malloc(sizeof(pthread_mutex_t) * data->philo_num)))
        return(1);
    
    while(i < data->philo_num)
    {
        philo[i].data = data;
        philo[i].id = i+ 1;
        philo[i].time_to_die = data->death_time;
        philo[i].eat_cont = 0;
        philo[i].eating = 0;
        
        pthread_mutex_init(&data->lock, NULL);
        pthread_mutex_init(&data->forks[i++], NULL);
    }
    i = 0;
    philo[0].l_fork = &data->forks[0];
    philo[0].r_fork = &data->forks[data->philo_num -1];
    i += 1;
    while(i < data->philo_num)
    {
        philo[i].l_fork = &data->forks[i];
        philo[i].r_fork = &data->forks[i-1];
        i++;
    }
    start_philos(data, philo);
    return(0);
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
    data->die = 0;
    if (data->philo_num <= 0 || data->philo_num > 200 || data->death_time < 0
		|| data->eat_time < 0 || data->sleep_time < 0)
		return (1);
    pthread_mutex_init(&data->lock, NULL);
    pthread_mutex_init(&data->write, NULL);
    return(0);
}

void ft_init(int ac, char **av, t_data *data, t_philo *philo)
{
    init_arg(ac , av, data);
    init_philos(data, philo);
}