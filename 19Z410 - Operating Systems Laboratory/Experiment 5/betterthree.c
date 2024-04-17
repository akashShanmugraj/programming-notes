#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
    pthread_mutex_t mutex;
} Stack;

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (!newNode)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Stack *stack, int data)
{
    pthread_mutex_lock(&stack->mutex);
    Node *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    pthread_mutex_unlock(&stack->mutex);
}

int pop(Stack *stack)
{
    pthread_mutex_lock(&stack->mutex);
    if (!stack->top)
    {
        printf("Stack is empty\n");
        pthread_mutex_unlock(&stack->mutex);
        return -1;
    }
    Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    pthread_mutex_unlock(&stack->mutex);
    return data;
}

void printStack_recursive(Node *current)
{
    if (!current)
    {
        return;
    }
    printStack_recursive(current->next);
    printf("| %d ", current->data);
}

void printStack(Stack *stack)
{
    printf("Stack contents ");
    printStack_recursive(stack->top);
    printf("\n");
}

int main()
{
    Stack stack = {.top = NULL, .mutex = PTHREAD_MUTEX_INITIALIZER};
    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);
    printStack(&stack);
    printf("Popped value: %d\n", pop(&stack));
    printStack(&stack);
    printf("Popped value: %d\n", pop(&stack));
    printStack(&stack);
    printf("Popped value: %d\n", pop(&stack));
    printStack(&stack);
    printf("Popped value: %d\n", pop(&stack));
    printStack(&stack);
    pthread_mutex_destroy(&stack.mutex);
    return 0;
}