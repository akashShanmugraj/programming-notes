#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack
struct Stack {
    int top; // index of the top element
    unsigned capacity; // stack size
    char* array; // the actual stack
};

// allocate memory for a stack of given capacity and initialize it
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}
 
// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // '$' denotes an empty stack
}

// Function to return the top element of the stack without popping
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); // checks if the a character is Operand / Alphabet
}

// Function to return the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void printcharstar(char* charstar) {
    int i;
    printf("CHARSTAR: ");
    for (i = 0; i < strlen(charstar); i++) {
        printf("%c", charstar[i]);
    }
    printf("\n");
}

void printstack(struct Stack* stack) {
    int i;
    printf("STACK: ");
    for (i = 0; i <= stack->top; i++) {
        printf("%c", stack->array[i]);
    }
    printf("\n");
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix) {
    int length = strlen(infix);
    struct Stack* stack = createStack(length);
    int i, k;

    for (i = 0, k = -1; i < length; ++i) {
        printf("i = %d, k = %d\n", i, k);
        printf("CHAR AT I = %c\n", infix[i]);
        printf("CHAR AT K = %c\n", infix[k]);

        // If the scanned character is an operand, add it to the output
        if (isOperand(infix[i])){
            printf("isOperand\n");
            infix[++k] = infix[i];
            printcharstar(infix);
            printf("i = %d k = %d", i, k);
        }
        // If the scanned character is an '(', push it onto the stack
        else if (infix[i] == '('){
            printf("is (\n");
            push(stack, infix[i]);
        }
        // If the scanned character is an ')', pop and output from the stack until an '(' is encountered
        else if (infix[i] == ')') {
            printf("is )\n");
            while (!isEmpty(stack) && peek(stack) != '('){
                printf("Stack is not empty and peek (%c) is not (\n", peek(stack));
                printf("Popping %c and adding it into infix", peek(stack));
                infix[++k] = pop(stack);
                printcharstar(infix);
                printstack(stack);
                printf("i = %d k = %d", i, k);

                }
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else{
                printf("not empty and peek is (\n");
                pop(stack);
                printstack(stack);
            }
        }
        // If an operator is encountered
        else {
            printf("is operator\n");
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))){
                printf("Stack is not empty and precedence of %c is less than or equal to precedence of %c\n", infix[i], peek(stack));
                infix[++k] = pop(stack);
                printf("i = %d k = %d", i, k);
                printcharstar(infix);
                printstack(stack);
            }
            printf("Pushing %c into stack\n", infix[i]);
            push(stack, infix[i]);
            printstack(stack);
        }
    }

    // Pop all the operators from the stack
    while (!isEmpty(stack))
        infix[++k] = pop(stack);
        printf("i = %d k = %d", i, k);
        printcharstar(infix);
        printstack(stack);

    // Null-terminate the postfix expression
    infix[++k] = '\0';

    // Print the postfix expression
    printf("Postfix expression: %s\n", infix);
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int i, operand1, operand2;

    for (i = 0; postfix[i] != '\0'; ++i) {
        // If the scanned character is an operand, push it onto the stack
        if (isOperand(postfix[i]))
            push(stack, postfix[i] - '0');
        // If the scanned character is an operator, pop two operands from the stack and perform the operation
        else {
            operand2 = pop(stack);
            operand1 = pop(stack);
            switch (postfix[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }

    printf("Result: %d\n", peek(stack));
    // The final result will be at the top of the stack
    return pop(stack);
}

// Main function
int main() {
    char infix[100];
    
    // Get the infix expression from the user
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix);

    return 0;
}
