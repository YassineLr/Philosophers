#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

/*
    create a programm where a thread filling a table and another thread 
    update values and another one to display the content of the table
*/
// pthread_mutex_t lock;

void    *filling(void *args){
    int *arg_array = (int *)args;
    
    for (size_t i = 0; i < 5; i++){
        arg_array[i] = i;
    }
    return(NULL);
}

void    *updating(void *args){
    int *tab;

    tab = (int *)args;
    for (size_t i = 0; i < 5; i++){
        tab[i] +=2;
    }
}

void    *display(void *args){
    int *arg_array = (int *)args;
    
    for (size_t i = 0; i < 5; i++){
        printf("tab[%ld] = %d\n",i , arg_array[i]);
    }
    return(NULL);
}

int main(int ac, char **av)
{
    pthread_t   threads[3];
    int         tab[5];

    pthread_create(&threads[0], NULL, filling, tab);
    pthread_join(threads[0], NULL);
    pthread_create(&threads[1], NULL, display, tab);
    pthread_join(threads[1],NULL);
    pthread_create(&threads[2], NULL, updating, tab);
    pthread_join(threads[2], NULL);
    pthread_create(&threads[1], NULL, display, tab);
    pthread_join(threads[1], NULL);
}
