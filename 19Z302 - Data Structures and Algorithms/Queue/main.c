#include <stdio.h>
void enqueue();
void dequeue();
int arr[5];
int n = 5;
int rear = -1;
int front = -1;

void enqueue()
{
    int item;
    if ((front == 0 && rear == n - 1) || rear + 1 == front)
        printf("Overflow \n");
    else
    {
        if (front == -1)
            front = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &item);
        rear = rear + 1;
        arr[rear] = item;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow \n");
    }
    else
    {
        printf("%d\n", arr[front]);
        front = front + 1;
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    enqueue();
    dequeue();
    dequeue();
    dequeue();
}
