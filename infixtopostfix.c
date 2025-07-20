// Program to convert an infix expression to postfix expression using stack
#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX]; // Stack for operators
int top = -1;

// Function to push an element onto the stack
void push(char c) {
    stack[++top] = c;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Function to return precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int main() {
    char exp[MAX], postfix[MAX];
    int i, j = 0;
    printf("Enter infix expression: ");
    scanf("%s", exp);
    for (i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (isalnum(c)) {
            // If operand, add to postfix
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            // Pop until '(' is found
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); // Remove '(' from stack
        } else {
            // Operator: pop higher or equal precedence
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    // Pop remaining operators
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
