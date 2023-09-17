#include "../includes/philo.h"

long	ft_time(void)
{
	struct timeval	current_time;
	long			time_in_ms;

	gettimeofday(&current_time, NULL);
	time_in_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (time_in_ms);
}

void	ft_usleep(int time)
{
	long	start_time;
	long	end_time;

	start_time = ft_time();
	usleep(time * 1000);
	end_time = ft_time();
	if (end_time - start_time < time)
		usleep((time - (end_time - start_time)) * 1000);
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