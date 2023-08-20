#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

void *task(void *thread_id)
{
    int id;

    id = *((int *)thread_id);
    printf("Hello from thread number : %d\n", id);
    return(NULL);
}
int main(int ac, char **av)
{
    pthread_t   threads[atoi(av[1])];
    int         i;

    i = 0;
    while (i < atoi(av[1]))
    {
        pthread_create(&threads[i], NULL, task, &i);
        sleep(2);
        i++;
    }
}
