/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylr <ylr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:55:25 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/13 15:27:26 by ylr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo        *init_philos(t_args *args)
{
    int         i;
    t_philo     *philos;

    i = 0;
    philos = (t_philo *) malloc (args->num_of_philosophers * sizeof(t_philo));
    while (i < args->num_of_philosophers)
    {
        pthread_mutex_init(&args->mutexes.forks[i], NULL);
        philos[i].id = i+1;
        philos[i].is_dead = 0;
        philos[i].args = args;
        philos[i].right_fork = args->mutexes.forks[i];
        philos[i].left_fork = args->mutexes.forks[(i+1)%args->num_of_philosophers];
        i++;
    }
    return(philos);
}

void	start_philos(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->num_of_philosophers)
	{
		pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i]);
		usleep(1000); 		
		pthread_detach(philo[i].thread_id);
		i++;
	}
}
