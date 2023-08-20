/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:38:14 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/20 19:05:11 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

struct s_data	data;
typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	int				eat_cont;
	int				eating;//how many time he eat ?
	long long		time_to_die;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_num;
	int				meals_nb;
	int				die;
	long long		death_time;
	long long		eat_time;
	long long		sleep_time;
	long long		start_time;
	pthread_mutex_t	*forks;//?mutexess
	pthread_mutex_t	write;//when i want to write something..
	pthread_mutex_t	lock;//when i have the both forks..
}	t_data;

void		ft_init(int ac, char **av, t_data *data);
int			ft_isdigit(char c);
void		*routine(void *arg);
long long   get_time(void);
void		ft_usleep(useconds_t time);
int			ft_to_int(char *str);
#endif