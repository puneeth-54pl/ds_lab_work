// Program to convert an infix expression to prefix expression using stack
#include <stdio.h>
#include <string.h>
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

// Function to reverse a string
void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

int main() {
    char exp[MAX], prefix[MAX];
    int i, j = 0;
    printf("Enter infix expression: ");
    scanf("%s", exp);
    reverse(exp); // Reverse the infix expression
    for (i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (isalnum(c)) {
            prefix[j++] = c;
        } else if (c == ')') {
            push(c);
        } else if (c == '(') {
            while (top != -1 && stack[top] != ')')
                prefix[j++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) > precedence(c))
                prefix[j++] = pop();
            push(c);
        }
    }
    while (top != -1)
        prefix[j++] = pop();
    prefix[j] = '\0';
    reverse(prefix); // Reverse to get the correct prefix
    printf("Prefix expression: %s\n", prefix);
    return 0;
} 