#include<stdio.h>
#include<stdlib.h>

void display(int * queueobject, int size, int* frontpointer,int* rearpointer){
    printf("DIS F:%d R:%d\n", *(frontpointer), *(rearpointer));   
    for (int iterable = *(frontpointer); iterable<=*(rearpointer); iterable++){
        printf("VAL:%d POS:%d\n", *(queueobject+iterable), iterable);
    }
    printf("\n");
}

void enqueue(int * queueobject, int size,int data, int * frontpointer, int* rearpointer){
    printf("ENQ F:%d R:%d\n", *(frontpointer), *(rearpointer));   
    if ((*(frontpointer) == 0 && *(rearpointer) == size-1) || *(frontpointer) == *(rearpointer)+1){
        printf("overflow");
    } else {
        *(rearpointer) = *(rearpointer) + 1;
        *(queueobject+*(rearpointer)) = data;
    }
}

int main(){
    int queuearray[10] = {0,0,0,30,29,47,58,69,0,0};
    int * queuepointer = queuearray;
    int front = -1, rear = -1;
    front = 3;
    rear = 7;
    display(queuepointer, 10, &front, &rear);
    enqueue(queuepointer, 10, 100, &front, &rear);
    display(queuepointer, 10, &front, &rear);

}