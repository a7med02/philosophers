/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:37:48 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/25 22:58:18 by abouregb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	ft_parcer(char **av, int ac)
{
	int	k;
	int	i;

	i = 1;
	while (i < ac)
	{
		k = 0;
		while (av[i][k])
		{
			if ((ft_isdigit(av[i][k]) || av[i][k] == 32) && av[i][0] != 48)
				k++;
			else
				return (printf("Erorr.\n"), -1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("data !..."), 1);
	if (ac > 6 || ac < 5)
		return (free(data), printf("to few argument  ..."), 1);
	if (ft_parcer(av, ac) == -1)
		return (0);
	ft_init(ac, av, data);
	free(data->forks);
	free(data->tid);
	free(data);
}
