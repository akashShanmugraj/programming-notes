#include <stdio.h>
#include <pthread.h>
#include <semaphore.h> 

int bufferobject[10];
int inpointer = 0;
int outpointer = 0;

sem_t isemptysemaphore;
sem_t isfullsemaphore;
pthread_mutex_t mutexthread;

void * producer(void * arg) {
    int i;
    for (i = 0; i < 20; i++) {
        sem_wait(&isemptysemaphore);
        pthread_mutex_lock(&mutexthread);

        bufferobject[inpointer] = i;
        printf("Producer produced %d\n", i);
        inpointer = (inpointer + 1) % 10;

        pthread_mutex_unlock(&mutexthread);
        sem_post(&isfullsemaphore);
        
        sleep(1);
    }
}

void * consumer(void * arg){
    int item, i;
    for (i = 0; i < 20; i++) {
        sem_wait(&isfullsemaphore);
        pthread_mutex_lock(&mutexthread);
        
        item = bufferobject[outpointer];
        printf("Consumer consumed: %d\n", item);
        outpointer = (outpointer + 1) % 10;

        pthread_mutex_unlock(&mutexthread);
        sem_post(&isemptysemaphore);

        sleep(1);
    }
}

int main() {
    pthread_t producerthread, consumerthread;

    sem_init(&isemptysemaphore, 0, 10);
    sem_init(&isfullsemaphore,0,0);
    pthread_mutex_init(&mutexthread, NULL);


    pthread_create(&producerthread, NULL, producer, NULL);
    pthread_create(&consumerthread, NULL, consumer, NULL);

    pthread_join(producerthread, NULL);
    pthread_join(consumerthread, NULL);

    sem_destroy(&isemptysemaphore);
    sem_destroy(&isfullsemaphore);
    pthread_mutex_destroy(&mutexthread);

    return 0;
}