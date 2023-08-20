#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
/*
    create a thread that calcule the sum of a table 
*/

void    *task(void *tab)
{
    int *table;
    int sum = 0;
    
    printf("Im inside the thread\n");
    table = (int *)tab;
    for(int i = 1; i <= table[0]; i++)
        sum+=table[i];
    printf("%d\n", sum);
}

int main(int ac, char **av)
{
    pthread_t threads;
    int         *tab;

    tab = malloc((ac)*sizeof(int));
    tab[0] = ac - 1;
    for(int i = 1; i < ac ; i++)
        tab[i] = atoi(av[i]);
    // The pthread_create() function starts a new thread in the calling process.
    if(pthread_create(&threads, NULL, task, tab))
        perror("");
    /* 
        The pthread_detach() function is used to indicate to the implementation that 
        storage for the thread thread can be reclaimed when that thread terminates. 
        If thread has not terminated, pthread_detach() will not cause it to terminate. 
        The effect of multiple pthread_detach() calls on the same target thread is unspecified.
    */
    if (pthread_detach(threads))
        perror("");
    usleep(100);
}
