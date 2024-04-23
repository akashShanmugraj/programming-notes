## Program 1 - Modified PID Manager with Threads and Mutex Locks

```c
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
```

## Program 2 - Parent-Child Thread Communication for Fibonacci Sequence

```c

#define MAX 1000

int fib[MAX];
int count = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

void *fibonacci(void *param) {
    int a = 0, b = 1, temp;
    pthread_mutex_lock(&mutex);
    while (count < MAX) {
        temp = a + b;
        a = b;
        b = temp;
        fib[count++] = temp;
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond, &mutex);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

int main() {
    pthread_t tid;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_create(&tid, NULL, fibonacci, NULL);
    while (count < MAX) {
        pthread_mutex_lock(&mutex);
        while (count == 0)
            pthread_cond_wait(&cond, &mutex);
        printf("%d\n", fib[count - 1]);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    pthread_join(tid, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}
```

## Program 3 - Fixing Race Condition in stack-ptr.c using Mutex Locks

```c
#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;
pthread_mutex_t mutex;
void push(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    pthread_mutex_lock(&mutex);
    newNode->next = top;
    top = newNode;
    pthread_mutex_unlock(&mutex);
}
int pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    pthread_mutex_lock(&mutex);
    Node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    pthread_mutex_unlock(&mutex);
    return value;
}
void *thread_function(void *arg)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        push(i);
        printf("Pushed: %d\n", i);
    }
    for (i = 0; i < 5; i++)
    {
        int value = pop();
        printf("Popped: %d\n", value);
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t tid;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&tid, NULL, thread_function, NULL);
    pthread_join(tid, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
```