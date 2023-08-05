/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:38:14 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/04 17:06:28 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_nb;
	int				dead;
	int				finished;
	// t_philo			*philos;
	int		death_time;
	int		eat_time;
	int		sleep_time;
	int		start_time;
	pthread_mutex_t	*forks;//?mutexess
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

typedef struct s_philo
{
	struct s_data	data;
	pthread_t		t1;
	int				id;
	int				eat_cont;
	int				status;
	int				eating;
	int			time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;


void ft_init(int ac, char **av, t_data data);
int ft_isdigit(char c);
#endif