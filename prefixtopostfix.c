#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure using a pointer
struct Stack {
    char stack[MAX];
    int *top;  // Pointer to the top of the stack
};

// Function to initialize the stack
void initStack(struct Stack *s) {
    s->top = s->stack - 1; // Set top pointer to -1 position (before the first element)
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return (s->top == s->stack - 1);
}

// Function to push an element onto the stack
void push(struct Stack *s, char c) {
    if (s->top - s->stack >= MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    *(++s->top) = c;  // Increment the pointer and then assign the value
}

// Function to pop an element from the stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return *(s->top--);  // Return the value and decrement the pointer
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert prefix expression to postfix expression
void prefixToPostfix(char *prefix) {
    int length = strlen(prefix);
    struct Stack s;
    initStack(&s);  // Initialize the stack

    char postfix[MAX];
    int j = 0;

    // Traverse the prefix expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        char c = prefix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If the character is an operator, pop two operands from the stack
        else if (isOperator(c)) {
            char operand1 = pop(&s);
            char operand2 = pop(&s);
            postfix[j++] = operand1;
            postfix[j++] = operand2;
            postfix[j++] = c;
        }
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';

    // Print the postfix expression
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char prefix[MAX];

    // Input the prefix expression
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    // Convert the prefix expression to postfix
    prefixToPostfix(prefix);

    return 0;
}
