#include "../includes/philo.h"

long	ft_time(void)
{
	struct timeval	current_time;
	long			time_in_ms;

	gettimeofday(&current_time, NULL);
	time_in_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (time_in_ms);
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