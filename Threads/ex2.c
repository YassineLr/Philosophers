#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
/*
    create a thread that calcule the sum of a table 
*/

void    *thread(void *tab)
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
    pthread_create(&threads, NULL, thread, tab);
    // The pthread_join() function waits for the thread specified by thread to terminate.
    pthread_join(threads, NULL);
}
