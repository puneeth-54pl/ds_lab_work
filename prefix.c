// Program to evaluate a prefix expression using stack
#include <stdio.h>
#include <string.h>
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
    int i, n;
    printf("Enter prefix expression: ");
    scanf("%s", exp);
    n = strlen(exp);
    // Scan from right to left
    for (i = n - 1; i >= 0; i--) {
        char c = exp[i];
        if (isdigit(c)) {
            push(c - '0');
        } else {
            int a = pop();
            int b = pop();
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
