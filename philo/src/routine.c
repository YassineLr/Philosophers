/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:43:07 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/17 02:25:44 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void    print_status(t_philo *philo, char *msg)
{
    pthread_mutex_lock(&philo->args->print_msg);
    printf("%ld ms %d %s\n", ft_time() - philo->args->start_time, philo->id ,msg);
    pthread_mutex_unlock(&philo->args->print_msg);
}

void    eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->args->forks[philo->id - 1]);
	print_status(philo , "has taken left fork");
	pthread_mutex_lock(&philo->args->forks[philo->id % philo->args->num_of_philosophers]);
	print_status(philo , "has taken right fork");
    print_status(philo, "is eating");
    pthread_mutex_lock(&philo->args->death);
    philo->last_meal = ft_time();
    pthread_mutex_unlock(&philo->args->death);
    pthread_mutex_lock(&philo->args->meal);
    philo->nbr_of_meal_has_eaten++;
    pthread_mutex_unlock(&philo->args->meal);
    ft_usleep(philo->args->time_to_eat);
    pthread_mutex_unlock(&philo->args->forks[philo->id - 1]);
    pthread_mutex_unlock(&philo->args->forks[philo->id% philo->args->num_of_philosophers]);
}

void    *routine(void *philo)
{
    t_philo *philosophers;

    philosophers = (t_philo *) philo;
    if (philosophers->id % 2)
        usleep(1000);
    while (1)
    {
		eating(philosophers);
		print_status(philo, "is sleeping");
        ft_usleep(philosophers->args->time_to_sleep);
        print_status(philosophers, "is thinking");
    }
    return (NULL);
}

// int check_dead(t_philo *philo)
// {
//     if(philo->nbr_of_meal_has_eaten >= philo->args->nofm_to_eat)
//         return (1);
//     if(ft_time() - philo->last_meal >= philo->args->time_to_die)
//         return (1);
//     return (0);
// }