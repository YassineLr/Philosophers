/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 08:48:38 by ylarhris          #+#    #+#             */
/*   Updated: 2023/08/21 10:49:58 by ylarhris         ###   ########.fr       */
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

typedef struct s_args
{
	int				num_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nofm_to_eat;
}					t_args;


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

t_args		*args_handler(int ac, char **av);

#endif