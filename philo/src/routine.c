/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylr <ylr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:43:07 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/13 15:38:29 by ylr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/philo.h"

void    print_status(t_philo *philo, char *msg)
{
    pthread_mutex_lock(&philo->args->mutexes.print_message);
    printf("%ld %d %s\n", ft_time() - philo->args->start_time, philo->id ,msg);
    pthread_mutex_unlock(&philo->args->mutexes.print_message);
}

void    eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_fork);
    print_status(philo, "has taken left fork");
    pthread_mutex_lock(&philo->right_fork);
    print_status(philo, "has taken right fork");
    pthread_mutex_lock(&philo->args->mutexes.meal);
    print_status(philo, "is eating");
    philo->last_meal = ft_time();
    usleep(philo->args->time_to_eat);
    philo->nbr_of_meal_has_eaten++;
    pthread_mutex_unlock(&philo->args->mutexes.meal);
    pthread_mutex_unlock(&philo->left_fork);
    pthread_mutex_unlock(&philo->right_fork);
}

void    *routine(void *philo)
{
    t_philo *philosophers;

    philosophers = (t_philo *) philo;
    if (philosophers->id % 2)
        usleep((philosophers->args->time_to_eat / 2) * 100);
    while (1)
    {
		// take_forks(philosophers);
		eating(philosophers);
		print_status(philo, "is sleeping");
        ft_usleep(philosophers->args->time_to_sleep);
        print_status(philosophers, "is thinking");
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