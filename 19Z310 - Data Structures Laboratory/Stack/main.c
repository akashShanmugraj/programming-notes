// code to convert infix expression to postfix expressino
// currently no dev support for parantheses

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// define a char stack
struct charstack
{
    int top;
    unsigned capacity;
    char *array;
};

void parseinfix(char *infixstatement){
    // split the infix statement into tokens
    char *token = strtok(infixstatement, " ");
    while (token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
}

void main()
{
    char infix[] = "2 + 1 * 2 - 4 / 2";
    printf("Infix statement: %s\n", infix);
    parseinfix(infix);
}
