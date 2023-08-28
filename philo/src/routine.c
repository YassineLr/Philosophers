/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:43:07 by ylarhris          #+#    #+#             */
/*   Updated: 2023/08/27 03:46:07 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void    print_status(t_philo *philo, char *msg)
{
    pthread_mutex_lock(&philo->args->mutexes.print_message);
    printf("%ld %d %s\n", ft_time() - philo->args->start_time, philo->id ,msg);
    pthread_mutex_unlock(&philo->args->mutexes.print_message);
}


void    take_forks(t_philo  *philo)
{
    pthread_mutex_lock(&philo->left_fork);
    print_status(philo, "has taken a fork");
    pthread_mutex_lock(&philo->right_fork);
    print_status(philo, "has taken a fork");
}

void    eating(t_philo *philo)
{
    print_status(philo, "is eating");
    pthread_mutex_lock(&philo->args->mutexes.meal);
    philo->last_meal = ft_time();
    pthread_mutex_unlock(&philo->args->mutexes.meal);
    usleep(philo->args->time_to_eat);
    pthread_mutex_lock(&philo->args->mutexes.meal);
    philo->nbr_of_meal_has_eaten++;
    pthread_mutex_unlock(&philo->args->mutexes.meal);
    pthread_mutex_unlock(&philo->left_fork);
    pthread_mutex_unlock(&philo->right_fork);
}

void    *routine(void *philo)
{
    t_philo *philosopher;

    philosopher = (t_philo *) philo;
    if (philosopher->id % 2)
        usleep(1000);
    while (1)
    {
        print_status(philosopher, "is thinking");
		take_forks(philosopher);
		eating(philosopher);
		print_status(philo, "is sleeping");
        usleep(1000);
    }
}

// int check_dead(t_philo *philo)
// {
//     if(philo->nbr_of_meal_has_eaten >= philo->args->nofm_to_eat)
//         return (1);
//     if(ft_time() - philo->last_meal >= philo->args->time_to_die)
//         return (1);
//     return (0);
// }