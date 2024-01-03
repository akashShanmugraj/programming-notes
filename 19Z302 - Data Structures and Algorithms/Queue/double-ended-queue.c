#include<stdio.h>
#include<stdlib.h>

void enqueue(int * queueobject, int queuesize, int * rearpointer, int data){
    int targetrearpointer = (*(rearpointer) + 1)%queuesize;
    if (*(queueobject + targetrearpointer) != 0){
        printf("QUEUE FULL, CANNOT INS, REF %d-%d\n", *(rearpointer), targetrearpointer);
    } else {
        *(queueobject + targetrearpointer) = data;
        *(rearpointer) = targetrearpointer;
    }
}

void enqueuefront(int * queueobject, int queuesize, int * frontpointer, int data) {
    int targetfrontpointer = (*(frontpointer) - 1 + queuesize) % queuesize;
    if (*(queueobject + targetfrontpointer) != 0) {
        printf("QUEUE FULL, CANNOT INS, REF %d-%d\n", *(frontpointer), targetfrontpointer);
    } else {
        *(queueobject + targetfrontpointer) = data;
        *(frontpointer) = targetfrontpointer;
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

void dequeueback(int * queueobject, int queuesize, int * rearpointer){
    int targetrearpointer = (*rearpointer - 1 + queuesize) % queuesize;
    if (*(queueobject + targetrearpointer) == 0){
        printf("EMPTY Q NO DEQUEUE\n");
    } else {
        printf("DEQUEUE BCK RESULT %d\n", *(queueobject + targetrearpointer));
        *(queueobject + targetrearpointer) = 0;
        *(rearpointer) = targetrearpointer;
    }
}

void printqueuecircle(int * queueobject, int queuesize, int frontpointer, int rearpointer){
    int radius = queuesize / 2;
    for(int i = -radius; i <= radius; i++){
        for(int j = -radius; j <= radius; j++){
            if(i*i + j*j <= radius*radius){
                int index = (j + radius + frontpointer) % queuesize;
                if(index == frontpointer && index == rearpointer){
                    printf("F%dR ", *(queueobject + index));
                } else if(index == frontpointer){
                    printf("F%d  ", *(queueobject + index));
                } else if(index == rearpointer){
                    printf(" %dR ", *(queueobject + index));
                } else {
                    printf(" %d  ", *(queueobject + index));
                }
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
}

void printqueue(int * queueobject, int queuesize, int frontpointer, int rearpointer){
    printf("Queue's contents: \n");
    for (int i = 0; i < queuesize; i++){
        if (i == frontpointer){
            printf("F->");
        }
        if (i == rearpointer){
            printf("R->");
        }
        printf("%d ", *(queueobject + i));
    }
    printf("\n\n");
    printf("Note: The queue wraps around from the end back to the start.\n");
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

    printqueue(arraypointer, 10, front, rear);

    dequeue(arraypointer, 10, &front);
    
    printqueue(arraypointer, 10, front, rear);

    enqueue(arraypointer, 10, &rear, 3);
     
    printqueue(arraypointer, 10, front, rear);

    dequeueback(arraypointer, 10, &rear);

    printqueue(arraypointer, 10, front, rear);

    enqueuefront(arraypointer, 10, &front, 5);

    printqueue(arraypointer, 10, front, rear);

}
