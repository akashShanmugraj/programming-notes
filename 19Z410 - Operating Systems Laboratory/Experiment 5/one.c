#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MIN_PID 300
#define MAX_PID 5000
#define NUM_THREADS 10

int *pid_map;
pthread_mutex_t mutex;

int allocate_map() {
    pid_map = (int *)malloc((MAX_PID - MIN_PID + 1) * sizeof(int));
    if (pid_map == NULL)
        return -1;

    for (int i = 0; i < MAX_PID - MIN_PID + 1; i++)
        pid_map[i] = 0;

    return 1;
}

int allocate_pid() {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < MAX_PID - MIN_PID + 1; i++) {
        if (pid_map[i] == 0) {
            pid_map[i] = 1;
            pthread_mutex_unlock(&mutex);
            return i + MIN_PID;
        }
    }
    pthread_mutex_unlock(&mutex);
    return -1;
}

void release_pid(int pid) {
    pthread_mutex_lock(&mutex);
    pid_map[pid - MIN_PID] = 0;
    pthread_mutex_unlock(&mutex);
}

void *thread_function(void *arg) {
    int pid = allocate_pid();
    if (pid == -1)
        printf("No PID available\n");
    else
        printf("Thread %ld got PID: %d\n", (long)arg, pid);
    release_pid(pid);
    pthread_exit(NULL);
}

int main() {
    if (allocate_map() == -1) {
        printf("Error: Unable to allocate PID map.\n");
        return -1;
    }

    pthread_mutex_init(&mutex, NULL);

    pthread_t threads[NUM_THREADS];
    for (long i = 0; i < NUM_THREADS; i++)
        pthread_create(&threads[i], NULL, thread_function, (void *)i);

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    free(pid_map);
    pthread_mutex_destroy(&mutex);
    return 0;
}
