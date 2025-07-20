// Program to convert a prefix expression to postfix expression using stack
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX][MAX]; // Stack for strings
int top = -1;

// Function to push a string onto the stack
void push(char *str) {
    strcpy(stack[++top], str);
}

// Function to pop a string from the stack
void pop(char *str) {
    if (top == -1) return;
    strcpy(str, stack[top--]);
}

int main() {
    char prefix[MAX], ch, op1[MAX], op2[MAX], temp[MAX];
    int i, n;
    printf("Enter prefix expression: ");
    scanf("%s", prefix);
    n = strlen(prefix);
    // Scan from right to left
    for (i = n - 1; i >= 0; i--) {
        ch = prefix[i];
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
            temp[0] = ch;
            temp[1] = '\0';
            push(temp);
        } else {
            pop(op1);
            pop(op2);
            sprintf(temp, "%s%s%c", op1, op2, ch);
            push(temp);
        }
    }
    printf("Postfix expression: %s\n", stack[top]);
    return 0;
}
