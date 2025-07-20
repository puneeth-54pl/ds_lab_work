// Program to evaluate a postfix expression with multiple digit numbers using stack
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
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
    int n, i, num;
    char op[5];
    printf("Enter number of tokens in postfix expression: ");
    scanf("%d", &n);
    printf("Enter the tokens (numbers or operators) one by one, separated by space or enter:\n");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &num) == 1) {
            // If input is a number, push to stack
            push(num);
        } else {
            // If not a number, must be an operator
            scanf("%s", op);
            int b = pop();
            int a = pop();
            switch (op[0]) {
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
