/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:55:25 by ylarhris          #+#    #+#             */
/*   Updated: 2023/08/25 18:09:57 by ylarhris         ###   ########.fr       */
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
        philos[i].id = i+1;
        philos[i].args = args;
        i++;
    }
    return(philos);
}

void *fun(void *philo)
{
	t_philo *philosopher;
	philosopher = (t_philo*) philo;
	pthread_mutex_lock(&philosopher->args->mutexes.lock);
	printf("hello i'm the philo %d and i was created in %ld\n", philosopher->id, ft_time() - philosopher->args->start_time);
	pthread_mutex_unlock(&philosopher->args->mutexes.lock);
	return(NULL);
}

void	start_philos(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->num_of_philosophers)
	{
		pthread_create(&philo[i].thread_id, NULL, &fun, &philo[i]);
		usleep(1000);
		pthread_detach(philo[i].thread_id);
		i++;
	}
}
