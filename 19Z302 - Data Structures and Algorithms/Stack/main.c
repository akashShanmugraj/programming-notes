#include<stdio.h>

int push(int * arraypointer, int stacksize, int data, int top){
    if (top+1 == stacksize){
        return -1;
    } else {
        top++;
        arraypointer[top] = data;
        return top;
    }
}

int pop(int * arraypointer, int arraylength, int* top){
    if (*(top) == -1){
        return -1; 
    } else {
        arraypointer[*(top)] = 0;
        return --*(top);
    }
}

void display(int * arraypointer, int arraylength){
    for (int i = 0; i < arraylength; i++){
        printf("%d ", arraypointer[i]);
    }
}


int main(){
    int numberarray[10]= {10,20,30,40};
    int maxsize = 10;
    int pointer = 3;
    int data = 50;
    int result = push(numberarray, maxsize, data, pointer);
    printf("Push result: %d\n", result);
    display(numberarray, maxsize);

    int popresult = pop(numberarray, maxsize, &result);
    printf("\nPop result: %d\n", popresult);
    display(numberarray, maxsize);
}