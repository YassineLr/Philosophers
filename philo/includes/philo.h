/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:48:38 by ylarhris          #+#    #+#             */
/*   Updated: 2023/08/27 03:31:21 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_mutexes
{
	pthread_mutex_t	*forks;
	pthread_mutex_t print_message;
	pthread_mutex_t death;
	// pthread_mutex_t lock;
	pthread_mutex_t meal;
}					t_mutexes;

typedef struct s_args
{
	int				num_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nofm_to_eat;
	long			start_time;
	t_mutexes		mutexes;
}					t_args;


typedef struct s_philo
{
	int			id;
	long		last_meal;
	int			nbr_of_meal_has_eaten;
	t_args		*args;
	pthread_t 	thread_id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}					t_philo;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int	    ft_atoi(const char *s);
void	ft_bzero(void *s, size_t n);	
void	*ft_calloc(size_t count, size_t size);
int	    ft_isalnum(int c);
int	    ft_isalpha(int c);
int	    ft_isdigit(int c);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	**ft_split(char *str, char sep);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

long		ft_time(void);
t_args		*args_handler(int ac, char **av);
t_philo     *init_philos(t_args *args);
void		start_philos(t_philo *philo);
void    print_status(t_philo *philo, char *msg);
void    take_forks(t_philo  *philo);
void    eating(t_philo *philo);
void    *routine(void *philo);

#endif