// Program to evaluate a postfix expression using stack
#include <stdio.h>
#include <ctype.h>
#define MAX 100

int stack[MAX]; // Stack for operands
int top = -1;

// Function to push an element onto the stack
void push(int n) {
    stack[++top] = n;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

int main() {
    char exp[MAX];
    int i;
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    for (i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (isdigit(c)) {
            // If operand, push to stack
            push(c - '0');
        } else {
            // Operator: pop two operands and apply operator
            int b = pop();
            int a = pop();
            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    printf("Result: %d\n", pop());
    return 0;
}
