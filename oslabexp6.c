#include<stdio.h>
#include<unistd.h>
sem_t mutex;
int y=10;
void* th(void* arg);
{
    sem_wait(&mutex0);
    printf("\nEntered into critical section\n");
    y=y+1;
    sleep(10);
    printf("The value of Y is %d\n",y);
    printf("\nExit from critical section\n");
    sem_post(&mutex);
}
int main()
{
    sem_init(&mutex,0,1);
    pthread_t t1,t2;
    pthread_create(&t1, NULL, th,NULL);
    sleep(3);
    pthread_create(&t2, NULL,th , NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}