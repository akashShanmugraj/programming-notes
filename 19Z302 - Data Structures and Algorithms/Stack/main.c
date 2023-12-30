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
    char* postfix = malloc(length + 1); // +1 for the null terminator
    int i, k;

    for (i = 0, k = -1; i < length; ++i) {
        if (isOperand(infix[i])) {
            postfix[++k] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[++k] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                return; // Invalid expression
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack))) {
                postfix[++k] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[++k] = pop(stack);
    }

    postfix[++k] = '\0';
    printf("Postfix expression: %s\n", postfix);
    free(postfix);
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
