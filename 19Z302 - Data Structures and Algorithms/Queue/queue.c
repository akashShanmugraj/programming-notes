#include<stdio.h>
#include<stdlib.h>

void enqueue(int * queueobject, int queuesize, int * rearpointer, int data){
    int targetrearpointer = (*(rearpointer) + 1)%queuesize;
    if (*(queueobject+ *(rearpointer)) != 0){

        printf("QUEUE FULL, CANNOT INS, REF %d-%d\n", *(rearpointer), targetrearpointer);
    } else {
        *(queueobject + *(rearpointer)) = data;
        *(rearpointer) = targetrearpointer;
    }
}

void dequeue(int * queueobject, int queuesize, int * frontpointer){
    if (*(queueobject + *frontpointer) == 0){
        printf("EMPTY Q NO DEQUEUE\n");
    } else {
        printf("DEQUEUE RESULT %d\n", *(queueobject + *(frontpointer)));
        *(queueobject + *(frontpointer)) = 0;
        *(frontpointer) = (*(frontpointer) + 1) % queuesize;
    }
}

void printqueue(int * queueobject, int queuesize){
    printf("Queue's contents: \n");
    for (int iterable = 0; iterable < queuesize; iterable++){
        printf("%d ", *(queueobject + iterable));
    }
    printf("\n\n");
}

int main(){
    int array[10] = {0};
    int * arraypointer = array;

    int front = 0;
    int rear = 0;


    enqueue(arraypointer, 10, &rear, 1);
    enqueue(arraypointer, 10, &rear, 2);
    enqueue(arraypointer, 10, &rear, 3);
    enqueue(arraypointer, 10, &rear, 4);
    enqueue(arraypointer, 10, &rear, 1);
    enqueue(arraypointer, 10, &rear, 2);
    enqueue(arraypointer, 10, &rear, 3);
    enqueue(arraypointer, 10, &rear, 4);
    enqueue(arraypointer, 10, &rear, 1);
    enqueue(arraypointer, 10, &rear, 2);

    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    enqueue(arraypointer, 10, &rear, 3);
     
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);
    
    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);
    
    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);
    
    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);
    
    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10);

}
