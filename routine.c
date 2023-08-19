/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:19:39 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/19 18:35:56 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
    t_philo *philo;
    philo = arg;
    if(philo->id % 2)
        usleep(500);
    printf("die : %d\n", philo->data->sleep_time);
    printf("hello : %d\n", philo->id);
    return(NULL);
}