# include "../includes/philo.h"

int	is_time_to_die(t_philo *philo, int index)
{
	long	current_time;
	long	diff;

	pthread_mutex_lock(&philo->args->mutexes.meal);
	current_time = ft_time();
	diff = current_time - philo[index].last_meal;
	pthread_mutex_unlock(&philo->args->mutexes.meal);
	return (diff > philo->args->time_to_die);
}

void	mark_philosopher_as_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->mutexes.death);
	philo->is_dead = 1;
	pthread_mutex_unlock(&philo->args->mutexes.death);
}

void	print_philosopher_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->mutexes.print_message);
	printf("%ld %d died\n", (ft_time() - philo->args->start_time),
		philo->id);
	pthread_mutex_unlock(&philo->args->mutexes.print_message);
}

int	check_philosopher_death(t_philo *philo, int index)
{
	if (is_time_to_die(philo, index))
	{
		mark_philosopher_as_dead(philo);
		print_philosopher_death(philo);
		return (1);
	}
	return (0);
}

int	is_philosopher_dead(t_philo *philo)
{
	int	i;
	int	is_dead;

	is_dead = 0;
	pthread_mutex_lock(&philo->args->mutexes.death);
	is_dead = philo->is_dead;
	pthread_mutex_unlock(&philo->args->mutexes.death);
	if (is_dead)
		return (1);
	i = 0;
	while (i < philo->args->num_of_philosophers)
	{
		if (check_philosopher_death(philo, i))
			return (1);
		i++;
	}
	return (0);
}
