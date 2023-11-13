#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;

void push(char element) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = element;
}

char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top < 0) {
        return '\0';
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int getPrecedence(char operator) {
    switch(operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0; // Assuming other characters are operands
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int i, j;
    char token, popped;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token; // If it's an operand, add it directly to postfix
        } else if (token == '(') {
            push(token);
        } else if (token == ')') {
            while ((popped = pop()) != '(') {
                postfix[j++] = popped;
            }
        } else { // If it's an operator
            while (!isEmpty() && getPrecedence(token) <= getPrecedence(peek())) {
                postfix[j++] = pop();
            }
            push(token);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Add null character to indicate end of string
}

int main() {
    char infix[MAX_SIZE] = "a+b*c-(d/e+f*g*h)";
    char postfix[MAX_SIZE];

    infixToPostfix(infix, postfix);

    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);

    return 0;
}
