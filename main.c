/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouregb <abouregb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:37:48 by abouregb          #+#    #+#             */
/*   Updated: 2023/08/23 13:13:32 by abouregb         ###   ########.fr       */
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
			{
				printf("Erorr.\n");
				exit(1);
			}
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		return(printf("data !..."), 1);
	if (ac > 6 || ac < 5)
		return (printf("to few argument  ..."), 1);
	ft_parcer(av, ac);
	ft_init(ac, av, data);
}
