#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void display(int * numberarray, int length){
    for (int iterable = 0; iterable < length; iterable++){
        printf("%d ", *(numberarray+iterable));
    }
}

int pushelement(int * numberarray, int maxlength, int toppointer, int data){
    if (toppointer + 1 == maxlength){
        printf("Stack Overflow\n");
        return -1;
    } else {
        toppointer++;
        *(numberarray+toppointer) = data;
        return toppointer;
    }
}

int popelement(int * numberarray, int toppointer){
    if (toppointer + 1 == 0){
        printf("Stack Underflow\n");
        return -1;
    } else {
        *(numberarray+toppointer) = 0;
        return --toppointer;
    }
}

int calluntilint(char * expression, int length, int pointer){
    printf("CURR: %c\n", *(expression+pointer));
    while (*(expression+pointer) > 47 && *(expression+pointer) < 58){
        printf("IDENT INT: %c\n", *(expression+pointer));
        pointer++;
    }

    return pointer;
}

void parseinfix(char * infix, int length){
    int integerconstructor = 0;
    int integercontainter = 0;

    for (int iterable = 0; iterable < length; iterable++){
        if (*(infix+iterable) == '+' || *(infix+iterable) == '-' || *(infix+iterable) == '*' || *(infix+iterable) == '/') {
            printf("BIN-OP: %c\n", *(infix+iterable));
            printf("INT-INT: %d\n\n", integercontainter);
            integerconstructor = 0;
            integercontainter = 0;
        } else if ((*(infix+iterable) == '(' || *(infix+iterable) == ')')){
            printf("PARAN: %c\n", *(infix+iterable));
            printf("INT-INT: %d\n\n", integercontainter);
            integerconstructor = 0;
            integercontainter = 0;
        } else {
            printf("CHAR-INT: %c\n", *(infix+iterable));
            integercontainter = integercontainter*pow(10, integerconstructor) + (*(infix+iterable) - 48);
            integerconstructor++;
        }
        

        // printf("%c\n", *())
    }
    printf("INT-INT: %d\n", integercontainter);

}

void main(){
    // int arrayobject[10] = {1,2,3,4};
    // int toppointer = 3;

    // display(arrayobject, 10);
    // printf("\n");

    // toppointer = pushelement(arrayobject, 10, toppointer, 5);
    // display(arrayobject, 10);
    // printf("\n");

    // toppointer = popelement(arrayobject, toppointer);
    // display(arrayobject, 10);
    // printf("\n");

    char * infix = "12+13*3-5/2";

    

    parseinfix(infix, strlen(infix));
    
}