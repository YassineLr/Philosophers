#include "../includes/philo.h"

t_philo        *init_philos(t_args *args)
{
    int         i;
    t_philo     *philos;

    i = 0;
    philos = (t_philo *) malloc (args->num_of_philosophers * sizeof(t_philo));
    while (i < args->num_of_philosophers)
    {
        philos[i].id = i+1;
        philos[i].args = args;
        i++;
    }
    return(philos);
}