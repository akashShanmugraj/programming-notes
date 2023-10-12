// code to convert infix expression to postfix expressino
// currently no dev support for parantheses

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void display(int *numberarray, int length)
{
    for (int iterable = 0; iterable < length; iterable++)
    {
        printf("%d ", *(numberarray + iterable));
    }
}

int pushelement(int *numberarray, int maxlength, int toppointer, int data)
{
    if (toppointer + 1 == maxlength)
    {
        printf("Stack Overflow\n");
        return -1;
    }
    else
    {
        toppointer++;
        *(numberarray + toppointer) = data;
        return toppointer;
    }
}

int popelement(int *numberarray, int toppointer)
{
    if (toppointer + 1 == 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        *(numberarray + toppointer) = 0;
        return --toppointer;
    }
}

void parseinfix(char *infix, int length)
{
    int integerconstructor = 0;
    int integercontainter = 0;
    int operationcounter = 0; // stack array must roughly contain operationcounter * 2 size

    for (int iterable = 0; iterable < length; iterable++)
    {
        if (*(infix + iterable) == '+' || *(infix + iterable) == '-' || *(infix + iterable) == '*' || *(infix + iterable) == '/')
        {
            operationcounter++;
            printf("BIN-OP: %c\n", *(infix + iterable));
            printf("INT-INT: %d\n\n", integercontainter);
            integerconstructor = 0;
            integercontainter = 0;
        }
        else if ((*(infix + iterable) == '(' || *(infix + iterable) == ')'))
        {
            printf("PARAN: %c\n", *(infix + iterable));
            printf("INT-INT: %d\n\n", integercontainter);
            integerconstructor = 0;
            integercontainter = 0;
        }
        else
        {
            printf("CHAR-INT: %c\n", *(infix + iterable));
            integercontainter = integercontainter * pow(10, integerconstructor) + (*(infix + iterable) - 48);
            integerconstructor++;
        }
    }
    printf("INT-INT: %d\n", integercontainter);
}

void main()
{
    char *infix = "2+1*3-5/2";

    parseinfix(infix, strlen(infix));
}

void arrayreference()
{
    int arrayobject[10] = {1, 2, 3, 4};
    int toppointer = 3;

    display(arrayobject, 10);
    printf("\n");

    toppointer = pushelement(arrayobject, 10, toppointer, 5);
    display(arrayobject, 10);
    printf("\n");

    toppointer = popelement(arrayobject, toppointer);
    display(arrayobject, 10);
    printf("\n");
}