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