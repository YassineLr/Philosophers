/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:55:25 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/17 02:39:11 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void		init_mutexes(t_args *args)
{
	int i;
	
	i = 0;
	while (i < args->num_of_philosophers)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&args->death, NULL);
	pthread_mutex_init(&args->meal, NULL);
	pthread_mutex_init(&args->print_msg, NULL);
}

t_philo        *init_philos(t_args *args)
{
    int         i;
    t_philo     *philos;

    i = 0;
    philos = (t_philo *) malloc (args->num_of_philosophers * sizeof(t_philo));
    while (i < args->num_of_philosophers)
    {
        philos[i].args = args;
        philos[i].id = i+1;
        philos[i].is_dead = 0;
		philos[i].last_meal = ft_time();
		philos->nbr_of_meal_has_eaten = 0;
        i++;
    }
    return(philos);
}

int	join_destroy(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->num_of_philosophers)
	{
		if (pthread_join(philo[i].id, NULL))
			return (1);
		i++;
	}
	i = 0;
	while (i < philo->args->num_of_philosophers)
	{
		if (pthread_mutex_destroy(&philo->args->forks[i]))
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&philo->args->print_msg))
		return (1);
	if (pthread_mutex_destroy(&philo->args->death))
		return (1);
	if (pthread_mutex_destroy(&philo->args->meal))
		return (1);
	return (0);
}

void	start_philos(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->num_of_philosophers)
	{
		pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i]);
		i++;
	}
}
