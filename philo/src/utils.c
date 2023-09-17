/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:11:35 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/17 01:27:33 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


int		check_args(t_args *args, int ac)
{
	if (args->num_of_philosophers <= 0)
	{
		ft_putstr_fd("Invalid number of philosophers !\n", 2);
		return (0);
	}
	if(args->time_to_die <= 0 || args->time_to_eat <= 0
		|| args->time_to_sleep <= 0)
	{
		ft_putstr_fd("Invalid Time !\n",2);
		return (0);
	}
	if(ac == 6 && args->nofm_to_eat <= 0)
	{
		ft_putstr_fd("Invalid number of meals !\n", 2);
		return (0);
	}
	return (1);
}

t_args		*args_handler(int ac, char **av)
{
	t_args	*args;

	if(ac < 5 || ac > 6)
	{
		ft_putstr_fd("Invalid number of arguments !\n", 2);
		return(NULL);
	}
	args = (t_args *)malloc(sizeof(t_args));
	if(!args)
		return (NULL);
	args->num_of_philosophers = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->start_time = ft_time();
	if(av[5])
		args->nofm_to_eat = ft_atoi(av[5]);
	else
		args->nofm_to_eat = -1;
	if(!check_args(args, ac))
		return (0);
	args->forks = calloc(args->num_of_philosophers, sizeof(pthread_mutex_t));
	return (args);
}
