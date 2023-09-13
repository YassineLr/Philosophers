/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylr <ylr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:11:35 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/13 08:41:39 by ylr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


int			number_of_philo_handler(char *str)
{
	int nop;
	
	nop = ft_atoi(str);
	if(nop < 0)
	{
		ft_putstr_fd("Invalid number of philosophers !\n",2);
		return (0);
	}
	return (nop);
}

void	ft_usleep(int sleep_time)
{
	long	current_time;

	current_time = ft_time();
	usleep(sleep_time * 1000 * 0.9);
	while (ft_time() - current_time < sleep_time)
		usleep(30);
}

int			time_handler(char *str)
{
	int time;
	
	time = ft_atoi(str);
	if(time < 0)
	{
		ft_putstr_fd("Invalid time !\n",2);
		return(0);
	}
	return(time);
}

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
	args->mutexes.forks = malloc(sizeof(pthread_mutex_t) * args->num_of_philosophers);
	if(!check_args(args, ac))
		return (0);
	return (args);
}
