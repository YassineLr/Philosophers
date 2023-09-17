/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:11:40 by ylarhris          #+#    #+#             */
/*   Updated: 2023/09/17 03:31:18 by ylarhris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int ac, char **av)
{
    t_args *args;
    t_philo    *philos;
    
    args = args_handler(ac, av);
    if(!args)
        return 1;
    init_mutexes(args);
    philos = init_philos(args);
    start_philos(philos);
    if(check_death(philos) == 0)
        return 0;
    if(join_destroy(philos))
        return 0;
    return 0;
}