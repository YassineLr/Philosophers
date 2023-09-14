/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylr <ylr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:11:40 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/13 15:01:09 by ylr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int ac, char **av)
{
    t_args *args;
    t_philo    *philos;
    
    args = args_handler(ac, av);
    if(!args)
        return 0;
    philos = init_philos(args);
    start_philos(philos);
    while (1)
	{
		if (is_philosopher_dead(philos))
			return (1);
	}
}