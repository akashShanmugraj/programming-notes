#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SEQUENCE 25

int fib_sequence[MAX_SEQUENCE];
int fib_count = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;
int done = 0;

void *calculate_fibonacci(void *arg)
{
    int n = *((int *)arg);

    int a = 0, b = 1;
    fib_sequence[0] = a;
    fib_sequence[1] = b;

    for (int i = 2; i <= n; i++)
    {
        int next = a + b;
        a = b;
        b = next;
        pthread_mutex_lock(&mutex);
        fib_sequence[i] = next;
        fib_count++;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_lock(&mutex);
    done = 1;
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main()
{
    int n;
    printf("Enter the number of Fibonacci numbers to generate (up to %d): ", MAX_SEQUENCE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SEQUENCE)
    {
        printf("Invalid input.\n");
        return 1;
    }

    pthread_t tid;
    int fib_arg = n;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&tid, NULL, calculate_fibonacci, (void *)&fib_arg);

    pthread_mutex_lock(&mutex);
    while (!done)
    {
        pthread_cond_wait(&cond, &mutex);
        for (int i = 0; i <= fib_count; i++)
        {
            printf("%d ", fib_sequence[i]);
        }
        printf("\n");
    }
    pthread_mutex_unlock(&mutex);

    pthread_join(tid, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
