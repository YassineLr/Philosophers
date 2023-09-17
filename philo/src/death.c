/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:01:02 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/17 03:31:27 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

int	has_eaten_enough(t_philo *philo)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	pthread_mutex_lock(&philo->args->meal);
	while (i < philo->args->num_of_philosophers)
	{
		if (philo->args->nofm_to_eat != -1
			&& philo[i].nbr_of_meal_has_eaten >= philo->args->nofm_to_eat)
			count++;
		i++;
	}
	if (count >= philo->args->num_of_philosophers)
	{
		pthread_mutex_unlock(&philo->args->meal);
		return (1);
	}
	pthread_mutex_unlock(&philo->args->meal);
	return (0);
}

int	check_death(t_philo *philo)
{
	int i;

	while (philo->is_dead == 0)
	{
		i = 0;
		while (i < philo->args->num_of_philosophers)
		{
			pthread_mutex_lock(&philo->args->death);
			if (ft_time() - philo[i].last_meal >= philo->args->time_to_die )
			{
				philo->is_dead = 1;
				print_status(philo, "is died");
				return(0);
			}
			if(has_eaten_enough(philo) == 1)
				return 0 ;
			pthread_mutex_unlock(&philo->args->death);
			i++;
		}
	}
	return(1);
}
