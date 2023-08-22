/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylr <ylr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:11:40 by ylarhris          #+#    #+#             */
/*   Updated: 2023/08/22 11:03:15 by ylr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void    print_args(t_args *args)
{
    printf("Number of philos : %d\n", args->num_of_philosophers);
    printf("Time to die : %d\n", args->time_to_die);
    printf("Time to eat : %d\n", args->time_to_eat);
    printf("Time to sleep : %d\n", args->time_to_sleep);
    printf("Number of meals to eat : %d\n", args->nofm_to_eat);

}

int main(int ac, char **av)
{
    t_args *args;
    t_philo    *philos;
    
    args = args_handler(ac, av);
    // if(args)
    //     print_args(args);
    // int i = 0;
    philos = init_philos(args);
    // while (i < args->num_of_philosophers)
    // {
    //     printf("id = %d\n",philos[i].id);
    //     // printf("thread id = %ld\n",philos[i].thread_id);
    //     print_args(philos[i].args);
    //     i++;
    // }
    start_philos(philos);
}