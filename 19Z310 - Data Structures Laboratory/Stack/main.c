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


void parseinfix(char *infixstatement, char ** tokensobject){
    char *token = strtok(infixstatement, " ");
    // create tokens array to store tokens
    int i = 0;
    while (token != NULL){
        *(tokensobject+i) = token;
        token = strtok(NULL, " ");
        i++;
    }
}

void main()
{
    char infix[] = "21 + 13 * 2 - 4 / 2";
    // create a stack
    struct charstack *stack = (struct charstack *)malloc(sizeof(struct charstack));
    printf("Infix statement: %s\n", infix);
    char **infixarray = (char **)malloc(100 * sizeof(char *));
    parseinfix(infix, infixarray);

    // print tokensobject
    for (int i = 0; i < 100; i++){
        if (strcmp(*(infixarray+i), "") == 0){
            printf("NO E\n");
        }
        printf("E: %s\n", *(infixarray+i));
    }
}
